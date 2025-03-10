#include <stdio.h>

void times2(int *a, int len);
void times3(int a[], int len);
void times4(int a[5], int len);
void double_array(int *a, int len);
void my_2d_array(int a[][3]);
void my_1d_array(int *a, int cols, int rows);

int main(void){
  int x[5] = {11, 22, 33, 44, 55};
  int x_2d[2][3] = {
    {1, 2, 3},
    {4, 5, 6}
  };
  int x_2d_1d[6] = {
    1,2,3,4,5,6
  };
  //times2(x, 5);
  //times3(x, 5);
  //times4(x, 5);
  //double_array(x, 5);
  //for (int i=0; i<5; i++){
  //  printf("%d\n",x[i]);
  //}
  //my_2d_array(x_2d);
  my_1d_array(x_2d_1d, 2, 3);
  
}

void my_1d_array(int *a, int rows, int cols){
  int idx = 0;
  for (int row = 0; row<rows; row++){
    idx = row;
    for (int col=0; col<cols; col++){
      printf("%d ", a[(row * cols) + col]);
    }
    puts("");
  }
} 

void my_2d_array(int a[][3]){
  for (int row = 0; row<2; row++){
    for (int col=0; col<3; col++){
      printf("%d ", a[row][col]);
    }
    puts("");
  }
}

void double_array(int *a, int len){
  for (int i=0; i<len; i++){
    a[i] *= 2;
  }
}

void times2(int *a, int len){
  for (int i=0; i<len; i++){
    printf("%d\n", a[i] * 2);
  }
}

void times3(int a[], int len){
  for (int i=0; i<len; i++){
    printf("%d\n", a[i] * 3);
  }
}

void times4(int a[5], int len){
  for (int i=0; i<len; i++){
    printf("%d\n", a[i] * 4);
  }
}
