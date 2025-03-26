#include <stdio.h>

void test1(void){
  int x = 3490;
  int *p = &x;
  int **q = &p;
  void *pvoid = &x;
  int *pint = pvoid;

  printf("%d\n", **q); 
  printf("%d\n", *((int*)pvoid)); 
  printf("%d\n", *pint); 
  puts("Show addresses");
  printf("%p\n", &x); 
  printf("%p\n", p); 
  printf("%p\n", &p); 
  printf("%p\n", &*q); 
}

int main(void){
  test1();
}
