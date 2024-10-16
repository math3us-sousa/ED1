#ifndef LINKED_LIST
#define LINKED_LIST
#include <stdbool.h>

typedef struct _list TLinkedList;
TLinkedList* TLinkedList_create();
bool TLinkedList_insert_begin(TLinkedList*, int);
bool TLinkedList_insert_final(TLinkedList*, int);
bool TLinkedList_insert_end(TLinkedList*, int);
void TLinkedList_print(TLinkedList*);

#endif
