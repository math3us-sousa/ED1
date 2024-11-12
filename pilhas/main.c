#include <stdio.h>
#include "Stack.h"

int main(){
    Stack* P1 = create();

    int vetor[] = {1,2,3,4,5,6,7,8,9,10,11,12};

    for(int i = 0; i<12; i++){
        if(!push(P1, vetor[i])){
            printf("Não foi possível adicionar o elemento vetor[%d] = %d\n", i, vetor[i]);
            printf("Overflow\n");
        }
    }
    int temp;
    while(pop(P1,&temp)){
        printf("%d,", temp);
    }
    destroy(P1);
    return 0;
}
