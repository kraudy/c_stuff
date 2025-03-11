#include <stdio.h>
#include <stdlib.h>

int dot_product(int *a, int *b, int n_size);
int* vector_matrix_product(int *v, int *M, int *M_size);

typedef struct {
  int *data;
  int n_size;
} Vector;

int main(void){
  //TODO: Make this a struct
  Vector v;
  Vector f;

  int a[5] = {1, 2, 3, 4, 5};
  v.data = a;
  v.n_size = 5;
  // Assume this is stuff is already transpossed

  int n_size = 5;
  int b[5] = {6, 7, 8, 9, 10};
  f.data = b;
  f.n_size = 5;
  printf("dot prod: %d \n", dot_product(a, b, n_size));

  int M_size[2] = {2,5};
  int c[10] = {6, 7, 8, 9, 10, 12, 13, 14, 15, 16};
  int *result = vector_matrix_product(a, c, M_size);
  if (result == NULL) puts("Error pointer NULL");
  for (int i=0; i<M_size[0]; i++){
    printf("%d ", result[i]);
  }
  puts("");

  printf("struct dot prod: %d \n", struct_dot_product(v, f));


}

int struct_dot_product(Vector a, Vector b){
  int sum = 0;
  for (int i=0; i<a.n_size; i++){
    sum += (a.data[i] * b.data[i]);
  }
  printf("sum: %d\n", sum);
  return sum;
}

int dot_product(int *a, int *b, int n_size){
  int sum = 0;
  for (int i=0; i<n_size; i++){
    sum += (a[i] * b[i]);
  }
  printf("sum: %d\n", sum);
  return sum;
}

int* vector_matrix_product(int *v, int *M, int *M_size){
  // Create vector, must be in heap to not return nonesense stuff
  int *result = (int*) malloc(M_size[0] * sizeof(int));
  if (result == NULL) return NULL;
  
  printf("M_size[0]: %d | M_size[1]: %d \n", M_size[0], M_size[1]);
  for (int i=0; i < M_size[0]; i++){
    printf("i: %d \n", i);
    // & this thing because we need the address of the element, and not the element
    /*
      This is very important, it means that we only need a way to trasverse the array, give
      the function the start of the resulting vector and pass it the length we need since we
      can't slice this thing
    */
    int *row = &M[i * M_size[1]];
    result[i] = dot_product(v, row, M_size[1]);
  }
  return result;
}