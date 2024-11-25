#include "Queue.h"
#include <stdlib.h>
#include <stdio.h>
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
    int temp;
    while(!queue_empty(fila)){
        dequeue_fila(fila,&temp);
        printf("Dado removido: %d", temp);
    }
    free(fila);
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
// está dando erro:
/*int dequeue_fila(Queue* fila, int* data){
    if(queue_empty(fila)) return 0;
    Tno* oldBegin = fila->fim->prox;
    *data = oldBegin->data;
    fila->fim->prox = oldBegin->prox;
    free(oldBegin);
    fila->qty--;
    return 1;
}*/
int dequeue_fila(Queue* fila, int* data){
    if(queue_empty(fila) || fila == NULL) return 0;
    Tno* oldBegin = fila->fim->prox;
    *data = oldBegin->data;
    if (fila->fim == oldBegin) { // Caso a fila tenha apenas um elemento
        fila->fim = NULL;
    } else {
        fila->fim->prox = oldBegin->prox; // Atualiza o próximo do último nó
    }
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

//ex6 (retorna qty de par)
int qty_par(Queue* fila){
    int temp, qtd=0;
    Queue* aux = create_fila(); // Cria uma fila auxiliar
    // Transferir os elementos de fila para aux e contar os pares
    while (!queue_empty(fila)) {
        dequeue_fila(fila, &temp);
        if(temp % 2 == 0){
            qtd++;
        }
        enqueue_fila(aux, temp); // Recoloca o elemento na fila auxiliar
    }
    // Recoloca os elementos de aux de volta em fila
    while (!queue_empty(aux)) {
        dequeue_fila(aux, &temp);
        enqueue_fila(fila, temp);
    }
    return qtd;
}