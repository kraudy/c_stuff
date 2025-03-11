#include <stdio.h>

int my_strlen(char *s);

int main(void){
  char *s = "Hello world!";
  printf("%d \n", my_strlen(s));  
}

int my_strlen(char *s){
  int count = 0;
  while (s[count] != '\0'){
    count ++;
  }
  return count;
}
