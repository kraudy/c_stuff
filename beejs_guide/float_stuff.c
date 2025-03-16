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

int main(void){
  wrong_add();
}
