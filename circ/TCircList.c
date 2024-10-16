#include "TCircList.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct no{
    int info;
    struct no *next;
}Tno;

struct circ_list {
    Tno* inicio;
};

Tno* CreateNode(int info){
    Tno* novo = malloc(sizeof(Tno));
    if(novo == NULL) return NULL;
    novo->info = info;
    novo->next = NULL;
    return novo;
}

TCircList* TCircList_create(){
    TCircList* list = malloc(sizeof(TCircList));
    if(list != NULL)
        list->inicio = NULL;
    return list;
}

bool TCircList_insert_begin(TCircList* list, int info){
    Tno* novo = CreateNode(info);
    if(novo == NULL) return false;
    if(list->inicio==NULL){
        list->inicio = novo;
        novo->next = novo;
    }else{
        Tno* aux = list->inicio;
        do{
            aux = aux->next;
        }while(aux->next!=list->inicio);
        aux->next = novo;
        novo->next = list->inicio;
        list->inicio = novo;   
    }return true;
    
}
bool TCircList_insert_end(TCircList* list, int info){
    Tno* novo = CreateNode(info);
    if(novo == NULL) return false;
    if(list->inicio==NULL){
        list->inicio = novo;
        novo->next = novo;
    }else{
        Tno* aux = list->inicio;
        do{
            aux = aux->next;
        }while(aux->next!=list->inicio);
        aux->next = novo;
        novo->next = list->inicio;
    }return true;
}

void TCircList_print(TCircList* list){
    if(list->inicio == NULL) return;
    Tno* aux = list->inicio;
    do{
        if(aux!=NULL){
            printf("%d ",aux->info);
            aux = aux->next;
        }
    }while(aux!=list->inicio);
    putchar('\n');
}

