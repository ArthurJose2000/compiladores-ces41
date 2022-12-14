/****************************************************/
/* File: util.c                                     */
/* Utility function implementation                  */
/* for the C- compiler                              */
/* Compiler Construction: Principles and Practice   */
/* Kenneth C. Louden                                */
/****************************************************/

#include "globals.h"
#include "util.h"


/* Procedure printToken prints a token
 * and its lexeme to the listing file
 */
void printToken(TokenType token, const char *tokenString)
{
  switch (token)
  {
  case IF:
  case ELSE:
  case INT:
  case RETURN:
  case VOID:
  case WHILE:
    fprintf(listing,
            "reserved word: %s\n", tokenString);
    break;
  case ASSIGN:
    fprintf(listing, "=\n");
    break;
  case LT:
    fprintf(listing, "<\n");
    break;
  case LEQT:
    fprintf(listing, "<=\n");
    break;
  case GT:
    fprintf(listing, ">\n");
    break;
  case GEQT:
    fprintf(listing, ">=\n");
    break;
  case EQ:
    fprintf(listing, "==\n");
    break;
  case NEQ:
    fprintf(listing, "!=\n");
    break;
  case PLUS:
    fprintf(listing, "+\n");
    break;
  case MINUS:
    fprintf(listing, "-\n");
    break;
  case TIMES:
    fprintf(listing, "*\n");
    break;
  case OVER:
    fprintf(listing, "/\n");
    break;
  case LPAREN:
    fprintf(listing, "(\n");
    break;
  case RPAREN:
    fprintf(listing, ")\n");
    break;
  case LBRACK:
    fprintf(listing, "[\n");
    break;
  case RBRACK:
    fprintf(listing, "]\n");
    break;
  case LBRACE:
    fprintf(listing, "{\n");
    break;
  case RBRACE:
    fprintf(listing, "}\n");
    break;
  case SEMI:
    fprintf(listing, ";\n");
    break;
  case COMA:
    fprintf(listing, ",\n");
    break;
  case ENDFILE:
    fprintf(listing, "EOF\n");
    break;
  case NUM:
    fprintf(listing,
            "NUM, val= %s\n", tokenString);
    break;
  case ID:
    fprintf(listing,
            "ID, name= %s\n", tokenString);
    break;
  case ERROR:
    fprintf(listing,
            "ERROR: %s\n", tokenString);
    break;
  default: /* should never happen */
    fprintf(listing, "Unknown token: %d\n", token);
  }
}

/* Function newTypeNode creates a new Type
 * node for syntax tree construction
 */
TreeNode *newTypeNode()
{
  TreeNode *t = (TreeNode *)malloc(sizeof(TreeNode));
  int i;
  if (t == NULL)
    fprintf(listing, "Out of memory error at line %d\n", lineno);
  else
  {
    for (i = 0; i < MAXCHILDREN; i++)
      t->child[i] = NULL;
    t->sibling = NULL;
    t->nodekind = TypeK;
    t->lineno = lineno;
    t->type = Void;
  }
  return t;
}

/* Function newAtvNode creates a new Ativation
 * node for syntax tree construction
 */
TreeNode *newAtvNode()
{
  TreeNode *t = (TreeNode *)malloc(sizeof(TreeNode));
  int i;
  if (t == NULL)
    fprintf(listing, "Out of memory error at line %d\n", lineno);
  else
  {
    for (i = 0; i < MAXCHILDREN; i++)
      t->child[i] = NULL;
    t->sibling = NULL;
    t->nodekind = AtvK;
    t->lineno = lineno;
  }
  return t;
}

/* Function newDeclNode creates a new Declaracao
 * node for syntax tree construction
 */
TreeNode *newDeclNode(DeclKind kind)
{
  TreeNode *t = (TreeNode *)malloc(sizeof(TreeNode));
  int i;
  if (t == NULL)
    fprintf(listing, "Out of memory error at line %d\n", lineno);
  else
  {
    for (i = 0; i < MAXCHILDREN; i++)
      t->child[i] = NULL;
    t->sibling = NULL;
    t->nodekind = DeclK;
    t->kind.decl = kind;
    t->lineno = lineno;
    t->type = Void;
  }
  return t;
}

/* Function newStmtNode creates a new statement
 * node for syntax tree construction
 */
TreeNode *newStmtNode(StmtKind kind)
{
  TreeNode *t = (TreeNode *)malloc(sizeof(TreeNode));
  int i;
  if (t == NULL)
    fprintf(listing, "Out of memory error at line %d\n", lineno);
  else
  {
    for (i = 0; i < MAXCHILDREN; i++)
      t->child[i] = NULL;
    t->sibling = NULL;
    t->nodekind = StmtK;
    t->kind.stmt = kind;
    t->lineno = lineno;
  }
  return t;
}

/* Function newExpNode creates a new expression
 * node for syntax tree construction
 */
TreeNode *newExpNode(ExpKind kind)
{
  TreeNode *t = (TreeNode *)malloc(sizeof(TreeNode));
  int i;
  if (t == NULL)
    fprintf(listing, "Out of memory error at line %d\n", lineno);
  else
  {
    for (i = 0; i < MAXCHILDREN; i++)
      t->child[i] = NULL;
    t->sibling = NULL;
    t->nodekind = ExpK;
    t->kind.exp = kind;
    t->lineno = lineno;
    t->type = Void;
  }
  return t;
}
/**/

