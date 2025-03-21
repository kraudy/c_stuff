#include <stdio.h>

#define HAPPY

void test1(void){
  #ifndef HAPPY
    puts("not happy");
  #else 
    puts("happy");
  #endif
}

#define FACTOR 1

void test2(void){
  #if FACTOR == 1
    puts("factor 1");
  #elif FACTOR == 0
    puts("factor 0");
  #endif
}

int main(void){
  test1();
  test2();
}
