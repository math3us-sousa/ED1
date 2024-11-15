#include "Stack.h"
#include <stdlib.h>

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
    // ou return stack->inicio == NULL;
}
// Retorna a quantidade de elementos empilhados
int qty(Stack* stack){
    return stack->qty;
}
// Sempre retorna 0 para listas dinâmicas
int full(Stack* stack){
    return 0;
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
