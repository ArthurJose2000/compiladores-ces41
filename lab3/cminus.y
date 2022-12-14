/****************************************************/
/* File: cminus.y                                   */
/* The C- Yacc/Bison specification file             */
/* Compiler Construction: Principles and Practice   */
/* Kenneth C. Louden                                */
/****************************************************/
%{
#define YYPARSER /* distinguishes Yacc output from other code files */

#include "globals.h"
#include "util.h"
#include "scan.h"
#include "parse.h"

#define YYSTYPE TreeNode *
static char * savedName; /* for use in assignments */
static int savedLineNo;  /* ditto */
static int savedValue; /* used for declarations */
static TreeNode * savedTree; /* stores syntax tree for later return */
static int yylex(void);
int yyerror(char *s);

%}

%token IF ELSE INT VOID WHILE 
%token ID NUM 
%token ASSIGN RETURN LT LEQT GT GEQT EQ NEQ PLUS MINUS TIMES OVER 
%token LPAREN RPAREN LBRACK RBRACK LBRACE RBRACE SEMI COMA
%token ERROR 

%% /* Grammar for C- */

program     : decl_lista
                 { savedTree = $1;} 
            ;
decl_lista    : decl_lista decl
                 { YYSTYPE t = $1;
                   if (t != NULL)
                   { while (t->sibling != NULL)
                        t = t->sibling;
                     t->sibling = $2;
                     $$ = $1; }
                     else $$ = $2;
                 }
            | decl  { $$ = $1; }
            ;
decl        : fun_decl { $$ = $1; }
            | var_decl { $$ = $1; }
            ;
id          : ID {$$ = newExpNode(IdK);
                  $$->attr.name = copyString(ID_name);
                  $$->lineno = lineno;}
            ;
var_decl    : INT id SEMI
                { $$ = newTypeNode();
                  $$->type = Integer;
                  $$->lineno = savedLineNo;
                  
                  $$->child[0] = newDeclNode(VarK);
                  $$->child[0]->type = Integer;
                  $$->child[0]->attr.name = $2->attr.name;
                  $$->child[0]->lineno = $2->lineno;
                }
            | VOID id SEMI
                { $$ = newTypeNode();
                  $$->type = Void;
                  $$->lineno = savedLineNo;
                  
                  $$->child[0] = newDeclNode(VarK);
                  $$->child[0]->type = Void;
                  $$->child[0]->attr.name = $2->attr.name;
                  $$->child[0]->lineno = $2->lineno;
                }
            | INT id LBRACK NUM { savedValue = atoi(tokenString); } RBRACK SEMI
                {
                  $$ = newTypeNode();
                  $$->type = Integer;
                  

                  $$->child[0] = newDeclNode(VarK);
                  $$->child[0]->type = Integer;
                  $$->child[0]->attr.name = $2->attr.name;
                  $$->child[0]->lineno = $2->lineno;

                  $$->child[0]->child[0] = newExpNode(ConstK);
                  $$->child[0]->child[0]->attr.val = savedValue;
                }
            | VOID id LBRACK NUM { savedValue = atoi(tokenString); } RBRACK SEMI
                {
                  $$ = newTypeNode();
                  $$->type = Void;

                  $$->child[0] = newDeclNode(VarK);
                  $$->child[0]->type = Void;
                  $$->child[0]->attr.name = $2->attr.name;
                  $$->child[0]->lineno = $2->lineno;

                  $$->child[0]->child[0] = newExpNode(ConstK);
                  $$->child[0]->child[0]->attr.val = savedValue;
                }
            ;
