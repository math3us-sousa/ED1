#include <stdio.h>
#include "TCircList.h"

int main(){
    //Descomente o seguinte código quando implementar as funções da TCircList.h 
    
    TCircList* list = TCircList_create();
    int V[] = {1,2,3,4,5,6,7,8,9};
    for(int i = 0; i <9; i++)
        if(!TCircList_insert_begin(list,V[i]))
            printf("Nao pude inserir o valor V[%d]=%d\n",i,V[i]);
    TCircList_print(list);

    TCircList* list2 = TCircList_create();
    for(int i = 0; i <9; i++)
        if(!TCircList_insert_end(list2,V[i]))
            printf("Nao pude inserir o valor V[%d]=%d\n",i,V[i]);
    TCircList_print(list2);
    
    return 0;
}
