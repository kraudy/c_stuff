#include <stdio.h>

typedef struct {
  int *strides;
  int v_dims;
} view;

typedef struct {
  float *data;
  int *shape;
  int dims;
  view *views;
  int v_counts;
} tensor;

tensor make_tensor(float *data, int *shape, int dims);
view make_view(tensor T, int *strides, int v_dims);
void show_tensor(tensor T, int v_index);

/*
  So, when a tensor is made, by defacto a view wich shows all the elements
  in the full tensor shape is created. This will be the view at index 0.
*/

int main(void){

}
