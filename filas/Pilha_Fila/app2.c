#include <stdio.h>
#include "Queue.h"
#include "Stack.h"

int main(){
    int numero = -1;
    Queue* filaPar = create_fila();
    Queue* filaImpar = create_fila();
    Stack* Pilha = create();

    while(numero!=0){
        scanf("%d", &numero);
        if(numero == 0) break;
        if(numero % 2 == 0){
            if(!enqueue_fila(filaPar,numero))
            printf("Não foi inserido o número %d.\n",numero);
        }else{
            if(!enqueue_fila(filaImpar,numero))
                printf("Não foi inserido o número %d.\n",numero);
        }
        
    }
    Pilha = pilha_ajustada(filaPar,filaImpar);
    print_stack(Pilha);
    return 0;
}
