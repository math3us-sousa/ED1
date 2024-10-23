#include "CircEdmundo.h"
#include <stdio.h>

int main() {
    Sorteio* lista1 = list_create();
    int n;
    int M;
    int i = 0;
    

    printf("Qual o número n? ");
    scanf("%d", &n);
    printf("Qual o número M? ");
    scanf("%d", &M); 
    for (int i = 0; i < n; i++) {
        insert_begin(lista1, i+1);
    }    
    List_remove(lista1, M);
    
    printf("O último soldado sobrevivente é: ");
    print(lista1); 
    
    return 0;
}
