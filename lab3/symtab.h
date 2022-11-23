/****************************************************/
/* File: symtab.h                                   */
/* Symbol table interface for the TINY compiler     */
/* (allows only one symbol table)                   */
/* Compiler Construction: Principles and Practice   */
/* Kenneth C. Louden                                */
/****************************************************/

#ifndef _SYMTAB_H_
#define _SYMTAB_H_
#include "globals.h"

/* Procedure st_insert inserts line numbers and
 * memory locations into the symbol table
 * loc = memory location is inserted only the
 * first time, otherwise ignored
 */
void st_insert( TreeNode *node, char *name, int lineno, int scope_level, char *scope_name, ExpType type, NodeKind nodekind, DeclKind kind );

/* Function st_lookup returns the memory 
 * location of a variable or -1 if not found
 */
int st_lookup ( char * name );

/*Search the table for same IDs scope relations
 * return 0 if not found same ID
 * return 1 if found same ID in higher or different scopes
 * return 2 if found same Id in the same scope
 */
enum id_search_case {
    NEW_DECLARATION__ID_NOT_FOUND,
    NEW_DECLARATION__ID_IN_A_LOWER_SCOPE,
    NEW_DECLARATION__ID_IN_A_HIGHER_SCOPE, 
    NEW_DECLARATION__ID_IN_ANOTHER_SCOPE_WITH_SAME_LEVEL, 
    NEW_DECLARATION__ID_IN_SAME_SCOPE_NAME, 
    IS_NOT_A_DECLARATION__NO_SCOPE_NAME_EXP,
    VARIABLE_IS_NOT_DECLARED,
    IS_NOT_A_DECLARATION,
    FUNCTION_IS_NOT_DECLARED,
    VARIABLE_DECLARATION_WITH_SAME_NAME_OF_A_PREVIOUS_FUNCTION
};
int search_ID(TreeNode *node, char * name, char * scope_name, int scope_level, NodeKind nodekind, DeclKind kind);

/* Procedure printSymTab prints a formatted 
 * listing of the symbol table contents 
 * to the listing file
 */
void printSymTab(FILE * listing);

#endif
