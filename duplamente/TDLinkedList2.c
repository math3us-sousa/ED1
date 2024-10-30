#include <stdio.h>
#include <stdlib.h>
#include "TDLinkedList.h"
#include <stdbool.h>

typedef struct no{
    int data;
    struct no *prox;
    struct no *ant;
}Tno;

struct _tdlink{
    Tno* inicio;
    Tno* fim;
};

Tno* no_create(int data){
    Tno* novo = malloc(sizeof(Tno));
    if(novo != NULL){
        novo->data = data;
        novo->ant = NULL;
        novo->prox = NULL;
    }
}

TDLinkedList* list_create(){
    TDLinkedList* nova = malloc(sizeof(TDLinkedList));
    if(nova!=NULL){
        nova->fim = NULL;
        nova->inicio = NULL;
    }
    return nova;
}
bool insert_end(TDLinkedList* list, int data){
    Tno* novo = no_create(data);
    if(novo==NULL)return false;

    if(list->inicio == NULL){
        list->inicio = novo;
        list->fim = novo;
    }
    else{
        list->fim->prox = novo;
        novo->ant = list->fim;
        list->fim = novo;
    }
    return true;

}
void print(TDLinkedList* list){
    Tno* aux = list->inicio;
    do{
        printf("[%d]->", aux->data);
        aux = aux->prox;
    }while(aux != NULL);
}
bool insert_ordem(TDLinkedList* list, int data) {
    Tno* novo = no_create(data);
    if (novo == NULL) return false;

    if (list->inicio == NULL) {  
        list->inicio = novo;
        list->fim = novo;
    } else {
        Tno* aux = list->inicio;

        // Encontrar a posição correta para inserção
        while (aux != NULL && aux->data < data) {
            aux = aux->prox;
        }

        if (aux == list->inicio) { 
            novo->prox = list->inicio;
            list->inicio->ant = novo;
            list->inicio = novo;
        } else if (aux == NULL) {  
            novo->ant = list->fim;
            list->fim->prox = novo;
            list->fim = novo;
        } else {  
            Tno* temp = aux->ant;
            temp->prox = novo;
            novo->ant = temp;
            novo->prox = aux;
            aux->ant = novo;
        }
    }
    return true;
}
