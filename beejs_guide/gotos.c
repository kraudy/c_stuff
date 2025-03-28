#include <stdio.h>

void test1(void){
  printf("One \n");
  printf("Two \n");

  goto skip_3;
  printf("Three \n");

skip_3:
  printf("Four \n");
}

int main(void){
  test1();
}
