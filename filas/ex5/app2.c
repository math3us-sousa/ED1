#include <stdio.h>
#include "Queue.h"

int main(){
    int V[] = {0,1,2,3,4,5,6,7,8,9};
    int V2[] = {10,11,12,13,14,15,16,17,18,19};
    Queue* fila = create_fila();
    Queue* fila2 = create_fila();

    for(int i = 0; i<10; i++)
        if(!enqueue_fila(fila,V[i]))
            printf("Não foi inserido V[%d]=%d.\n", i, V[i]);
    for(int i = 0; i<10; i++)
        if(!enqueue_fila(fila,V2[i]))
            printf("Não foi inserido V[%d]=%d.\n", i, V2[i]);
    
    concatenate(fila, fila2);
    int temp;
    while(dequeue_fila(fila, &temp))
        printf("%d,", temp);
    printf("\n");
    return 0;
}
