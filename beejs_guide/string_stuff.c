#include <stdio.h>
#include <string.h>

int my_strlen(char *s);
void str_copy(void);

int main(void){
  char *s = "Hello world!";
  printf("%d \n", my_strlen(s));  

  str_copy();
}

void str_copy(void){
  char s[] = "Hello world";
  char t[100];
  strcpy(t, s);
  t[0] = 'z';
  printf("%s \n",s);
  printf("%s \n",t);
}

int my_strlen(char *s){
  int count = 0;
  while (s[count] != '\0'){
    count ++;
  }
  return count;
}
