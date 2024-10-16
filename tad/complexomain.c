#include "complexo.h"
#include <stdio.h>

int main() {
    // Criando dois números complexos
    Complexo* c1 = Complexo_create(3.0, 4.0);
    Complexo* c2 = Complexo_create(1.0, 2.0);

    // Exibindo os números criados
    printf("Número complexo 1: ");
    Complexo_print(c1);

    printf("Número complexo 2: ");
    Complexo_print(c2);

    // Somando os dois números complexos
    Complexo* soma = Complexo_soma(c1, c2);
    printf("Soma: ");
    Complexo_print(soma);

    // Subtraindo os dois números complexos
    Complexo* subtracao = Complexo_subtrai(c1, c2);
    printf("Subtração: ");
    Complexo_print(subtracao);

    // Liberando a memória dos números complexos
    Complexo_destroy(c1);
    Complexo_destroy(c2);
    Complexo_destroy(soma);
    Complexo_destroy(subtracao);

    return 0;
}
