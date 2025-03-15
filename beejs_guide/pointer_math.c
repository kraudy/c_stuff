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

void* my_memcpy(void *dest, void *src, int n_byte){
  /* 
  Convert void pointer to char, this help us to defference it and
  conveniently a char = 1 byte so anything can be coppied
  */
  char *s = src, *d = dest;

  while(n_byte)
    *d++ = *s++;
  
  return dest;
  
}

void resize_pointer(void){
  float *p = malloc(20 * sizeof *p);
  for (int i=0; i<20; i++)
    *(p + i) = i;
    //*(p + i) = *(&i);

  float *new_p;
  if((new_p = realloc(p, 40 * sizeof *p)) == NULL){
    puts("Null pointer");
  }

  p = new_p;

  for (int i=20; i<40; i++)
    *(p + i) = i;

  for (int i=0; i<40; i++)
    printf("%f\n", *(p + i));

  free(p);
}

int main(void){
  move_index();
  resize_pointer();
}
