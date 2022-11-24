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

         break; /* return_k */
      default:
         break;
    }
} /* genStmt */

/* Procedure genExp generates code at an expression node */
static char * genExp( TreeNode * tree)
{  printf("chegou em genEXP\n");
   int loc;
  TreeNode * p1, * p2;
  switch (tree->kind.exp) {

    case ConstK :
      break; /* ConstK */
    
    case IdK :
      break; /* IdK */

    case OpK :
         printf("chegou em OpK\n");
         p1 = tree->child[0];
         p2 = tree->child[1];
         char* tmp_name = gen_temp_var_name("t", tmp_counter++);
         
         /* gen code for ac = left arg */
         char * first_var = cGen(p1);
         /* gen code for ac = right operand */
         char* second_var = cGen(p2);
         /* now load left operand */
         switch (tree->attr.op) {
            case PLUS :
               printf("%s = %s + %s", tmp_name, first_var, second_var);
               break;
            case MINUS :
               printf("%s = %s - %s", tmp_name, first_var, second_var);
               break;
            case TIMES :
               printf("%s = %s * %s", tmp_name, first_var, second_var);
               break;
            case OVER :
               printf("%s = %s / %s", tmp_name, first_var, second_var);
               break;
            case LT :
               printf("%s = %s < %s", tmp_name, first_var, second_var);
               break;
            case EQ :
               printf("%s = %s == %s", tmp_name, first_var, second_var);
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


static char * genDefDecl(TreeNode * tree){
   TreeNode * p1, * p2;
   switch (tree->kind.decl) {
    case VarK :
      break; /* VarK */
    
    case FunK :
      
      p1 = tree->child[1];
      while(p1 != NULL){
         
      }
      printf("%s: %s", tree->attr.name, )

      break; /* FunK */

    default:
      break;
  }
}



/*Acesso indexado*/
static void idx_access(TreeNode * tree){
   
}

/* Procedure cGen recursively generates code by
 * tree traversal
 */
static char * cGen( TreeNode * tree)
{  //printf("entrou em cGen\n");
   if (tree != NULL) {
      if(tree->attr.name != NULL){printf("%s\n", tree->attr.name);}
   switch (tree->nodekind) {
      case StmtK:
        return genStmt(tree);
        break;
      case ExpK:
        return genExp(tree);
        break;
      case DeclK:
         break;
      case AtvK:
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
