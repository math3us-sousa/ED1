#include "complexo.h"
#include <stdlib.h>
#include <stdio.h>

struct _complexo {
    float real;
    float imaginario;
};

Complexo* Complexo_create(float x, float y) {
    Complexo* novo = (Complexo*) malloc(sizeof(Complexo));
    if (novo != NULL) {
        novo->real = x;
        novo->imaginario = y;
    }
    return novo;
}

void Complexo_destroy(Complexo* c) {
    if (c != NULL) {
        free(c);
    }
}

Complexo* Complexo_soma(Complexo* c1, Complexo* c2) {
    if (c1 != NULL && c2 != NULL) {
        return Complexo_create(c1->real + c2->real, c1->imaginario + c2->imaginario);
    }
    return NULL;
}

Complexo* Complexo_subtrai(Complexo* c1, Complexo* c2) {
    if (c1 != NULL && c2 != NULL) {
        return Complexo_create(c1->real - c2->real, c1->imaginario - c2->imaginario);
    }
    return NULL;
}

void Complexo_print(Complexo* c) {
    if (c != NULL) {
        printf("(%.2f + %.2fi)\n", c->real, c->imaginario);
    }
}
