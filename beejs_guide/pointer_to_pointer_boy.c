#include <stdio.h>

void test1(void){
  int x = 3490;
  int *p = &x;
  int **q = &p;
  void *pvoid = &x;
  int *pint = pvoid;

  printf("%d\n", **q); 
  printf("%d\n", *((int*)pvoid)); 
  printf("%d\n", *pint); 
  puts("Show addresses");
  printf("%p\n", &x); 
  printf("%p\n", p); 
  printf("%p\n", &p); 
  printf("%p\n", q); 
}

void* my_memcpy(void *dest, const void *src, size_t n){
  const unsigned char *s = src;
  unsigned char *d = dest;

  while (n-- > 0)
    *d++ = *s++;

  return dest;
}

int main(void){
  test1();
  int a = 5;
  void *s = a;
  void *d;
  my_memcpy(d, s, sizeof(int));
}
