#include <stdio.h>

enum {
  ONE=1,
  TWO=2
};

void test1(void){
  printf("%d %d\n", ONE, TWO);
}

int main(void){
  test1();
}
