#ifndef STACK_H
#define STACK_H
#include "Queue.h"
typedef struct stack Stack;

Stack* create();
int push(Stack*, int);
int pop(Stack*, int*);
int head(Stack*, int*);
void destroy(Stack*);
int full(Stack*);
int empty(Stack*);
int qty(Stack*);
int remover_carro(Stack*, Stack*, int);
void print_stack(Stack*);
Stack* pilha_ajustada(Queue*, Queue*);


#endif