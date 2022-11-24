/****************************************************/
/* File: cgen.c                                     */
/* The code generator implementation                */
/* for the TINY compiler                            */
/* (generates code for the TM machine)              */
/* Compiler Construction: Principles and Practice   */
/* Kenneth C. Louden                                */
/****************************************************/

#include "globals.h"
#include "symtab.h"
#include "code.h"
#include "cgen.h"

/* tmpOffset is the memory offset for temps
   It is decremented each time a temp is
   stored, and incremeted when loaded again
*/
static int tmpOffset = 0;

/*Global counter for tmp_variables */
static int tmp_counter = 0;

static char intstr[30];
/* prototype for internal recursive code generator */
static void cGen (TreeNode * tree);

/*Generate labels for temporary variables*/
char * gen_temp_var_name(char* name, int x){
  char* tmp_name;
  char intstr[30];
  int len = strlen(name)+30;
  tmp_name = malloc(len);
  strcpy(tmp_name, name);
  sprintf(intstr, "%d", x); 
  strcat(tmp_name, intstr);
  return tmp_name;
}

/* Procedure genStmt generates code at a statement node */
static void genStmt( TreeNode * tree)
{ TreeNode * p1, * p2, * p3;
  switch (tree->kind.stmt) {

      case IfK :
         p1 = tree->child[0] ;
         p2 = tree->child[1] ;
         p3 = tree->child[2] ;
         break; /* if_k */

      case RepeatK:
         p1 = tree->child[0] ;
         p2 = tree->child[1] ;
         break; /* repeat */

      case AssignK:
         if (tree->child[0]->child[0] == NULL && tree->child[1]->child[0] == NULL) {
            printf("%s = %d\n", tree->child[0]->attr.name, tree->child[1]->attr.val);
         }
         else {
            char* tmp_name = gen_temp_var_name("t", tmp_counter);
            printf("%s = %s\n", tree->child[0]->attr.name, tmp_name);
            cGen(tree->child[1]);
         }
         break; /* assign_k */

      case ReturnK:
         char* tmp_name = "temp_name";
         cGen(tree->child[0]);
         tmp_name = gen_temp_var_name("t", tmp_counter);
         printf("return %s", tmp_name);
         break; /* return_k */
      default:
         break;
    }
} /* genStmt */

/* Procedure genExp generates code at an expression node */
static void genExp( TreeNode * tree)
{ 
  TreeNode * p1, * p2;
  switch (tree->kind.exp) {
    case ConstK :
      printf("%d", tree->attr.val);
      break; /* ConstK */
    
    case IdK :
      printf("%s", tree->attr.name);
      break; /* IdK */

    case OpK :

      // preparando ASSIGNK
      if (tree->nodekind == ExpK && tree->kind.exp == OpK && tree->attr.op && tree->attr.op == ASSIGN) {
         tree->nodekind = StmtK;
         tree->kind.stmt = AssignK;
         genStmt(tree);
         break;
      }
      char* tmp_name = "temp_name";
      p1 = tree->child[1];
      p2 = tree->child[0];

      if (tree->attr.op == ASSIGN) break;

      

      if(p2->kind.exp != OpK){
         if(tmp_counter != 0){
            tmp_name = gen_temp_var_name("t", tmp_counter);
            printf("%s = ", tmp_name);
         }
         genExp(p1);
         switch (tree->attr.op) {
         case PLUS :
            printf(" + ");
            break;
         case MINUS :
            printf(" - ");
            break;
         case TIMES :
            printf(" * ");
            break;
         case OVER :
            printf(" / ");
            break;
         case LT :
            printf(" < ");
            break;
         case EQ :
            printf(" == ");
            break;
         default:
            emitComment("BUG: Unknown operator");
            break;
         } /* case op */
         genExp(p2);
         printf("\n");
      }else{
         tmp_counter++;
         genExp(p2);
         tmp_counter--;
         tmp_name = gen_temp_var_name("t", tmp_counter);
         printf("%s = ", tmp_name);
         tmp_counter++;
         tmp_name = gen_temp_var_name("t", tmp_counter);
         printf("%s", tmp_name);
         switch (tree->attr.op) {
         case PLUS :
            printf(" + ");
            break;
         case MINUS :
            printf(" - ");
            break;
         case TIMES :
            printf(" * ");
            break;
         case OVER :
            printf(" / ");
            break;
         case LT :
            printf(" < ");
            break;
         case EQ :
            printf(" == ");
            break;
         default:
            emitComment("BUG: Unknown operator");
            break;
         } /* case op */
         genExp(p1);
         tmp_counter--;
         printf("\n");

      }

    default:
      break;
  }
} /* genExp */

/*Definicao de sub-rotinas*/
static void genDefDecl(TreeNode * tree){
   TreeNode * p1;
   switch (tree->kind.decl) {
    case VarK :
      break; /* VarK */
    
    case FunK :
      printf("%s:", tree->attr.name);
      p1 = tree->child[1];
      cGen(p1);
      printf("\n");
      break; /* FunK */
    default:
      break;
  }
}

/*Invocacao de sub-rotinas*/
static void genAtivDecl(TreeNode * tree){
   TreeNode * p1;
   int count = 0;
   p1 = tree->child[0];

   while(p1 != NULL){
      printf("param %s\n", p1->attr.name);
      count++;
      p1 = p1->sibling;
   }
   printf("call %s, %d\n", tree->attr.name, count);
}


/*Acesso indexado*/
static void idx_access(TreeNode * tree){
   
}

/* Procedure cGen recursively generates code by
 * tree traversal
 */
static void cGen( TreeNode * tree)
{  
   if (tree != NULL) 
   {  
      switch (tree->nodekind) {
      case StmtK:
         genStmt(tree);
         break;
      case ExpK:
         genExp(tree);
         break;
      case DeclK:
         genDefDecl(tree);
         break;
      case TypeK:
         cGen(tree->child[0]);
         break;
      case AtvK:
         genAtivDecl(tree);
         break;
      default:
        break;
   }
   cGen(tree->sibling);
  }
}



/**********************************************/
/* the primary function of the code generator */
/**********************************************/
/* Procedure codeGen generates code to a code
 * file by traversal of the syntax tree. The
 * second parameter (codefile) is the file name
 * of the code file, and is used to print the
 * file name as a comment in the code file
 */
void codeGen(TreeNode * syntaxTree, char * codefile)
{  char * s = malloc(strlen(codefile)+7);
   strcpy(s,"File: ");
   strcat(s,codefile);
   emitComment("TINY Compilation to TM Code");
   emitComment(s);
   /* generate code for TINY program */
   cGen(syntaxTree);
   /* finish */
   emitComment("End of execution.");
   emitRO("HALT",0,0,0,"");
}
