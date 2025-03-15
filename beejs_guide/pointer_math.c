#include <stdio.h>

void move_index(void){
  int a[5] = {11, 22, 33, 44, 55};
  int *p;

  p = a;
  printf("%d\n", *p);
  printf("%d\n", p[1]);
  printf("%d\n", *(p + 1));
  printf("%p\n", (a+1));
  printf("%p\n", &p[1]);
  int *q;
  q = &p[1];
  printf("%d\n", *q);
  printf("%p\n", q);
  

}

int main(void){
  move_index();

}
