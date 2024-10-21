#include "CircEdmundo.h"
#include <stdio.h>

int main() {
    Sorteio* lista1 = list_create();
    int n;
    int vetor[n];
    int M;
    int i = 0;
    

    printf("Qual o número n? ");
    scanf("%d", &n);
    printf("Qual o número M? ");
    scanf("%d", &M); 

    for (int i = 0; i < n; i++) {
        vetor[i] = i + 1; 
        insert_begin(lista1, vetor[i]);
    }    
    while (list_size(lista1) > 1) {  
        print(lista1);  

        i = (i + M - 1) % list_size(lista1);
        int soldado = get_soldado_at(lista1, i);  
        List_remove(lista1, soldado);
    }
    
    printf("O último soldado sobrevivente é: ");
    print(lista1); 
    
    return 0;
}
