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

  size_t size = 0;
  /* just multiply each read by 5 bytes since we are usin RLE*/
  for (int i=1; i<argc; i++){
    FILE *fd;
    if(find_file(&fd, argv[i])){
      return 1;
    }

    int c_read;

    while(getline(&line, &size, fd) != -1){
      buffer = realloc(buffer, 5 * size);
      if(buffer == NULL){
        fclose(fd);
        free(buffer);
        free(line);
        return 1;
      }
      char *savp = buffer;
      for(int i=0; i<size; i+=5){
        char c = *(buffer+(4*i));
      }
      buffer = savp;
    }
    

    while((c_read = fgetc(fd)) != EOF){
      /* EOF = -1 so assigning -1 at the start is useful*/
      if (current_read == -1){
        current_read = c_read;
        count = 1;
      }
      else if(c_read != current_read){
        size ++;
        buffer = realloc(buffer, 5 * size);
        if(buffer == NULL){
          fclose(fd);
          free(buffer);
          return 1;
        }
        memcpy(buffer + (size - 1) * 5, &count, 4);
        buffer[(size * 5) - 1] = current_read;
        current_read = c_read;
        count = 1;
      } 
      else{
        count ++;
      }
    }
    fclose(fd);
  }
  // Handle the last run after EOF
  if (count > 0) {
      size++;
      buffer = realloc(buffer, 5 * size);
      if (buffer == NULL) return 1;
      memcpy(buffer + (size - 1) * 5, &count, 4);
      buffer[(size - 1) * 5 + 4] = current_read;
  }

  /* write */
  fwrite(buffer, sizeof(char), 5 * size, stdout);

  free(buffer);

  return 0;
}



