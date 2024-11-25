#include <stdio.h>
#include "Queue.h"

int main(){
    int V[] = {0,1,2,5,6,7,8,9};
    int V2[] = {-1,3,4,10};
    Queue* fila1 = create_fila();
    Queue* fila2 = create_fila();
    Queue* fila3 = create_fila();

    for(int i = 0; i<8; i++)
        if(!enqueue_fila(fila1,V[i]))
            printf("Não foi inserido V[%d]=%d.\n", i, V[i]);
    for(int i = 0; i<4; i++)
        if(!enqueue_fila(fila2,V2[i]))
            printf("Não foi inserido V[%d]=%d.\n", i, V2[i]);

    int temp;
    preenche_fila(fila1,fila2,fila3);
    while(dequeue_fila(fila3, &temp))
        printf("%d,", temp);
    printf("\n");
    return 0;
}
