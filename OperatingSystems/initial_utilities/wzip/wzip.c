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
    fprintf(stdout, "wzip: file1 [file2 ...]\n");
    return 1;
  }

  char current = -1;
  int count = 0;

  
  /* read char */

  unsigned char *buffer = NULL; 
  size_t size = 0;
  /* just multiply each read by 5 bytes since we are usin RLE*/
  for (int i=1; i<argc; i++){
    FILE *fd;
    if(find_file(&fd, argv[i])){
      return 1;
    }

    int c_read;
    while((c_read = fgetc(fd)) != EOF){
      /* EOF = -1 so assigning -1 at the start is useful*/
      if (current == -1){
        current = c_read;
        count = 1;
      }
      else if(c_read != current){
        size ++;
        buffer = realloc(buffer, 5 * size);
        if(buffer == NULL){
          fclose(fd);
          free(buffer);
          return 1;
        }
        memcpy(buffer + (size - 1) * 5, &count, 4);
        buffer[(size - 1) * 5 + 4] = current;
        current = c_read;
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
      buffer[(size - 1) * 5 + 4] = current;
  }

  /* write */
  fwrite(buffer, sizeof(char), 5 * size, stdout);

  free(buffer);

  return 0;
}



