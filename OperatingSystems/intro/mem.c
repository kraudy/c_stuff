#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "common.h"

int main(int argc, char *argv[]){
  int *p = malloc(1 * sizeof(int));
  assert(p != NULL);
  printf("(%d) address pointe by p: %p\n", getpid(), p);

  // Asign value to address
  *p = 0;

  while (1) {
    Spin(1);
    *p = *p + 1;
    printf("(%d) p: %d\n", getpid(), *p);
  }

  free(p);

  return 0;

}