char * scopeName(char* name, int x){
  char* scope_name;
  char intstr[10];
  int len = strlen(name)+10;
  scope_name = malloc(len);
  strcpy(scope_name, name);
  sprintf(intstr, "%d", x); 
  strcat(scope_name, intstr);
  return scope_name;
}

/* Function copyString allocates and makes a new
 * copy of an existing string
 */
char *copyString(char *s)
{
  int n;
  char *t;
  if (s == NULL)
    return NULL;
  n = strlen(s) + 1;
  t = malloc(n);
  if (t == NULL)
    fprintf(listing, "Out of memory error at line %d\n", lineno);
  else
    strcpy(t, s);
  return t;
}

/*Update children's scope name*/
void scope_update(TreeNode * node, char* scopename){
  TreeNode * t = node;
  while (t != NULL && t->child[0] != NULL){
    t->child[0]->scope_name = scopename;
    t = t->sibling;
  }
}


/* Variable indentno is used by printTree to
 * store current number of spaces to indent
 */
static int indentno = 0;

/* Variable to track scope level of nodes */
static int scope_lvl = 0;

/* Variable to track scope lineno of nodes */
static int scope_lineno = 0;

/*Variable to count ifs*/
static int if_count = 0;

/*Variable to count whiles*/
static int while_count = 0;

/* macros to increase/decrease indentation */
#define INDENT indentno += 2
#define UNINDENT indentno -= 2

/* printSpaces indents by printing spaces */
static void printSpaces(void)
{
  int i;
  for (i = 0; i < indentno; i++)
    fprintf(listing, " ");
}

/* procedure printTree prints a syntax tree to the
 * listing file using indentation to indicate subtrees
 */
void printTree(TreeNode *tree)
{
  int i;
  char *current_if_count;
  char *current_while_count;
  INDENT;
  while (tree != NULL)
  {
    printSpaces();
    if (tree->nodekind == StmtK)
    {
      switch (tree->kind.stmt)
      {
      case IfK:
        if_count++;
        fprintf(listing, "If in scope lvl: %d\n", scope_lvl);
        scope_update(tree->child[0], tree->scope_name);
        scope_update(tree->child[1], scopeName("if", if_count));
        scope_update(tree->child[2], scopeName("else", if_count));
        scope_lvl++;
        break;
      case RepeatK:
        while_count++;
        scope_update(tree->child[0], tree->scope_name);
        scope_update(tree->child[1], scopeName("while", while_count));
        scope_lvl++;
        fprintf(listing, "Repeat\n");
        break;
      case AssignK:
        tree->scope_lvl = scope_lvl;
        scope_update(tree, tree->scope_name);
        fprintf(listing, "Assign to: %s scope_lvl: %d\n", tree->attr.name, scope_lvl);
        break;
      case ReturnK:
        scope_update(tree, tree->scope_name);
        fprintf(listing, "Return\n");
        break;
      default:
        fprintf(listing, "Unknown ExpNode kind\n");
        break;
      }
    }
    else if (tree->nodekind == ExpK)
    {
      switch (tree->kind.exp)
      {
      case OpK:
        fprintf(listing, "Op: ");
        scope_update(tree, tree->scope_name);
        printToken(tree->attr.op, "\0");
        // if (tree->attr.op == ASSIGN) {
        //   printf("assingnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnn tree->scope_name: %s\n", tree->scope_name);
        // }
        break;
      case ConstK:
        fprintf(listing, "Const: %d\n", tree->attr.val);
        break;
      case IdK:
        tree->scope_lvl=scope_lvl;
        scope_update(tree, tree->scope_name);
        fprintf(listing, "Id: %s scope_lvl: %d\n", tree->attr.name, scope_lvl);
        break;
      default:
        fprintf(listing, "Unknown ExpNode kind\n");
        break;
      }
    }
    else if (tree->nodekind == DeclK)
    {
      switch (tree->kind.decl)
      {
      case VarK:
        tree->scope_lvl=scope_lvl;
        if (scope_lvl == 0)
          tree->scope_name = "GLOBAL";
        scope_update(tree, tree->scope_name);
        fprintf(listing, "Decl_Var: %s scope_lvl: %d\n", tree->attr.name, scope_lvl);
        break;
      case FunK:
        tree->scope_lvl=scope_lvl;
        scope_update(tree->child[0], tree->scope_name);
        scope_update(tree->child[1], tree->scope_name);
        fprintf(listing, "Decl_Fun: %s in scope: %d\n", tree->attr.name, scope_lvl);
        scope_lvl++;
        break;
      }
    }
    else if (tree->nodekind == TypeK)
    {
      switch (tree->type)
      {
      case Integer:
        fprintf(listing, "int \n");
        break;
      case Void:
        fprintf(listing, "void \n");
        break;
      }
    }
    else if (tree->nodekind == AtvK)
    {
      tree->scope_lvl=scope_lvl;
      scope_update(tree, tree->scope_name);
      fprintf(listing, "Atv_Fun: %s in scope: %d\n", tree->attr.name, tree->scope_lvl);
    }
    else
      fprintf(listing, "Unknown node kind\n");
    for (i = 0; i < MAXCHILDREN; i++)
      printTree(tree->child[i]);
    
    /*Adjust scope level*/
    if (tree->nodekind == StmtK){
      if (tree->kind.stmt == IfK || tree->kind.stmt == RepeatK){
          scope_lvl--;
        }
    }else if (tree->nodekind == DeclK){
      if (tree->kind.decl == FunK){
        scope_lvl--;
      }
    }
    tree = tree->sibling;
  }
  UNINDENT;
}
