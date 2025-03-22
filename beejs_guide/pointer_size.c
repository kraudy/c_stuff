#include <stdio.h>
#include <stdlib.h>

void test1(void){
  void *p = malloc(1 * sizeof(int));

  char *cp = p;
  int  *ip = p;

  *cp = 'H';
  
  printf("%c\n", *cp);
  printf("%d\n", *ip);
  printf("%p\n", cp);
  printf("%p\n", ip);
  printf("%x\n", *ip);

  free(p);
}

int main(void){
  test1();
}
