#ifndef COMPLEXO_H
#define COMPLEXO_H

typedef struct _complexo Complexo;

/**
 * Cria um número complexo com parte real x e parte imaginária y
 * @param float x - parte real
 * @param float y - parte imaginária
 * @return Complexo* - ponteiro para o novo número complexo criado
 */
Complexo* Complexo_create(float x, float y);

/**
 * Destrói (libera a memória) de um número complexo
 * @param Complexo* - ponteiro para o número complexo a ser destruído
 */
void Complexo_destroy(Complexo*);

/**
 * Soma dois números complexos
 * @param Complexo* c1 - primeiro número complexo
 * @param Complexo* c2 - segundo número complexo
 * @return Complexo* - resultado da soma (novo número complexo)
 */
Complexo* Complexo_soma(Complexo* c1, Complexo* c2);

/**
 * Subtrai dois números complexos
 * @param Complexo* c1 - primeiro número complexo
 * @param Complexo* c2 - segundo número complexo
 * @return Complexo* - resultado da subtração (novo número complexo)
 */
Complexo* Complexo_subtrai(Complexo* c1, Complexo* c2);

/**
 * Imprime um número complexo no formato (x + yi)
 * @param Complexo* - número complexo a ser impresso
 */
void Complexo_print(Complexo*);


#endif
