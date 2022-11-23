/****************************************************/
/* File: symtab.c                                   */
/* Symbol table implementation for the TINY compiler*/
/* (allows only one symbol table)                   */
/* Symbol table is implemented as a chained         */
/* hash table                                       */
/* Compiler Construction: Principles and Practice   */
/* Kenneth C. Louden                                */
/****************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "symtab.h"
#include "globals.h"

/* SIZE is the size of the hash table */
#define SIZE 211

/* SHIFT is the power of two used as multiplier
   in hash function  */
#define SHIFT 4

/* the hash function */
static int hash ( char * key )
{ int temp = 0;
  int i = 0;
  while (key[i] != '\0')
  { temp = ((temp << SHIFT) + key[i]) % SIZE;
    ++i;
  }
  return temp;
}

/* the list of line numbers of the source 
 * code in which a variable is referenced
 */
typedef struct LineListRec
{ int lineno;
  struct LineListRec * next;
} * LineList;

/* The record in the bucket lists for
 * each variable, including name, 
 * assigned memory location, and
 * the list of line numbers in which
 * it appears in the source code
 */
typedef struct BucketListRec
   { char * name;
     LineList lines;
     int scope_level ; /* memory location for variable */
     struct BucketListRec * next;
     char * scope_name;   /*Name of the scope this ID is in*/
     ExpType type;    /*Distinguish between Integer and Void types*/
     DeclKind kind;   /*Distinguish between variables and functions*/
   } * BucketList;

/* the hash table */
static BucketList hashTable[SIZE];

/* Procedure st_insert inserts line numbers and
 * memory locations into the symbol table
 * loc = memory location is inserted only the
 * first time, otherwise ignored
 */
void st_insert( char *name, int lineno, int scope_level, char *scope_name, ExpType type, NodeKind nodekind, DeclKind kind ) {

  int h = hash(name);
  BucketList l =  hashTable[h];
  while ((l != NULL) && (strcmp(name,l->name) != 0))
    l = l->next;
  
  LineList t;
  if (l != NULL)
    t = l->lines;

  int id_search_case = search_ID(name, scope_name, scope_level, nodekind, kind);

  switch (id_search_case) {
    case NEW_DECLARATION__ID_NOT_FOUND:
    case NEW_DECLARATION__ID_IN_A_HIGHER_SCOPE:
    case NEW_DECLARATION__ID_IN_ANOTHER_SCOPE_WITH_SAME_LEVEL:
      l = (BucketList) malloc(sizeof(struct BucketListRec));
      l->name = name;
      l->lines = (LineList) malloc(sizeof(struct LineListRec));
      l->lines->lineno = lineno;
      l->scope_level = scope_level;
      l->type = type;
      l->kind = kind;
      l->scope_name = scope_name;
      l->lines->next = NULL;
      l->next = hashTable[h];
      hashTable[h] = l;
      break;
    case IS_NOT_A_DECLARATION:
    case IS_NOT_A_DECLARATION__NO_SCOPE_NAME_EXP:
      while (t->next != NULL) t = t->next;
      t->next = (LineList) malloc(sizeof(struct LineListRec));
      t->next->lineno = lineno;
      t->next->next = NULL;
      break;
    case NEW_DECLARATION__ID_IN_A_LOWER_SCOPE:
      break;
    case VARIABLE_IS_NOT_DECLARED:
      printf("Error (CODE: 1) at line %d: variable '%s' is not declared\n", lineno, name);
      exit(1);
      break;
    case FUNCTION_IS_NOT_DECLARED:
      printf("Error (CODE: 5) at line %d: function '%s' is not declared\n", lineno, name);
      exit(1);
      break;
    case NEW_DECLARATION__ID_IN_SAME_SCOPE_NAME: // ERROR
      printf("Error (CODE: 4) at line %d: invalid declaration of '%s' (previously declared)\n", lineno, name);
      exit(1);
      break;
    case VARIABLE_DECLARATION_WITH_SAME_NAME_OF_A_PREVIOUS_FUNCTION:
      printf("Error (CODE: 7) at line %d: invalid declaration of '%s' (already exist a function with same name that was declared previously)\n", lineno, name);
      exit(1);
      break;
    default:
      break;
  }
} /* st_insert */

