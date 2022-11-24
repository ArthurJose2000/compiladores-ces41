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

static char intstr[10];
/* prototype for internal recursive code generator */
static char * cGen (TreeNode * tree);

/*Generate labels for temporary variables*/
char * gen_temp_var_name(char* name, int x){
  char* tmp_name;
  char intstr[10];
  int len = strlen(name)+10;
  tmp_name = malloc(len);
  strcpy(tmp_name, name);
  sprintf(intstr, "%d", x); 
  strcat(tmp_name, intstr);
  return tmp_name;
}

/* Procedure genStmt generates code at a statement node */
static char* genStmt( TreeNode * tree)
{ TreeNode * p1, * p2, * p3;
  int savedLoc1,savedLoc2,currentLoc;
  int loc;
  switch (tree->kind.stmt) {

      case IfK :
         p1 = tree->child[0] ;
         p2 = tree->child[1] ;
         p3 = tree->child[2] ;
         /* generate code for test expression */
         cGen(p1);
         /* recurse on then part */
         cGen(p2);
         /* recurse on else part */
         cGen(p3);
         break; /* if_k */

      case RepeatK:
         p1 = tree->child[0] ;
         p2 = tree->child[1] ;
         /* generate code for body */
         cGen(p1);
         /* generate code for test */
         cGen(p2);
         break; /* repeat */

      case AssignK:
         /* generate code for rhs */
         char* tmp_name = gen_temp_var_name("t", 1);
         //printf("%s = %s\n", tree->attr.name, tmp_name);
         cGen(tree->child[0]);
         /* now store value */
         break; /* assign_k */

      case ReturnK:
         char * valor = "return default";
         valor = cGen(tree->child[0]);
         printf("return %s\n", valor);
         return valor;
         break; /* return_k */
      default:
         break;
    }
} /* genStmt */

/* Procedure genExp generates code at an expression node */
static char * genExp( TreeNode * tree)
{ 
  TreeNode * p1, * p2;
  switch (tree->kind.exp) {

    case ConstK :
      sprintf(intstr, "%d", tree->attr.val);
      return intstr;
      break; /* ConstK */
    
    case IdK :
      return tree->attr.name;
      break; /* IdK */

    case OpK :
         p1 = tree->child[0];
         p2 = tree->child[1];
         
         char* tmp_name = "temp_name";
         tmp_name = gen_temp_var_name("t", tmp_counter++);
         
         char first_var[10] = "first_var";
         strcpy(first_var, cGen(p1)); 
         char second_var[10] = "second_var";
         strcpy(second_var ,cGen(p2));
         
         switch (tree->attr.op) {
            case PLUS :
               printf("%s = %s + %s\n", tmp_name, first_var, second_var);
               break;
            case MINUS :
               printf("%s = %s - %s\n", tmp_name, first_var, second_var);
               break;
            case TIMES :
               printf("%s = %s * %s\n", tmp_name, first_var, second_var);
               break;
            case OVER :
               printf("%s = %s / %s\n", tmp_name, first_var, second_var);
               break;
            case LT :
               printf("%s = %s < %s\n", tmp_name, first_var, second_var);
               break;
            case EQ :
               printf("%s = %s == %s\n", tmp_name, first_var, second_var);
               break;
            default:
               emitComment("BUG: Unknown operator");
               break;
         } /* case op */
         return tmp_name;
         break; /* OpK */
    default:
      break;
  }
} /* genExp */

/*Definicao de sub-rotinas*/
static char * genDefDecl(TreeNode * tree){
   TreeNode * p1, * p2;
   switch (tree->kind.decl) {
    case VarK :
      printf("entrou em Vark %s", tree->attr.name);
      break; /* VarK */
    
    case FunK :
      printf("%s:", tree->attr.name);
      p1 = tree->child[1];
      while(p1 != NULL){
         cGen(p1);
         p1 = p1->sibling;
      }
      
      break; /* FunK */
    default:
      break;
  }
}

/*Invocacao de sub-rotinas*/
static char * genAtivDecl(TreeNode * tree){
   TreeNode * p1;
   int count = 0;
   p1 = tree->child[0];

   while(p1 != NULL){
      char param_name[10];
      strcpy(param_name, cGen(p1));
      printf("param %s\n", param_name);
      count++;
      p1 = p1->sibling;
   }
   printf("call %s %d", tree->attr.name, count);
}


/*Acesso indexado*/
static void idx_access(TreeNode * tree){
   
}

/* Procedure cGen recursively generates code by
 * tree traversal
 */
static char * cGen( TreeNode * tree)
{  //printf("entrou em cGen\n");
   if (tree != NULL) 
   { switch (tree->nodekind) {
      case StmtK:
         return genStmt(tree);
         break;
      case ExpK:
         return genExp(tree);
         break;
      case DeclK:
         return genDefDecl(tree);
         break;
      case AtvK:
         return genAtivDecl(tree);
         break;
      case TypeK:
         return cGen(tree->child[0]);
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
