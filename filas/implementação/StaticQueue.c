#include "Queue.h"
#include <stdlib.h>
#define MAX 5


struct queue{
    int qty, head, tail;
    int data[MAX];
};

Queue* create_fila(){
    Queue* nova = malloc(sizeof(Queue));
    if(nova!=NULL){
        nova->head=0;
        nova->qty=0;
        nova->tail=0;
    }
    return nova;
}
void destroy_fila(Queue* fila){
    free(fila);
}
int enqueue_fila(Queue* fila, int data){
    if(queue_full(fila)) return 0;
    fila->data[fila->tail] = data;
    fila->qty++;
    fila->tail = (fila->tail + 1) % MAX;
    return 1;
}
int dequeue_fila(Queue* fila, int* data){
    if(queue_empty(fila)) return 0;
    *data = fila->data[fila->head];
    fila->qty--;
    fila->head = (fila->head + 1) % MAX;
    return 1;
}
int head_fila(Queue* fila, int* data){ // mostra a informação do início da fila
    if(queue_empty(fila)) return 0;
    *data = fila->data[fila->head];
    return 1;
}

int queue_full(Queue* lista){
    return lista->qty == MAX; //retorna 1 se a fila estiver cheia
    // ou return lista->qty == 5;
}
int queue_empty(Queue* lista){
    return lista->qty == 0; //retorna 1 se a fila estiver vazia
}
int queue_qty(Queue* lista){// retorna a quantidade de elementos da fila
    return lista->qty; 
}