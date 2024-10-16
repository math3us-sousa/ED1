#ifndef TCircList_H
#define TCircList_H
#include <stdbool.h>


/*
*  Structure of a node of the list
*/
typedef struct circ_list TCircList;

TCircList* TCircList_create();

bool TCircList_insert_begin(TCircList* list, int info);

bool TCircList_insert_end(TCircList* list, int info);

void TCircList_print(TCircList*);



#endif
