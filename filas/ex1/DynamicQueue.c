#include "Queue.h"
#include "Stack.h"
#include <stdlib.h>

typedef struct no{
    int data;
    struct no* prox;
}Tno;

Tno* create_no_fila(int info){
    Tno* novo = malloc(sizeof(Tno));
    if(novo!=NULL){
        novo->data = info;
        novo->prox = novo;
    } return novo;
}
struct queue{
    int qty;
    Tno* fim;
};

Queue* create_fila(){
    Queue* nova = malloc(sizeof(Queue));
    if(nova != NULL){
        nova->fim = NULL;
        nova->qty = 0;
    } return nova;
}
void destroy_fila(Queue* fila){

    while(!queue_empty(fila)){
        
    }
}
int enqueue_fila(Queue* fila, int data){
    Tno* novo = create_no_fila(data);
    if(novo==NULL) return 0;
    if(fila->fim == NULL){
        fila->fim = novo;
    }
    else{ 
        novo->prox = fila->fim->prox; //novo aponta para o inicio da fila
        fila->fim->prox = novo; //o "antigo" fim aponta para o "novo" fim
        fila->fim = novo; //move o fim antigo para o novo fim
    }
    fila->qty++;
    return 1;
}
int dequeue_fila(Queue* fila, int* data){
    if(queue_empty(fila)) return 0;
    Tno* oldBegin = fila->fim->prox;
    *data = oldBegin->data;
    fila->fim->prox = oldBegin->prox;
    free(oldBegin);
    fila->qty--;
    return 1;
}
int head_fila(Queue* fila, int* data){//acessa a informação do início da fila
    if(queue_empty(fila)) return 0;
    Tno* oldBegin = fila->fim->prox;
    *data = oldBegin->data;
    return 1;
}

int queue_full(Queue* fila){
    return 0; //"nunca" vai estar cheia
}
int queue_empty(Queue* fila){
    return fila->qty == 0; //retorna 1 se a fila estiver vazia
}
int queue_qty(Queue*);

//ex1

int reverse_fila(Queue* fila){
    int temp;
    Stack* aux = create();
    while(!queue_empty(fila)){//enquanto a fila não estiver vazia
        dequeue_fila(fila,&temp);//tira o elemento do inicio
        push(aux,temp);//passa o elemento para uma pilha aux
    }
    //agora os elementos da fila estão em ordem invertida dentro da pilha
    while(!empty(aux)){//enquanto a pilha não estiver vazia
        pop(aux,&temp);//tira o elemento do topo da pilha
        enqueue_fila(fila,temp);//adiciona o elemento na fila
    }
    destroy(aux);
    return 0;
}
