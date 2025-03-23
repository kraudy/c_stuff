#include <stdio.h>

union foo{
  int a, b, c, d, e, f;
  float g, h;
  char i, j, k, l;
};

union foo2{
  float b;
  short a;
};

void test1(void){
  printf("Size union: %zu\n", sizeof(union foo));
  printf("Size union: %d\n", sizeof(union foo));

  union foo2 x2;
  x2.b = 3.1573;
  printf("%f\n", x2.b);
  printf("%d\n", x2.a);

  union foo x;

  int *foo_int_p = (int *)&x;
  float *foo_float_p = (float *)&x;

  x.a = 12;
  printf("%d\n", x.a);
  printf("%d\n", *foo_int_p);

  x.g = 3.141592;
  printf("%f\n", x.g);
  printf("%f\n", *foo_float_p);
}

int main(void){
  test1();
}
