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

  char c = "";
  char c_read = "";
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
    while((c_read = fgetc(fd)) != EOF){
      if(c_read != c){
        // here do the add
        size ++;
        if(realloc(buffer, 5 * size * sizeof(char)) == NULL){
          return 1;
        }
        c = c_read;
        count = 0;
      }
      count ++;
    } 
    fclose(fd);
  }

  /* write */
  fwrite(buffer, sizeof(char), size, stdout);

  return 0;
}



