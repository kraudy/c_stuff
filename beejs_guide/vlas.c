#include <stdio.h>

void print_matrix(int h, int w, int m[h][w]){
  for (int row = 0; row<h; row++){
    for (int col=0; col<w; col++)
      printf("%2d ", m[row][col]);
    puts("");
  }
  
}

void test1(){
  int rows = 4, cols = 7;
  int matrix[rows][cols];

  for (int row = 0; row<rows; row++)
    for (int col=0; col<cols; col++)
      matrix[row][col] = row*col;

  print_matrix(rows, cols, matrix);
}

int main(void){
  test1();

}
