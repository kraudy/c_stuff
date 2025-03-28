#include <stdio.h>
#include <signal.h>

void test1(void){
  char s[1024];
  signal(SIGINT, SIG_IGN);
  printf("Hit ^C, hit enter \n");
  fgets(s, sizeof s, stdin);
}

int main(void){
  test1();

}
