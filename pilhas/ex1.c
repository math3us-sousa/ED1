#include "Stack.h"
#include <stdio.h>
#include <string.h>

int main(){
  char string[1024];
  fgets(string,1024,stdin);
  puts(string);
  Stack* stack = create();

  for(int i = 0; i<strlen(string);i++){
    if(string[i] == '\n')
      break;
    if(string[i]==' ' || string[i]=='.')
      print_stack(stack);
    else
  }


  return 0;
}



/*função no .h
void print_stack(Stack* stack){
  char item;
  while(pop(stack, &item))
    printf("%c", item);
  putchar(' ');
  }

*/
