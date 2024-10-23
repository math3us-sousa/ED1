#include "TDLinkedList.h"
#include <stdio.h>
int main(){
    TDLinkedList* lista1 = TDLinkedList_Create();
    for(int i = 0; i <= 10; i++){
        if(!TDLinkedList_insert_end(lista1, i))
            printf("Erro ao inserir %d\n", i);
    }
    TDLinkedList_print(lista1);
    TDLinkedList_print_reverse(lista1);
}
