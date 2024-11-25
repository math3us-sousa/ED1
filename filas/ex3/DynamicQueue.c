#include "Queue.h"
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

//ex3
int preenche_fila(Queue* fila1, Queue* fila2, Queue* fila3) {
    if (fila1 == NULL || fila2 == NULL || fila3 == NULL) return 0; 
    int temp1, temp2;
    int has_fila1, has_fila2;
    // Enquanto houver elementos em pelo menos uma das filas
    while (!queue_empty(fila1) || !queue_empty(fila2)) {
        has_fila1 = head_fila(fila1, &temp1); // Verifica e pega o elemento do início de fila1
        has_fila2 = head_fila(fila2, &temp2); // Verifica e pega o elemento do início de fila2

        if (has_fila1 && has_fila2) {
            // Ambas as filas têm elementos; compara e transfere o maior
            if (temp1 < temp2) {
                dequeue_fila(fila1, &temp1);
                enqueue_fila(fila3, temp1);
            } else {
                dequeue_fila(fila2, &temp2);
                enqueue_fila(fila3, temp2);
            }
        } else if (has_fila1) {
            // Apenas fila1 tem elementos
            dequeue_fila(fila1, &temp1);
            enqueue_fila(fila3, temp1);
        } else if (has_fila2) {
            // Apenas fila2 tem elementos
            dequeue_fila(fila2, &temp2);
            enqueue_fila(fila3, temp2);
        }
    }
    return 1; // Sucesso
}
