#include <stdio.h>

struct car {
  char *name;
  float price;
  int speed;
};

int main(void){
  // This is a nice way of initializing
  struct car saturn = {.price=1600.99, .name="Saturn",  .speed=175};


}





