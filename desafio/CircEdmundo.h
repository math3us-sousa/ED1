#ifndef CIRCEDMUNDO_H  
#define CIRCEDMUNDO_H

#include <stdbool.h>

typedef struct circular Sorteio;

Sorteio* list_create();                // Cria uma nova lista circular
bool insert_begin(Sorteio*, int);       // Insere no início
void print(Sorteio*);                   // Imprime a lista
bool List_remove(Sorteio*, int);        // Remove um elemento da lista
#endif
