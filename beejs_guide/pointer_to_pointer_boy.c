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

  puts("Foo repre");
  for (size_t i=0; i<sizeof x; i++){
    printf("%p | %02X \n", &p[i], p[i]);
  }
  puts("");

  int a = 5;
  unsigned char *pa = &a;
  puts("Int repre");
  for (size_t i=0; i<sizeof(int); i++){
    printf("%p | %02X \n", &pa[i], pa[i]);
  }
  puts("");

}

void print_int(int n){
  printf("%d\n", n);
}

void test4(){
  void (*p)(int);
  p = print_int;
  p(1234);
}

int add(int a, int b){
  return a + b;
}

int mult(int a, int b){
  return a * b;
}

void print_math(int (*op)(int, int), int x, int y){
  int result = op(x, y);
  printf("%d\n",result);
}

void test5(void){
  puts("Function as param");
  print_math(add, 5, 7);
  print_math(mult, 5, 7);
}

int main(void){
  test1();
  test2();
  test3();
  test4();
  test5();
}