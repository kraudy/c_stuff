#include <stdio.h>
#include <stdbool.h>

int main (void){
  bool x = true;
  int i = 2; float f = 3.14;
  int *p;
  char *s = "Hello, world !";

  p = &i;

  printf("%s i  = %d and f = %f \n", s, i, f);
  printf("i addres: %p \n", (void *) p);
  printf("%zu\n", sizeof p); //size of pointer
  printf("%zu\n", sizeof *p);// size of int
  if (x) {
    printf("x is true \n");
  }

}
