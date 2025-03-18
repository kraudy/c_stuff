#include <stdio.h>

typedef struct {
  int *strides;
  int v_dims;
} view;

typedef struct {
  float *data;
  int *shape;
  int dims;
  view *views; // This will need to be realloc
  int v_counts;
} tensor;

tensor make_tensor(float *data, int *shape, int dims);
view* make_view(int *strides, int v_dims);
void show_tensor(tensor T, int v_index);


int main(void){
  // do something like make_data
  int a[6] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0};
  int dims = 1;
  int shape[1] = {6};
  tensor T = make_tensor(a, shape, dims);

}

/*
  So, when a tensor is made, by defacto a view wich shows all the elements
  in the full tensor shape is created. This will be the view at index 0.
*/

tensor make_tensor(float *data, int *shape, int dims){
  // Validate NULL pointer, maybe make T a tensor pointer
  tensor T;
  // This is the defacto initialization
  T.data = data;
  T.shape = shape;
  T.dims = dims;
  // Make default view, for now only 1d vectors
  int strides[1] = {1};
  T.views = make_view(strides, T.dims);
  T.v_counts = 1;
}