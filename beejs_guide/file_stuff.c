#include <stdio.h>

int main(void){
  FILE *fp;
  char s[1024];
  int linecount = 0;

  fp = fopen("hello.txt", "r");
  if (fp == NULL){
    puts("fp null!");
    return 1;
  }

  while((fgets(s, sizeof s, fp)) != NULL)
    printf("%d: %s", ++linecount, s);
  puts("");

  fclose(fp);

}
