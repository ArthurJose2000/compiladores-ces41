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

static char intstr[20];
/* prototype for internal recursive code generator */
static void cGen (TreeNode * tree);

/*Generate labels for temporary variables*/
char * gen_temp_var_name(char* name, int x){
  char* tmp_name;
  char intstr[20];
  int len = strlen(name)+10;
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
         /* generate code for test expression */
         //cGen(p1);
         /* recurse on then part */
         //cGen(p2);
         /* recurse on else part */
         //cGen(p3);
         break; /* if_k */

      case RepeatK:
         p1 = tree->child[0] ;
         p2 = tree->child[1] ;
         /* generate code for body */
         //cGen(p1);
         /* generate code for test */
         //cGen(p2);
         break; /* repeat */

      case AssignK:
      /*
         p1 = tree->child[0];
         char tmp_name[20] = "default tmp_name";
         strcpy(tmp_name, cGen(tree->child[0]));
         printf("%s = %s\n", tree->attr.name, tmp_name);*/
         break; /* assign_k */

      case ReturnK:
         cGen(tree->child[0]);
         printf("return ");
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
         p1 = tree->child[0];
         p2 = tree->child[1];

         char* tmp_name = "temp_name";
         tmp_name = gen_temp_var_name("t", tmp_counter++);
         printf("%s = ", tmp_name);
         cGen(p1);
         
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
         cGen(p2);
         printf("\n");
         break; /* OpK */
    default:
      break;
  }
} /* genExp */

/*Definicao de sub-rotinas*/
static void genDefDecl(TreeNode * tree){
   TreeNode * p1;
   switch (tree->kind.decl) {
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
static void genAtivDecl(TreeNode * tree){
   TreeNode * p1;
   int count = 0;
   p1 = tree->child[0];

   while(p1 != NULL){
      printf("param ");
      cGen(p1);
      printf(" \n");
      count++;
      p1 = p1->sibling;
   }
   printf("call %s, %d\n", tree->attr.name, count);

   char call_line[20]= "call ";
   sprintf(intstr, "%d", count); 
   strcat(call_line, tree->attr.name);
   strcat(call_line, ", ");
   strcat(call_line, intstr);
   printf("%s\n", call_line);
   //return call_line;
}


/*Acesso indexado*/
static void idx_access(TreeNode * tree){
   
}

/* Procedure cGen recursively generates code by
 * tree traversal
 */
static void cGen( TreeNode * tree)
{  //printf("entrou em cGen\n");
   if (tree != NULL) 
   { switch (tree->nodekind) {
      case StmtK:
         genStmt(tree);
         break;
      case ExpK:
         genExp(tree);
         break;
      case DeclK:
         genDefDecl(tree);
         break;
      case AtvK:
         genAtivDecl(tree);
         break;
      case TypeK:
         cGen(tree->child[0]);
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
