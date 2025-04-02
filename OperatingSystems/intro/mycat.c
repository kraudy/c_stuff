#include <stdio.h>
#include <assert.h>

int main(int argc, char *argv[]){
  assert(argc >= 2);

  puts("out");

  for (int i=1; i<argc; i++){
    FILE *f = fopen(argv[i], "r");
    if(f == NULL){
      fprintf(stderr, "File not found: %s\n", argv[i]);
      continue;
    }
    puts("found");
    char s[1024];
    while(fgets(s, sizeof s, f) != NULL)
      printf("%s", s);

    fclose(f);
  }

  return 0;
}
