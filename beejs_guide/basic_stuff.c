#include <stdio.h>
#include <stdbool.h>

void bool_stuff(void){
  puts("\nbool_stuf");
  bool x = true;
  if (x) {
    printf("x is true \n");
  }
}

void pointers(int* i){
  puts("\npointers");
  int *p;
  char *s = "Hello, world !";

  p = i;

  printf("%s i  = %d  \n", s, *i);
  printf("i addres: %p \n", (void *) p);
  printf("%zu\n", sizeof p); //size of pointer
  printf("%zu\n", sizeof *p);// size of int
}

void arrays(void){
  puts("\narrays");
  float f[4]; 
  int a[5] = {1,2,3,4,5};
  int b[100] = {0}; // This wil set all elements to zero
  f[0] = 3.1638; f[1] = 1.2345;
  f[2] = 1.6808; f[3] = 2.7898;
  for (int i=0; i<4; i++){
    printf("%f\n",f[i]);
  }

}

void size_stuff(void){
  puts("\nsize_stuff");
  int x[12];
  printf("%zu\n", sizeof(x));
  printf("%zu\n", sizeof(int));
  printf("%zu\n", sizeof(x) / sizeof(int));
}

void matrix_stuff(void){
  puts("\nmatrix_stuff");
  int row, col;
  int a[2][5] = {
    {0, 1, 2, 3, 4},
    {5, 6, 7, 8, 9}
  };

  for (row=0; row<2; row++){
    for (col=0; col<5; col++){
      printf("(%d, %d) = %d\n", row, col, a[row][col]);
    }
  }

}

void array_pointers(void){
  puts("\narray_pointers");
  int a[5] = {1,2,3,4,5};
  int *p;

  p = &a[0];
  printf("%d\n",*p);
  p = a;
  printf("%d\n",*p);

}


int main (void){
  int i = 2;   

  bool_stuff();
  pointers(&i);
  arrays();
  size_stuff();
  matrix_stuff();
  array_pointers();

}
