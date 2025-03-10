#include <stdio.h>
#include <stdbool.h>

void bool_stuff(void){
  puts("\nbool_stuf");
  bool x = true;
  if (x) {
    printf("x is true \n");
  }
}

void pointers(int* i){
  puts("\npointers");
  int *p;
  char *s = "Hello, world !";

  p = i;

  printf("%s i  = %d  \n", s, *i);
  printf("i addres: %p \n", (void *) p);
  printf("%zu\n", sizeof p); //size of pointer
  printf("%zu\n", sizeof *p);// size of int
}

void arrays(void){
  puts("\narrays");
  float f[4]; 

}


int main (void){
  int i = 2;   

  bool_stuff();
  pointers(&i);
  arrays();

}
