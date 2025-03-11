#include <stdio.h>
#include <stdlib.h>

int dot_product(int *a, int *b, int n_size);
int* vector_matrix_product(int *v, int *M, int *M_size);

typedef struct {
  int *data;
  int n_size;
} Vector;

typedef struct{
  int *data;
  int n_size[2];
} Matrix;

int struct_dot_product(Vector a, Vector b);
Vector struct_vector_matrix_product(Vector v, Matrix M);



int main(void){
  //TODO: Make this a struct
  Vector v;

  int a[5] = {1, 2, 3, 4, 5};
  v.data = a;
  v.n_size = 5;
  // Assume this is stuff is already transpossed

  Vector f;
  int n_size = 5;
  int b[5] = {6, 7, 8, 9, 10};
  f.data = b;
  f.n_size = 5;
  printf("dot prod: %d \n", dot_product(a, b, n_size));

  Matrix M;
  int M_size[2] = {2,5};
  int c[10] = {6, 7, 8, 9, 10, 12, 13, 14, 15, 16};
  M.data = c;
  M.n_size[0] = 2; M.n_size[1] = 5;

  int *result = vector_matrix_product(a, c, M_size);
  if (result == NULL) puts("Error pointer NULL");
  for (int i=0; i<M_size[0]; i++){
    printf("%d ", result[i]);
  }
  puts("");

  printf("struct dot prod: %d \n", struct_dot_product(v, f));

  Vector v_result = struct_vector_matrix_product(v, M);
  if (v_result.data == NULL) puts("Error pointer struct NULL");
  for (int i=0; i<v_result.n_size; i++){
    printf("%d ", v_result.data[i]);
  }
  puts("");

}

int struct_dot_product(Vector a, Vector b){
  int sum = 0;
  for (int i=0; i<a.n_size; i++){
    sum += (a.data[i] * b.data[i]);
  }
  printf("sum: %d\n", sum);
  return sum;
}

Vector struct_vector_matrix_product(Vector v, Matrix M){
  // Create vector, must be in heap to not return nonesense stuff
  Vector result;
  result.n_size = M.n_size[0];
  result.data = (int*) malloc(M.n_size[0] * sizeof(int));
  if (result.data == NULL) puts("Error NULL pointer");
  
  printf("M_size[0]: %d | M_size[1]: %d \n", M.n_size[0], M.n_size[1]);
  for (int i=0; i < M.n_size[0]; i++){
    printf("i: %d \n", i);
    Vector row;
    row.data = &M.data[i * M.n_size[1]];
    row.n_size = M.n_size[1];
    result.data[i] = struct_dot_product(v, row);
  }
  return result;
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