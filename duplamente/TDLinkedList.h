#ifndef TDLINKED_LIST_H
#define TDLINKED_LIST_H

#include <stdbool.h>

typedef struct _tdlinked_list TDLinkedList;

bool TDLinkedList_insert_end(TDLinkedList*, int);

bool TDLinkedList_insert_begin(TDLinkedList*, int);

TDLinkedList* TDLinkedList_Create();

void TDLinkedList_print(TDLinkedList*);

void TDLinkedList_print_reverse(TDLinkedList*);


#endif
