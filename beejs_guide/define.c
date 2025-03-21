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

void test3(void){
  #if 0
    puts("Shall never be known");
  #endif
  puts("Pedestrian text");
}

void test4(void){
  printf("This function: %s\n", __func__);
  printf("This file: %s\n", __FILE__);
  printf("This line: %d\n", __LINE__);
  printf("Compiled on: %s %s\n", __DATE__, __TIME__);
  printf("C Version: %ld\n", __STDC_VERSION__);
}

#define SQR(x) x * x
void test5(void){
  printf("%d\n", SQR(12)); 
  printf("%d\n", SQR(3 + 4)); // 19, bad! 
}

int main(void){
  test1();
  test2();
  test3();
  test4();
  test5();
}
