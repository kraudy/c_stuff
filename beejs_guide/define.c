#include <stdio.h>

#define HAPPY

int main(void){
  #ifndef HAPPY
    puts("not happy");
  #else 
    puts("happy");
  #endif
}
