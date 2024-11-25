#include <stdio.h>
#include "Queue.h"

int main(){
    int V[] = {0,1,2,3,4,5,6,7,8,9};
    int V2[] = {10,11,12,13,14,15,16,17,18,19}; 
    int temp;
    Queue* fila = create_fila();
    Queue* fila2 = create_fila();
    Queue* fila3 = create_fila();
    for(int i = 0; i<10; i++)
        if(!enqueue_fila(fila,V[i]))
            printf("Não foi inserido V[%d]=%d.\n", i, V[i]);
    for(int i = 0; i<10; i++)
        if(!enqueue_fila(fila2,V2[i]))
            printf("Não foi inserido V[%d]=%d.\n", i, V2[i]);

    print(fila);
    print(fila2);
    fila3 = intercala_fila(fila, fila2);
    print(fila3);
    return 0;
}
