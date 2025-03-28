#include <stdio.h>
#include <stdlib.h>

#define ASSERT(c, m) \
do { \
    if (!(c)) { \
        fprintf(stderr, __FILE__ ":%d: assertion %s failed: %s\n", \
                        __LINE__, #c, m); \
        exit(1); \
    } \
} while(0)

void test3(void){
  int goats = 10;
  goats -= 100;
  ASSERT(goats > 0, "Goats must be more than 0");
}


int main(void){
  test3();

  puts("End");
  return 0;
}
