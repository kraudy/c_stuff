#include <stdio.h>

void my_1d_array(int *a, int cols, int rows);
void my_1d_dims(int *a, int *dims, int n_dims);

int main(void){
  int x_2d_1d[6] = {
    1,2,3,4,5,6
  };
  int d[1] = {6};
  int d2[2] = {2, 3};
  int a = 3;
  int dims;
  
  my_1d_array(x_2d_1d, 2, 3);
  my_1d_array(x_2d_1d, 3, 2);
  my_1d_array(x_2d_1d, 6, 1);
  my_1d_array(x_2d_1d, 1, 6);

  dims = 0;
  my_1d_dims(&a, &dims, 0);
  my_1d_dims(x_2d_1d, d, 1);
  my_1d_dims(x_2d_1d, d2, 2);
  d2[0]=3; d2[1]=2;
  my_1d_dims(x_2d_1d, d2, 2);

}

void my_1d_array(int *a, int rows, int cols){
  puts("\nmy_1d_array");
  for (int row = 0; row<rows; row++){
    for (int col=0; col<cols; col++){
      printf("%d ", a[(row * cols) + col]);
    }
    puts("");
  }
} 


void my_1d_dims(int *a, int *dims, int n_dims){
  puts("\nmy_1d_array");
  int idx = 0;
  int idx2 = 0;
  if (n_dims == 0){
    puts("scalar");
    printf("%d\n", a[0]);
  }

  if (n_dims == 1){
    puts("vector");
    for (idx=0; idx<dims[0]; idx++){
      printf("%d ", a[idx]);
    }
    puts("");
  }

  idx=0;
  idx2=0;
  if (n_dims == 2){
    puts("matrix");
    for (idx=0; idx<dims[0]; idx++){
      for (idx2=0; idx2<dims[1]; idx2++){
        printf("%d ", a[(idx * dims[1]) + idx2]);
      }
      puts("");
    }
    puts("");
  }

  if (n_dims == 3){
    puts("3d matrix");
  }

} 