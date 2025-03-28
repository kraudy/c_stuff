#include <stdio.h>

void test1(void){
  printf("One \n");
  printf("Two \n");

  goto skip_3;
  printf("Three \n");

skip_3:
  printf("Four \n");
}

// TCO Factorial
int factorial(int n, int a){
tco:
  if (n==0)
    return a;

  int next_n = n-1;
  int next_a = a*n;

  n = next_n;
  a = next_a;

  goto tco;
}

int main(void){
  test1();
  for(int i=0; i<8; i++){
    printf("%d! == %d\n", i, factorial(i, 1));
  }
}
