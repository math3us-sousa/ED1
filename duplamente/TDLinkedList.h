#ifndef TDLINKEDLIST_H
#define TDLINKEDLIST_H
#include <stdbool.h>

typedef struct _tdlink TDLinkedList;

TDLinkedList* list_create();
bool insert_end(TDLinkedList*, int);
void print(TDLinkedList*);
bool insert_ordem(TDLinkedList*, int);




#endif
