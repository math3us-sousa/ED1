#include "Stack.h"
#include "Stack.h"
#include "Queue.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct no{
    int info;
    struct no* prox;
}Tno;

struct stack{
    Tno* inicio;
    int qty;
};
// Função para criar um novo nó com o valor `info`
Tno* create_no(int info){
    Tno* novo = malloc(sizeof(Tno));
    if(novo!=NULL){
        novo->info = info;
        novo->prox = NULL;
    }return novo;
}
// Função para criar e inicializar uma nova pilha
Stack* create(){
    Stack* nova = malloc(sizeof(Stack));
    if(nova!=NULL){
        nova->inicio = NULL;
        nova->qty = 0;
    }return nova;
}
// Função para empilhar um elemento na pilha
int push(Stack* stack, int info){
    Tno* novo = create_no(info);
    if(novo==NULL) return 0;//overflow
    novo->prox = stack->inicio;
    stack->inicio = novo;
    stack->qty++;
    return 1;
}
// Função para desempilhar um elemento da pilha
int pop(Stack* stack, int* info){
    if(!empty(stack)){
        *info = stack->inicio->info;
        Tno* aux = stack->inicio;
        stack->inicio = stack->inicio->prox;
        stack->qty--;
        free(aux);
        return 1;
    }return 0;   
}
int head(Stack* stack, int* info){
    // Fala qual é a informação do elemento do topo da pilha
     if(!empty(stack)){
        *info = stack->inicio->info;
        return 1;
    }return 0;
}
// Função para liberar todos os elementos da pilha
void destroy(Stack* stack){
    while(!empty(stack)){
        Tno* aux = stack->inicio;
        stack->inicio = stack->inicio->prox;
        stack->qty--;
        free(aux);
    }
    free(stack);
}
// Verifica se a pilha está vazia
int empty(Stack* stack){
    return stack->qty == 0;
}
// Retorna a quantidade de elementos empilhados
int qty(Stack* stack){
    return stack->qty;
}
// Sempre retorna 0 para listas dinâmicas
int full(Stack* stack){
    return 0;
}
Stack* pilha_ajustada(Queue* filaPar, Queue* filaImpar) {
    Stack* Pilha = create(); // Cria a pilha
    if (Pilha == NULL) return NULL;

    int alterna = 0; // Variável para alternar entre as filas

    while (!queue_empty(filaImpar) || !queue_empty(filaPar)) {
        int temp;

        if (alterna % 2 == 0 && !queue_empty(filaImpar)) {
            // Processa a FILA ÍMPAR
            dequeue_fila(filaImpar, &temp);
            if (temp >= 0) {
                push(Pilha, temp); // Adiciona à pilha se positivo
            } else {
                pop(Pilha, &temp); // Remove da pilha se negativo
            }
        } else if (alterna % 2 == 1 && !queue_empty(filaPar)) {
            // Processa a FILA PAR
            dequeue_fila(filaPar, &temp);
            if (temp >= 0) {
                push(Pilha, temp); // Adiciona à pilha se positivo
            } else {
                pop(Pilha, &temp); // Remove da pilha se negativo
            }
        }

        alterna++; // Alterna entre FILA ÍMPAR e FILA PAR
    }

    return Pilha; // Retorna a pilha ajustada
}
void print_stack(Stack* Pilha){
    int item;
  while(pop(Pilha, &item))
    printf("%d,", item);
  putchar('\n');
}