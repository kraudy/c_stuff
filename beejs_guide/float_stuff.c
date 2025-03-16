#include <stdio.h>
#include <float.h>


void wrong_add(void){
  float f = 3.14159f;
  float g = 0.00000265358f;
  printf("%.5f\n", f);
  printf("%.11f\n", g);

  f += g; //Adding stuff would give %.11f presicion needed
  printf("%.11f\n"), f;

}

void some_double_stuff(void){
  printf("\nmore_float_stuff\n");
  double x = 0.12345678901234500;
  double y = 0.00000000000000060;
  printf("%.11f\n", x);
  printf("%.11f\n", y);

}


int main(void){
  wrong_add();
  some_double_stuff();

}
