#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void* aligned_realloc(void *ptr, size_t old_size, size_t alignment, size_t size){
  char *new_ptr = aligned_alloc(alignment, size);
  if (new_ptr == NULL)
    return NULL;

  size_t copy_size = old_size < size? old_size : size;  

  if(ptr != NULL)
    memcpy(new_ptr, ptr, copy_size);

  free(ptr);

  return new_ptr;
}

void try_aligned(void){
  char *p = aligned_alloc(64, 256); // 256 = 64*4

  //p = "Hello, world!";
  strcpy(p, "Hello, world!");
  printf("%s\n", p);

  free(p);
}


int main(void){
    try_aligned();
}

