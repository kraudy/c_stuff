#include <stdio.h>
#include <assert.h>

int find_file(FILE **f, char *name){
  *f = fopen(name, "r");
  if(*f == NULL){
    fprintf(stderr, "File not found: %s\n", name);
    return 1;
  }
  return 0;
}

int read_file_fgets(char *name){
  FILE *f = NULL;
  if (find_file(&f, name))
    return 1;

  printf("File: %s\n", name);
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

  printf("File: %s\n", name);
  char c;
  while((c = fgetc(f)) != EOF)
    putchar(c);

  fclose(f);
  return 0;
}

int main(int argc, char *argv[]){
  assert(argc >= 2);

  puts("out");

  for (int i=1; i<argc; i++){
    //read_file_fgets(argv[i]);
    read_file_fgetc(argv[i]);
    printf("\n\n");
  }

  return 0;
}
