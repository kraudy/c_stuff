#include <stdio.h>
#include <threads.h>

/* This is like the thread main */
int run(void *args){
  int *a = args;
  printf("THREAD: Running with arg %d\n", *a);
  return 12;
}

int main(void){
  thrd_t t;
  int arg = 3490;

  printf("Launching thread\n");

  thrd_create(&t, run, &arg);

  printf("Doing something while thread runs\n");

  int res;

  thrd_join(t, &res);
  printf("Thread exited with return value: %d\n", res);

}



