#include "LinkedList.h"
#include <stdio.h>

int main(){
    TLinkedList* list = TLinkedList_create();
    TLinkedList* listDois = TLinkedList_create();
    int V[] = {7, 5, 1};
    for(int i=0; i<3; i++){
        if(!TLinkedList_insert_begin(list, V[i])){
            printf("Erro ao inserir %d\n", V[i]);
        }
        TLinkedList_insert_final(listDois, V[i]);
    }
    TLinkedList_insert_begin(list, 0);
    TLinkedList_print(list);
    TLinkedList_print(listDois);
    return 0;
}