fun_decl    : INT id LPAREN params RPAREN comp_decl
                {
                  $$ = newTypeNode();
                  $$->type = Integer;

                  $$->child[0] = newDeclNode(FunK); 
                  $$->child[0]->type = Integer;
                  $$->child[0]->attr.name = $2->attr.name;
                  $$->child[0]->lineno = $2->lineno;
                  $$->child[0]->scope_name = $2->attr.name;

                  $$->child[0]->child[0] = $4;
                  $$->child[0]->child[1] = $6;
                }
            | VOID id LPAREN params RPAREN comp_decl
                {
                  $$ = newTypeNode();
                  $$->type = Void;

                  $$->child[0] = newDeclNode(FunK); 
                  $$->child[0]->type = Void;
                  $$->child[0]->attr.name = $2->attr.name;
                  $$->child[0]->lineno = $2->lineno;
                  $$->child[0]->scope_name = $2->attr.name;

                  $$->child[0]->child[0] = $4;
                  $$->child[0]->child[1] = $6;
                }
            ;
params      : param_list 
              { $$ = $1; }
            | VOID
              { 
                $$ = newDeclNode(VarK);
                $$->attr.name = "void";
                $$->type = Void;
              }
            ;
param_list  : param_list COMA param
              { YYSTYPE t = $1;
                   if (t != NULL)
                   { while (t->sibling != NULL)
                        t = t->sibling;
                     t->sibling = $3;
                     $$ = $1; }
                     else $$ = $3;
                 }
            | param { $$ = $1; }
            ;
param       : INT id
                { $$ = newTypeNode();
                  $$->type = Integer;
                  $$->lineno = savedLineNo;
                  
                  $$->child[0] = newDeclNode(VarK);
                  $$->child[0]->type = Integer;
                  $$->child[0]->attr.name = $2->attr.name;
                  $$->child[0]->lineno = $2->lineno;
                }
            | VOID id
                { $$ = newTypeNode();
                  $$->type = Void;
                  $$->lineno = savedLineNo;
                  
                  $$->child[0] = newDeclNode(VarK);
                  $$->child[0]->type = Void;
                  $$->child[0]->attr.name = $2->attr.name;
                  $$->child[0]->lineno = $2->lineno;
                }
            | INT id LBRACK RBRACK
                {
                  $$ = newTypeNode();
                  $$->type = Integer;

                  $$->child[0] = newDeclNode(VarK);
                  $$->child[0]->type = Integer;
                  $$->child[0]->attr.name = $2->attr.name;
                  $$->child[0]->lineno = $2->lineno;

                  $$->child[0]->child[0] = newExpNode(ConstK);
                  $$->child[0]->child[0]->type = Void;
                }
            | VOID id LBRACK RBRACK
                {
                  $$ = newTypeNode();
                  $$->type = Void;

                  $$->child[0] = newDeclNode(VarK);
                  $$->child[0]->type = Void;
                  $$->child[0]->attr.name = $2->attr.name;
                  $$->child[0]->lineno = $2->lineno;

                  $$->child[0]->child[0] = newExpNode(ConstK);
                  $$->child[0]->child[0]->type = Void;
                }
            ;
comp_decl   : LBRACE loc_decls stmt_list RBRACE
              { 
                YYSTYPE t = $2;
                if (t != NULL)
                { while (t->sibling != NULL)
                    t = t->sibling;
                  t->sibling = $3; 
                  $$ = $2; }
                else $$ = $3;
              }
            ;
loc_decls   : loc_decls var_decl
              { 
                YYSTYPE t = $1;
                if (t != NULL)
                { while (t->sibling != NULL)
                    t = t->sibling;
                  t->sibling = $2;
                  $$ = $1; }
                else $$ = $2;
              }
            | %empty {$$ = NULL;}
            ;
stmt_list   : stmt_list stmt
              { YYSTYPE t = $1;
                if (t != NULL)
                { while (t->sibling != NULL)
                    t = t->sibling;
                  t->sibling = $2;
                  $$ = $1; }
                  else $$ = $2;
              }
            | %empty {$$ = NULL;}
            ; 
stmt        : exp_decl { $$ = $1; }
            | comp_decl { $$ = $1; }
            | sel_decl { $$ = $1; }
            | itera_decl { $$ = $1; }
            | ret_decl { $$ = $1; }
            ;
exp_decl    : exp SEMI 
              { $$ = $1; }
            | SEMI
              { $$ = NULL; }
            ;
