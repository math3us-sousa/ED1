#ifndef STACK_H
#define STACK_H

typedef struct stack Stack;

Stack* create();
int push(Stack*, int);
int pop(Stack*, int*);
int head(Stack*, int*);
void destroy(Stack*);
int full(Stack*);
int empty(Stack*);
int qty(Stack*);
int remover_carro(Stack*, Stack*, int);//para Edcarlos
void print_stack(Stack*);


#endif
