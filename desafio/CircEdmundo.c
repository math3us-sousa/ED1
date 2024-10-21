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
bool List_remove(Sorteio* list, int soldado) {
    if (list->fim == NULL) return false;
    Tno* aux = list->fim->prox;
    Tno* temp = list->fim;
    do {
        if (aux->soldado == soldado) {
            temp->prox = aux->prox;
            if (aux == list->fim) {
                list->fim = (aux == temp) ? NULL : temp;
            }
            free(aux);
            return true;
        }
        temp = aux;
        aux = aux->prox;
    } while (aux != list->fim->prox);
    return false;
}
int list_size(Sorteio* lista) {
    if (lista == NULL || lista->fim == NULL) {
        return 0;  // Lista vazia
    }

    Tno* atual = lista->fim->prox;  // Começamos no primeiro nó
    int count = 1;  // Contamos o último nó (fim)

    // Iteramos até retornar ao nó 'fim', ou seja, quando voltamos ao início
    while (atual != lista->fim) {
        atual = atual->prox;
        count++;
    }

    return count;
}
int get_soldado_at(Sorteio* list, int pos) {
    if (list == NULL || list->fim == NULL) return -1;  // Lista vazia ou posição inválida
    
    Tno* aux = list->fim->prox;  // Começamos no primeiro nó
    for (int i = 0; i < pos; i++) {
        aux = aux->prox;  // Percorre até a posição desejada
    }
    
    return aux->soldado;  // Retorna o valor do soldado na posição
}



