#ifndef QUEUE_H
#define QUEUE_H

typedef struct queue Queue;

Queue* create_fila();
void destroy_fila(Queue*);
int enqueue_fila(Queue*, int);
int dequeue_fila(Queue*, int*);
int head_fila(Queue*, int*);

int queue_full(Queue*);
int queue_empty(Queue*);
int queue_qty(Queue*);
void print(Queue*);

//ex7
Queue* intercala_fila(Queue*, Queue*);

#endif