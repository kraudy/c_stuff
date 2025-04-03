#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int find_file(FILE **fd, char *name){
  if ((*fd = fopen(name, "r")) == NULL)
    return 1;
  
  return 0;
}

int main(int argc, char *argv[]){
  if(argc == 1){
    fprintf(stdout, "wgrep: searchterm [file ...]\n");
    return 1;
  }  

  char *line = NULL;
  size_t len = 0;
  if(argc == 2){
    getline(&line, &len, stdin);
    if (strstr(line, argv[1]) != NULL)
      fprintf(stdout, "%s",line);
  }

  for (int i = 2; i<argc; i++){
    FILE *fd = NULL;
    if(find_file(&fd, argv[i])){
      fprintf(stdout, "wgrep: cannot open file\n");
      return 1;
    }

    while((getline(&line, &len, fd)) != -1)
      if ((strstr(line, argv[1])) != NULL)
        fprintf(stdout, "%s", line);
        
    fclose(fd);
  }

  free(line);

  return 0;
}
