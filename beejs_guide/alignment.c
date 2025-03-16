#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
  char *p = aligned_alloc(64, 256); // 256 = 64*4

  //p = "Hello, world!";
  strcpy(p, "Hello, world!");
  printf("%s\n", p);

  free(p);
}

