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

void test2(void){
  int a = 5;
  int b;
  void *s = &a;
  void *d = &b;
  my_memcpy(d, s, sizeof(int));
  printf("%d\n", b);
}

struct foo{
  char a;
  int b;
};

void test3(void){
  struct foo x = {0x12, 0x12345678};
  unsigned  char *p =  (unsigned char*)&x;

  for (size_t i=0; i<sizeof x; i++){
    printf("%02X\n", p[i]);
  }

}

int main(void){
  test1();
  test2();
  test3();
}
