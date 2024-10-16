#include "CircEdmundo.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int soldado;
    struct no *next;
}Tno;

struct circ_list {
    Tno* fim;
};

Tno* CreateNode(int soldado){
    Tno* novo = malloc(sizeof(Tno));
    if(novo == NULL) return NULL;
    novo->soldado = soldado;
    novo->next = NULL;
    return novo;
}

TCircList* TCircList_create(){
    TCircList* list = malloc(sizeof(TCircList));
    if(list != NULL)
        list->fim = NULL;
    return list;
}

bool TCircList_insert_begin(TCircList* list, int soldado){
    Tno* novo = CreateNode(soldado);
    if(novo == NULL) return false;
    if(list->fim==NULL){
        list->fim = novo;
        novo->next = novo;
    }else{
        novo->next = list->fim->next;
        list->fim->next = novo;
    }return true;
}

void TCircList_print(TCircList* list){
    if(list->fim == NULL) return;
    Tno* aux = list->fim;
    do{
        aux = aux->next;
        printf("%d ",aux->soldado);
    }while(aux!=list->fim);
    printf("\n");
}

int TCircList_remove(TCircList* list, int soldado){
    if(list->fim == NULL) return -1;
    Tno* aux = list->fim;
    Tno* ant = NULL;
    do{
        ant = aux;
        aux = aux->next;
        if(aux->soldado == soldado){
            ant->next = aux->next;
            if(aux == list->fim){
                list->fim = ant;
            }
            free(aux);
            return 1;
        }
    }while(aux!=list->fim);
    return 0;
}
