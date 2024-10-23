#include "TDLinkedList.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct no{
    int data;
    struct no *next;
    struct no *prev;
}TNo;

struct _tdlinked_list {
    TNo *inicio;
    TNo *fim;
};

TNo* TNo_create(int data){
    TNo* novo = malloc(sizeof(TNo));
    if(novo != NULL){
        novo->data = data;
        novo->next = NULL;
        novo->prev = NULL;
    }
    return novo;
}
TDLinkedList* TDLinkedList_Create(){
    TDLinkedList* nova = malloc(sizeof(TDLinkedList));
    if(nova == NULL) {
        nova->inicio = NULL;
        nova->fim = NULL;
    }
    return nova;
}

bool TDLinkedList_insert_end(TDLinkedList* list, int data){
    TNo* novo = TNo_create(data);
    if(novo == NULL) return false;
    if(list->inicio == NULL){
        list->inicio = novo;
        list->fim = novo;
    } else {
        list->fim->next = novo;
        novo->prev = list->fim;
        list->fim = novo;
    }
    return true;
}
void TDLinkedList_print(TDLinkedList* list){
    TNo* aux = list->inicio;
    printf("Print do inicio ao fim: ");
    while(aux != NULL){
        printf("%d ", aux->data);
        aux = aux->next;
    }
    printf("\n");
}
void TDLinkedList_print_reverse(TDLinkedList* list){
    TNo* aux = list->fim;
    printf("Print do fim ao início: ");
    while(aux != NULL){
        printf("%d ", aux->data);
        aux = aux->prev;
    }
    printf("\n");
}
