/****************************************************/
/* File: analyze.c                                  */
/* Semantic analyzer implementation                 */
/* for the TINY compiler                            */
/* Compiler Construction: Principles and Practice   */
/* Kenneth C. Louden                                */
/****************************************************/

#include "globals.h"
#include "symtab.h"
#include "analyze.h"
#include "scan.h"

static void typeError(TreeNode * t, char * message, int code_error)
{ fprintf(listing,"Error (CODE: %d) at line %d: %s\n", code_error, t->lineno, message);
  Error = TRUE;
}

/* Procedure traverse is a generic recursive 
 * syntax tree traversal routine:
 * it applies preProc in preorder and postProc 
 * in postorder to tree pointed to by t
 */
static void traverse( TreeNode * t, void (* preProc) (TreeNode *), void (* postProc) (TreeNode *) ) {
  if (t != NULL){
    preProc(t);
    { int i;
      for (i=0; i < MAXCHILDREN; i++)
        traverse(t->child[i],preProc,postProc);
    }
    postProc(t);
    traverse(t->sibling,preProc,postProc);
  }
}

/* nullProc is a do-nothing procedure to 
 * generate preorder-only or postorder-only
 * traversals from traverse
 */
static void nullProc(TreeNode * t)
{ if (t==NULL) return;
  else return;
}

/* Procedure insertNode inserts 
 * identifiers stored in t into 
 * the symbol table 
 */
static void insertNode( TreeNode * t){ 
  switch (t->nodekind)
  { case StmtK:
      switch (t->kind.stmt)
      { case AssignK:
        case IfK:
          break;
        case RepeatK:
          break;
        case ReturnK:
          break;
        default:
          break;
      }
      break;
    case ExpK:
      switch (t->kind.exp)
      { 
        case IdK:
          st_insert(t->attr.name,t->lineno,t->scope_lvl,t->scope_name, t->type, ExpK, -1);
          if (t->scope_name == NULL)
            printf("IdK: algo errado com %s na linha %d - tipo %d\n", t->attr.name, t->lineno, t->type);
          break;
        default:
          break;
      }
      break;
    case DeclK:
      switch (t->kind.decl)
        { 
          case VarK:
            if (t->scope_name == NULL)
              printf("VarK: algo errado com %s na linha %d\n", t->attr.name, t->lineno);

            if (t->type == Void && strcmp(t->attr.name, "void") != 0) {
              typeError(t,"a variable cannot be declared as void", 3);
              exit(1);
            }
            else if (strcmp(t->attr.name, "void") != 0)
              st_insert(t->attr.name,t->lineno,t->scope_lvl,t->scope_name, t->type, DeclK, VarK);
            break;
          case FunK:
            if (t->scope_name == NULL)
              printf("FunK: algo errado com %s na linha %d\n", t->attr.name, t->lineno);
            st_insert(t->attr.name,t->lineno,t->scope_lvl,t->scope_name, t->type, DeclK, FunK);
            break;
          default:
            break;
        }
        break;
    case AtvK:
      if (t->scope_name == NULL)
        printf("AtvK: algo errado com %s na linha %d\n", t->attr.name, t->lineno);
      if (strcmp(t->attr.name, "input") == 0) {
        t->scope_name = "GLOBAL";
        t->type = Integer;
      } else if (strcmp(t->attr.name, "output") == 0) {
        t->scope_name = "GLOBAL";
        t->type = Void;
      }
      st_insert(t->attr.name,t->lineno,t->scope_lvl,t->scope_name, t->type, AtvK, -1);
      break;
    default:
      break;
  }
}

/* Function buildSymtab constructs the symbol 
 * table by preorder traversal of the syntax tree
 */
void buildSymtab(TreeNode * syntaxTree)
{ traverse(syntaxTree,insertNode,nullProc);
  if (TraceAnalyze)
  { fprintf(listing,"\nSymbol table:\n\n");
    printSymTab(listing);
  }
}

/* Procedure checkNode performs
 * type checking at a single tree node
 */
static void checkNode(TreeNode * t) {
  switch (t->nodekind) {
    case ExpK:
      switch (t->kind.exp) {
        case OpK:
          // if ((t->child[0]->type == Integer) && (t->child[1]->type != Void)) {
          //   printf("t->child[0]->type: %d, t->child[1]->type: %d\n", t->child[0]->type, t->child[1]->type);
          //   typeError(t,"invalid assignment (int variable receiving void)", 2);
          // }
          break;
        case ConstK:
        case IdK:
          break;
        default:
          break;
      }
      break;
    case StmtK:
      switch (t->kind.stmt) {
        case IfK:
          break;
        case AssignK:
          break;
        case RepeatK:
          break;
        default:
          break;
      }
      break;
    default:
      break;

  }
}

/* Procedure typeCheck performs type checking 
 * by a postorder syntax tree traversal
 */
void typeCheck(TreeNode * syntaxTree)
{ traverse(syntaxTree,nullProc,checkNode);
}
