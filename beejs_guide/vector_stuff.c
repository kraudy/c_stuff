#include <stdio.h>

int dot_product(int *a, int *b, int n_size);


int main(void){
  //TODO: Make this a struct
  int n_size = 5;
  int a[5] = {1, 2, 3, 4, 5};
  int b[5] = {6, 7, 8, 9, 10};

  printf("dot prod: %d \n", dot_product(a, b, n_size));

}

int dot_product(int *a, int *b, int n_size){
  int sum = 0;
  for (int i=0; i<n_size; i++){
    sum += (a[i] * b[i]);
  }
  return sum;
}