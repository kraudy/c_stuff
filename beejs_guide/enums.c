#include <stdio.h>

enum {
  ONE=1,
  TWO=2
};

enum {
  SHEEP,
  WHEAT,
  WOOD,
};

enum {
  x=2,
  y=2,
};

void test1(void){
  printf("%d %d\n", ONE, TWO);
  printf("%d %d %d\n", SHEEP, WHEAT, WOOD);
  printf("%d %d\n", x, y);
}

int main(void){
  test1();
}
