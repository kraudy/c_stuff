#include <stdio.h>
#include <stdlib.h>

void on_exit_1(void){
  printf("Exit handler 1 called!\n");
}

void on_exit_2(void){
  printf("Exit handler 2 called!\n");
}

void test1(void){
  atexit(on_exit_1);
  atexit(on_exit_2);
}

void on_quick_exit_1(void){
  printf("Quick exit handler\n");
}

void test2(void){
  at_quick_exit(on_quick_exit_1);
}

int main(void){
  //test1();
  test2();

  puts("End");
  return 0;
}
