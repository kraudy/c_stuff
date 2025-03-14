#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int *data;
  int n_size;
} Vector;

typedef struct{
  //TODO: Change this to storage which is always a 1d vector
  int *data;
  //TODO: Change this to implement a View
  int n_size[2];
} Matrix;

int dot_product(Vector *a, Vector *b);
Vector vector_matrix_product(Vector *v, Matrix *M);


int main(void){
  //TODO: Make this a struct
  Vector v;

  int a[5] = {1, 2, 3, 4, 5};
  v.data = a;
  v.n_size = 5;
  // Assume this is stuff is already transpossed

  Vector f;
  int b[5] = {6, 7, 8, 9, 10};
  f.data = b;
  f.n_size = 5;

  Matrix M;
  int M_size[2] = {2,5};
  int c[10] = {6, 7, 8, 9, 10, 12, 13, 14, 15, 16};
  M.data = c;
  M.n_size[0] = 2; M.n_size[1] = 5;

  printf("struct dot prod: %d \n", dot_product(&v, &f));

  Vector v_result = vector_matrix_product(&v, &M);
  if (v_result.data == NULL) puts("Error pointer struct NULL");
  for (int i=0; i<v_result.n_size; i++){
    printf("%d ", v_result.data[i]);
  }
  puts("");

}

int dot_product(Vector *a, Vector *b){
  int sum = 0;
  // a->n_size = (*a).n_size 
  for (int i=0; i< a->n_size; i++){
    sum += (a->data[i] * b->data[i]);
  }
  printf("sum: %d\n", sum);
  return sum;
}

Vector vector_matrix_product(Vector *v, Matrix *M){
  // Create vector, must be in heap to not return nonesense stuff
  Vector result;
  result.n_size = M->n_size[0];
  result.data = (int*) malloc(M->n_size[0] * sizeof(int));
  if (result.data == NULL) puts("Error NULL pointer");
  
  printf("M_size[0]: %d | M_size[1]: %d \n", M->n_size[0], M->n_size[1]);
  for (int i=0; i < M->n_size[0]; i++){
    printf("i: %d \n", i);
    Vector row;
    row.data = &M->data[i * M->n_size[1]];
    row.n_size = M->n_size[1];
    result.data[i] = dot_product(v, &row);
  }
  return result;
}
