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
  
  char *buffer = NULL; 
  size_t buffer_size = 0;

  /* just multiply each read by 5 bytes since we are usin RLE*/
  for (int i=1; i<argc; i++){
    FILE *fd;
    if(find_file(&fd, argv[i])){
      return 1;
    }

    int count;
    char c;

    while(fread(&count, sizeof(int), 1, fd) && fread(&c, sizeof(char), 1, fd)){

      size_t new_size = buffer_size + count;
      if ((buffer = realloc(buffer, new_size)) == NULL) {
        fclose(fd);
        free(buffer);
        return 1;
      }

      // Fill the new portion with the character
      memset(buffer + buffer_size, c, count);
      buffer_size = new_size;
    }

    fclose(fd);
  }

  if (buffer_size > 0) {
    fwrite(buffer, 1, buffer_size, stdout);
  }
    
  free(buffer);
  
  return 0;
}

