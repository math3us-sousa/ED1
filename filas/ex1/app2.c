#include <stdio.h>
#include "Queue.h"

int main(){
    int V[] = {0,1,2,3,4,5,6,7,8,9};
    Queue* fila = create_fila();

    for(int i = 0; i<10; i++)
        if(!enqueue_fila(fila,V[i]))
            printf("Não foi inserido V[%d]=%d.\n", i, V[i]);
    
    int temp;
    reverse_fila(fila);
    while(dequeue_fila(fila, &temp))
        printf("%d,", temp);
    printf("\n");
    return 0;
}
