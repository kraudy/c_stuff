#include <stdio.h>
#include <stdbool.h>

void pointers(int* i){
  int *p;
  char *s = "Hello, world !";

  p = i;

  printf("%s i  = %d and f = %f \n", s, i);
  printf("i addres: %p \n", (void *) p);
  printf("%zu\n", sizeof p); //size of pointer
  printf("%zu\n", sizeof *p);// size of int
}

void arrays(void){
  float f[4]; 

}

void bool_stuff(void){
  bool x = true;
  if (x) {
    printf("x is true \n");
  }
}

int main (void){
  int i = 2;   


}
