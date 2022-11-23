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
     int memloc ; /* memory location for variable */
     struct BucketListRec * next;
     char * scope_name;   /*Name of the scope this ID is in*/
     ExpType type;    /*Distinguish between Integer and Void types*/
     DeclKind kind;   /*Distinguish between variables and functions*/
   } * BucketList;

/* the hash table */
static BucketList hashTable[SIZE];

/* new insert demo*/
void st_insertV2( char * name, int lineno, int loc, char *scope_name, ExpType type, DeclKind kind ){
  int h = hash(name);
  int search_res = 0; //search_ID(name, scope_name, loc); ta dando mt errado a funcao search_ID() nao sei pq.
  BucketList l = hashTable[h];
  if (search_res == 0 || search_res == 1 || search_res == 3){ /*Variable not yet in table or in another scope of same or lower level, add it*/
    while (l != NULL)
      l = l->next;
    l = (BucketList) malloc(sizeof(struct BucketListRec));
    l->name = name;
    l->lines = (LineList) malloc(sizeof(struct LineListRec));
    l->lines->lineno = lineno;
    l->memloc = loc;
    l->type = type;
    l->kind = kind;
    l->scope_name = scope_name;
    l->lines->next = NULL;
    l->next = hashTable[h];
    hashTable[h] = l; 
  }else if(search_res == 2){  /*Variable found in higher scope level, add line number*/
    while ((l != NULL) && (strcmp(name,l->name) != 0))
      l = l->next;
    if(l != NULL){
      LineList t = l->lines;
      while (t->next != NULL) t = t->next;
      t->next = (LineList) malloc(sizeof(struct LineListRec));
      t->next->lineno = lineno;
      t->next->next = NULL;
    } 
  }else{ /*Invalid insert*/
    printf("Invalid variable insert\n");
  }
}

/* Procedure st_insert inserts line numbers and
 * memory locations into the symbol table
 * loc = memory location is inserted only the
 * first time, otherwise ignored
 */
void st_insert( char * name, int lineno, int loc, char *scope_name, ExpType type, DeclKind kind )
{ int h = hash(name);
  BucketList l =  hashTable[h];
  while ((l != NULL) && (strcmp(name,l->name) != 0))
    l = l->next;
  if (l == NULL) /* variable not yet in table */
  { l = (BucketList) malloc(sizeof(struct BucketListRec));
    l->name = name;
    l->lines = (LineList) malloc(sizeof(struct LineListRec));
    l->lines->lineno = lineno;
    l->memloc = loc;
    l->type = type;
    l->kind = kind;
    l->scope_name = scope_name;
    l->lines->next = NULL;
    l->next = hashTable[h];
    hashTable[h] = l; }
  else /* found in table, so just add line number */
  { LineList t = l->lines;
    while (t->next != NULL) t = t->next;
    t->next = (LineList) malloc(sizeof(struct LineListRec));
    t->next->lineno = lineno;
    t->next->next = NULL;
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
  else return l->memloc;
}


/*Search the table for same IDs scope relations
 * return 0 if not found same ID
 * return 1 if found same ID in lower scope
 * return 2 if found same ID in higher scope
 * return 3 if found same ID in another scope of the same level
 * return 4 if found same ID in the same scope
 */
int search_ID(char * name, char * scope_name, int memloc){
  int h = hash(name);
  BucketList l =  hashTable[h];
  if(l == NULL) {return 0;}
  while (l != NULL){
    if(l == NULL) {printf("l is null in 4\n");}
    if(strcmp(name,l->name) == 0){  /*Found same ID*/
      if(l->memloc == memloc || strcmp(scope_name, l->scope_name) == 0){  /*Same level same scope*/
        return 4;   /*Found in same scope*/
      }
    }
    l = l->next;
  }
  l =  hashTable[h];
  while (l != NULL)
  { if(l == NULL) {printf("l is null in 2\n");}
    if(strcmp(name,l->name) == 0){  /*Found same ID*/
      if(l->memloc < memloc ){  /*Found in higher scope*/
        return 2;  
      }
    l = l->next;
    }
  }
  l =  hashTable[h];
  while (l != NULL)
  { if(l == NULL) {printf("l is null in 3\n");}
    if(strcmp(name,l->name) == 0){  /*Found same ID*/
      if(l->memloc == memloc || strcmp(scope_name, l->scope_name) != 0){  /*Same level different scope*/
        return 3;  /*Found in another scope of the same level*/
      }
    l = l->next;
    }
  }
  l =  hashTable[h];
  while (l != NULL)
  { if(l == NULL) {printf("l is null in 1\n");}
    if(strcmp(name,l->name) == 0){  /*Found same ID*/
      if(l->memloc > memloc ){  /*Found in lower scope*/
        return 1;  
      }
    l = l->next;
    }
  }
  return 0;   /*Not found in symbol table*/
}


/* Procedure printSymTab prints a formatted 
 * listing of the symbol table contents 
 * to the listing file
 */
void printSymTab(FILE * listing)
{ int i;
  fprintf(listing,"Variable Name  Scope Level   Scope Name    Type    Kind   Line Numbers\n");
  fprintf(listing,"-------------  -----------   ----------    ----    ----   ------------\n");
  for (i=0;i<SIZE;++i)
  { if (hashTable[i] != NULL)
    { BucketList l = hashTable[i];
      while (l != NULL)
      { LineList t = l->lines;
        fprintf(listing,"%-14s ",l->name);
        fprintf(listing,"%-11d  ",l->memloc);
        fprintf(listing,"%5s",l->scope_name);
        fprintf(listing,"%13d", l->type);
        fprintf(listing,"%8d", l->kind);
        while (t != NULL)
        { fprintf(listing,"%6d ",t->lineno);
          t = t->next;
        }
        fprintf(listing,"\n");
        l = l->next;
      }
    }
  }
} /* printSymTab */