/* Function st_lookup returns the memory 
 * location of a variable or -1 if not found
 */
int st_lookup ( char * name )
{ int h = hash(name);
  BucketList l =  hashTable[h];
  while ((l != NULL) && (strcmp(name,l->name) != 0))
    l = l->next;
  if (l == NULL) return -1;
  else return l->scope_level;
}

int search_ID(char * name, char * scope_name, int scope_level, NodeKind nodekind, DeclKind kind) {

  int h = hash(name);
  BucketList l =  hashTable[h];

  while ((l != NULL) && (strcmp(name,l->name) != 0))
    l = l->next;

  if (l == NULL && scope_name != NULL) { /* variable not yet in table */
    return NEW_DECLARATION__ID_NOT_FOUND;
  }
  else if (l == NULL && scope_name == NULL && nodekind == AtvK) { /* gambiarra */
      return FUNCTION_IS_NOT_DECLARED; 
  }
  else if (l == NULL && scope_name == NULL) { /* gambiarra */
      return VARIABLE_IS_NOT_DECLARED; 
  }
  else if (scope_name == NULL || nodekind == ExpK) { /* gambiarra */
    return IS_NOT_A_DECLARATION__NO_SCOPE_NAME_EXP; 
  }
  else if (nodekind == AtvK) {
    return IS_NOT_A_DECLARATION;
  }
  else { /* found in table, so just check more deeply */

    if (l->kind == FunK)
      return VARIABLE_DECLARATION_WITH_SAME_NAME_OF_A_PREVIOUS_FUNCTION;

    if (l->scope_level > scope_level) {
      return NEW_DECLARATION__ID_IN_A_LOWER_SCOPE;
    }
    else if (l->scope_level < scope_level) {
      return NEW_DECLARATION__ID_IN_A_HIGHER_SCOPE;
    }
    else if (l->scope_level == scope_level && strcmp(scope_name, l->scope_name) != 0) {
      return NEW_DECLARATION__ID_IN_ANOTHER_SCOPE_WITH_SAME_LEVEL;
    }
    else if (l->scope_level == scope_level && strcmp(scope_name, l->scope_name) == 0) {
      return NEW_DECLARATION__ID_IN_SAME_SCOPE_NAME;
    }
  }
}


/* Procedure printSymTab prints a formatted 
 * listing of the symbol table contents 
 * to the listing file
 */
void printSymTab(FILE * listing) { 
  bool isThereMainFunction = FALSE;
  int i;
  fprintf(listing,"Variable Name  Scope Level   Scope Name   Type   Kind   Line Numbers\n");
  fprintf(listing,"-------------  -----------   ----------   ----   ----   ------------\n");
  for (i=0;i<SIZE;++i)
  { if (hashTable[i] != NULL)
    { BucketList l = hashTable[i];
      while (l != NULL)
      { LineList t = l->lines;
        fprintf(listing,"%-15s",l->name);
        fprintf(listing,"%-14d",l->scope_level);
        fprintf(listing,"%-13s",l->scope_name);

        if (l->type == Integer)
          fprintf(listing,"%-7s", "int");
        else if (l->type == Void)
          fprintf(listing,"%-7s", "void");
        
        if (l->kind == VarK)
          fprintf(listing,"%-7s", "VarK");
        else if (l->kind == FunK)
          fprintf(listing,"%-7s", "Funk");
        else
          fprintf(listing,"%-7s", "Funk"); // to output() and input()

        while (t != NULL)
        { fprintf(listing,"%-4d ",t->lineno);
          t = t->next;
        }
        fprintf(listing,"\n");

        if (strcmp(l->name, "main") == 0)
          isThereMainFunction = TRUE;

        l = l->next;
      }
    }
  }

  if (!isThereMainFunction) {
    printf("Error (CODE: 6): main function does not exist.\n");
    exit(1);
  }
} /* printSymTab */
