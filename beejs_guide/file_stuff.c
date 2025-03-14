#include <stdio.h>

int read_fopen(void){
  FILE *fp;
  char s[1024];
  int linecount = 0;

  fp = fopen("hello.txt", "r");
  if (fp == NULL){
    puts("fp null!");
    return 1;
  }

  while((fgets(s, sizeof s, fp)) != NULL)
    printf("%d: %s", ++linecount, s);
  puts("");

  fclose(fp);
}

int read_fscanf(void){
  FILE *fp;
  char name[1024];  // Big enough for any line this program will encounter
  float length;
  int mass;

  fp = fopen("whales.txt", "r");

  while (fscanf(fp, "%s %f %d", name, &length, &mass) != EOF)
      printf("%s whale, %d tonnes, %.1f meters\n", name, mass, length);

  fclose(fp);

}

int write_file(void){
  FILE *fp;
  int x = 32;

  //fp = stdout;
  fp = fopen("output.txt", "w");

  fputc('B', fp);
  fputc('\n', fp);
  fprintf(fp, "x = %d\n", x);
  fputs("Hello, world!\n", fp);

  fclose(fp);
}

int main(void){
  read_fopen();
  read_fscanf();
  write_file();

}
