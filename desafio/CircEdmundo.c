#include "CircEdmundo.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct no {
    int soldado;
    struct no *prox;
} Tno;

struct circular {
    Tno* fim;
    unsigned int qty;
};
Tno* CreateNo(int soldado) {
    Tno* novo = malloc(sizeof(Tno));
    if (novo != NULL) {
        novo->soldado = soldado;
        novo->prox = NULL;
    }
    return novo;
}
Sorteio* list_create() {
    Sorteio* nova = malloc(sizeof(Sorteio));
    if (nova == NULL) return NULL;
    nova->fim = NULL;
    nova->qty = 0;
    return nova;
}
bool insert_begin(Sorteio* list, int soldado) {
    Tno* novo = CreateNo(soldado);
    if (novo == NULL) return false;
    if (list->fim == NULL) {
        list->fim = novo;
        novo->prox = novo;
    } else {
        novo->prox = list->fim->prox;
        list->fim->prox = novo;
    }
    list->qty++;
    return true;
}
void print(Sorteio* list) {
    if (list->fim == NULL) return;
    Tno* aux = list->fim->prox;
    do {
        printf(" Soldado %d -> ", aux->soldado);
        aux = aux->prox;
    } while (aux != list->fim->prox);
    putchar('\n');
}
bool List_remove(Sorteio* list, int M) {
    if (list->fim == NULL) return false;
    while(list->qty > 1){
        Tno* aux = list->fim;
        for(int i=1; i<M;i++){
            aux = aux->prox;
        }   
        Tno* target = aux->prox;
        aux->prox = target->prox;
        free(target);
        list->fim = aux->prox;
        list->qty--;
    }
    return false;
}
