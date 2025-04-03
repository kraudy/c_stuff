#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main(int argc, char *argv[]){
  if(argc == 1){
    fprintf(stdout, "wgrep: searchterm [file ...]\n");
    return 1;
  }  

  char *line = NULL;
  size_t len = 0;
  if(argc == 2){
    getline(&line, &len, stdin);
    if (strstr(line, argv[2]) != NULL)
      fprintf(stdout, "%s",line);
  }

  free(line);

  return 0;
}
