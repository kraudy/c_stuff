#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int find_file(FILE **fd, char *name){
  if((*fd = fopen(name, "rb")) == NULL){
    return 1;
  }
  return 0;
}

int main(int argc, char *argv[]){
  if (argc < 2){
    fprintf(stdout, "wunzip: file1 [file2 ...]\n");
    return 1;
  }

  char current_read = -1;
  int count = 0;
  
  char *line = NULL;
  char *buffer = NULL; 

  size_t line_size = 0;
  size_t buffer_size = 0;
  /* just multiply each read by 5 bytes since we are usin RLE*/
  for (int i=1; i<argc; i++){
    FILE *fd;
    if(find_file(&fd, argv[i])){
      return 1;
    }

    int c_read;

    while(getline(&line, &line_size, fd) != -1){

      char *saved_buff = buffer;
      char *saved_line = line;

      while(line < saved_line + line_size){
        int count;
        memcpy(&count, line, 4);
        char c = *(line+4);

        buffer_size += count;
        buffer = realloc(buffer, buffer_size);
        if(buffer == NULL){
          fclose(fd);
          free(buffer);
          free(line);
          return 1;
        }

        for(int i=0; i<count; i++){
          buffer[(buffer_size - count) + i] = c;
        }

        line += 5;
        //buffer += count;
      }
      free(line);

      //buffer = saved_buff;
    }

    fprintf(stdout, "%s", buffer);
    
    free(buffer);

  return 0;
}



