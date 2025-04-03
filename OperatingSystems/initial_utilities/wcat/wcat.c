#include <stdio.h>
#include <assert.h>

int find_file(FILE **f, char *name){
  *f = fopen(name, "r");
  if(*f == NULL){
    return 1;
  }
  return 0;
}

int read_file_fgets(char *name){
  FILE *f = NULL;
  if (find_file(&f, name))
    return 1;

  char s[1024];
  while(fgets(s, sizeof s, f) != NULL)
    printf("%s", s);

  fclose(f);
  return 0;
}

int read_file_fgetc(char *name){
  FILE *f = NULL;
  if (find_file(&f, name))
    return 1;

  char c;
  while((c = fgetc(f)) != EOF)
    putchar(c);

  fclose(f);
  return 0;
}

int main(int argc, char *argv[]){
  if(argc < 2)
    return 0;

  for (int i=1; i<argc; i++){
    if (read_file_fgetc(argv[i])){
      fprintf(stdout, "wcat: cannot open file\n");
      return 1;
    }
  }

  return 0;
}
