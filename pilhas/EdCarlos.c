#include "Stack.h"
#include <stdlib.h>
#include <stdio.h>
#define MAX 10

struct stack{
    int index;//Índice do elemento do topo da pilha
    int id[MAX];// Informação do topo da pilha -> id do carro
};

Stack* create(){
    Stack* nova = malloc(sizeof(Stack));
    //Cria um pilha nova
    if(nova!=NULL){
        nova->index= -1;
    }
    return nova;
}
int push(Stack* stack, int id){
    if(!full(stack)){
        // Adiciona um elemento no topo da pilha
        stack->index++;
        stack->id[stack->index] = id;
        return 1;
    }return 0; //overflow
}
int pop(Stack* stack, int* id){
    // Remove o elemento do topo da pilha
    if(!empty(stack)){
        *id = stack->id[stack->index];
        stack->index--;
        return 1;
    }return 0; //undeflow
}
int head(Stack* stack, int* id){
    // Fala qual é a informação do elemento do topo da pilha
     if(!empty(stack)){
        *id = stack->id[stack->index];
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
int remover_carro(Stack* st1, Stack* st2, int id) {
    int temp_id;
    int encontrado = 0;
    // Move carros de st1 para st2 até encontrar o carro desejado
    while (!empty(st1)) {
        pop(st1, &temp_id);
        if (temp_id == id) {
            encontrado = 1; // Encontrou o carro
            break;          // Remove e sai do loop
        }
        push(st2, temp_id); // Move para st2
    }
    // Se o carro não foi encontrado
    if (!encontrado) {
        printf("Carro com ID %d não encontrado.", id);
    }
    // Move os carros de volta de st2 para st1
    while (!empty(st2)) {
        pop(st2, &temp_id);
        push(st1, temp_id);
    }
    return encontrado; // Retorna 1 se removeu o carro, 0 se não encontrou
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

