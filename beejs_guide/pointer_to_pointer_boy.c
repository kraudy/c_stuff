#include <stdio.h>

void test1(void){
  int x = 3490;
  void *p = &x;
  int *pint = p;

  printf("%d\n", *((int*)p)); 
  printf("%d\n", *pint); 
}

int main(void){
  test1();
}
