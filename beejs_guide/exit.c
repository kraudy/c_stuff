#include <stdio.h>
#include <stdlib.h>

void on_exit_1(void){
  printf("Exit handler 1 called!\n");
}

int main(void){

  atexit(on_exit_1);

  puts("End");
  return 0;
}
