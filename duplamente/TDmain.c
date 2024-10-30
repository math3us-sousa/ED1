#include "TDLinkedList.h"
#include <stdio.h>

int main (void){
    TDLinkedList* lista1 = list_create();
    TDLinkedList* lista2 = list_create();
    for(int i = 1; i<=10; i++){
        insert_end(lista1, i);
    }
    insert_ordem(lista2, 0);
    insert_ordem(lista2, 4);
    insert_ordem(lista2, 3);
    insert_ordem(lista2, 1);
    insert_ordem(lista2, 5);
    print(lista1);
    printf("\n");
    print(lista2);
}
