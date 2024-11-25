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

//ex2;
Queue* remove_negativo(Queue* fila) {
    if (fila == NULL) return NULL; // Verifica se a fila é válida

    Queue* aux = create_fila(); // Cria uma nova fila para armazenar os valores não negativos
    if (aux == NULL) return NULL; // Verifica se a nova fila foi criada com sucesso

    int temp;
    while (!queue_empty(fila)) { // Itera sobre todos os elementos da fila original
        dequeue_fila(fila, &temp); // Remove o elemento do início da fila
        if (temp >= 0) {           // Verifica se o elemento é não negativo
            enqueue_fila(aux, temp); // Adiciona o elemento à nova fila
        }
    }

    // Retorna a nova fila contendo apenas os elementos não negativos
    return aux;
}
