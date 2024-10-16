#ifndef CircEdmundo_H
#define CircEdmundo_H
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct circ_list TCircList;

TCircList* TCircList_create();

bool TCircList_insert_begin(TCircList* list, int info);

bool TCircList_insert_end(TCircList* list, int info);

void TCircList_print(TCircList*);

int TCircList_remove(TCircList* list, int soldado);




#endif
