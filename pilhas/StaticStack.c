#include "Stack.h"
#include <stdlib.h>
#define MAX 10

struct stack{
    int index;//Índice do elemento do topo da pilha
    int info[MAX];// Informação do topo da pilha
};

Stack* create(){
    Stack* nova = malloc(sizeof(Stack));
    //Cria um pilha nova
    if(nova!=NULL){
        nova->index= -1;
    }
    return nova;
}
int push(Stack* stack, int info){
    if(!full(stack)){
        // Adiciona um elemento no topo da pilha
        stack->index++;
        stack->info[stack->index] = info;
        return 1;
    }return 0; //overflow
}
int pop(Stack* stack, int* info){
    // Remove o elemto do topo da pilha
    if(!empty(stack)){
        *info = stack->info[stack->index];
        stack->index--;
        return 1;
    }return 0; //undeflow
}
int head(Stack* stack, int* info){
    // Fala qual é a informação do elemento do topo da pilha
     if(!empty(stack)){
        *info = stack->info[stack->index];
        return 1;
    }return 0;
}
void destroy(Stack* stack){
    // Libera memória, apaga a pilha
    free(stack);
}
int full(Stack* stack){
    // Retorna 1 se a pilha está cheia, 0 caso contrário
    return stack->index == MAX-1;
}
int empty(Stack* stack){
    // Retorna 1 se a pilha está vazia, 0 caso contrário
    return stack->index == -1;
}
int qty(Stack* stack){
    // Retorna a quantidade de elementos
    return stack->index + 1;
}
void print_stack(Stack* stack) {
    int item;
    Stack* aux = create();
    // Move os itens da pilha original para a auxiliar
    while (!empty(stack)) {
        pop(stack, &item);
        push(aux, item); // Copia para auxiliar
    }
    // Imprime os itens e restaura a pilha original
    while (!empty(aux)) {
        pop(aux, &item);
        printf("%d ", item); // Imprime o item
        push(stack, item);   // Restaura o item para a pilha original
    }
    putchar('\n');
    destroy(aux); // Libera a memória da pilha auxiliar
}