sel_decl    : IF LPAREN exp RPAREN stmt 
              { $$ = newStmtNode(IfK);
                $$->child[0] = $3;
                $$->child[1] = $5;
              }
            | IF LPAREN exp RPAREN stmt ELSE stmt
              { $$ = newStmtNode(IfK);
                $$->child[0] = $3;
                $$->child[1] = $5;
                $$->child[2] = $7;
              }
            ;
itera_decl  : WHILE LPAREN exp RPAREN stmt
              { $$ = newStmtNode(RepeatK);
                $$->child[0] = $3;
                $$->child[1] = $5;
              }
            ;
ret_decl    : RETURN SEMI { $$ = newStmtNode(ReturnK); }
            | RETURN exp SEMI 
                { $$ = newStmtNode(ReturnK);
                  $$->child[0] = $2; 
                }
            ;
exp         : var ASSIGN exp 
              { $$ = newExpNode(OpK);
                $$->child[0] = $1;
                $$->child[1] = $3;
                $$->attr.op = ASSIGN;
              }
            | simp_exp { $$ = $1; }
            ;
var         : id  {$$ = $1;}
            | id LBRACK exp RBRACK
              {
                $$ = newExpNode(IdK);
                $$->attr.name = $1->attr.name;
                $$->child[0] = $3;
              }
            ;
simp_exp    : soma_exp rela soma_exp
              { $$ = newExpNode(OpK);
                $$->child[0] = $1;
                $$->child[1] = $3;
                $$->attr.op = $2;
              }
            | soma_exp
              { $$ = $1; }
            ;
rela        : LEQT
              { $$ = LEQT; }
            | LT
              { $$ = LT; }
            | GT
              { $$ = GT; }
            | GEQT
              { $$ = GEQT; }
            | EQ
              { $$ = EQ; }
            | NEQ
              { $$ = NEQ; }
            ;
soma_exp    : soma_exp soma termo
              { $$ = newExpNode(OpK);
                $$->child[0] = $1;
                $$->child[1] = $3;
                $$->attr.op = $2;
              }
            | termo
              { $$ = $1; }
            ;
soma        : PLUS
              { $$ = PLUS; }
            | MINUS
              { $$ = MINUS; }
            ;
termo       : termo mult fator
              { $$ = newExpNode(OpK);
                $$->child[0] = $1;
                $$->child[1] = $3;
                $$->attr.op = $2;
              }
            | fator
              { $$ = $1; }
            ;
mult        : TIMES
              { $$ = TIMES; }
            | OVER
              { $$ = OVER; }
            ;
fator       : LPAREN exp RPAREN
              { $$ = $2; }
            | var
              { $$ = $1; }
            | ativ
              { $$ = $1; }
            | NUM
              { $$ = newExpNode(ConstK);
                $$->attr.val = atoi(tokenString);
              }
            ;
ativ        : id LPAREN args RPAREN
              {
                $$ = newAtvNode(AtvK);
                $$->attr.name = $1->attr.name;
                $$->lineno = $1->lineno;
                $$->child[0] = $3;
              }
            ;
args        : arg_list
              { $$ = $1; }
            | %empty {$$ = NULL;}
            ;
arg_list    : arg_list COMA exp
              { YYSTYPE t = $1;
                if (t != NULL)
                { while (t->sibling != NULL)
                    t = t->sibling;
                  t->sibling = $3;
                  $$ = $1; }
                  else $$ = $3;
              }
            | exp
              { $$ = $1; }
            ;
%%

int yyerror(char * message)
{ fprintf(listing,"Syntax error at line %d: %s\n",lineno,message);
  fprintf(listing,"Current token: ");
  printToken(yychar,tokenString);
  Error = TRUE;
  return 0;
}

/* yylex calls getToken to make Yacc/Bison output
 * compatible with ealier versions of the TINY scanner
 */
static int yylex(void)
{ return getToken(); }

TreeNode * parse(void)
{ yyparse();
  return savedTree;
}

