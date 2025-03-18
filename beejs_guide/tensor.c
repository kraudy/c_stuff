#include <stdio.h>

typedef struct{

} autograd_meta;

typedef struct {
  int *shape;
  int *strides;
  int dims;
} view;

typedef struct {
  float *data;
  view *views; // This will need to be realloc
  int v_counts;
} tensor;

//TODO: Add a struct to keep track of tensors pointers

tensor make_tensor(float *data, int *shape, int dims);
view* make_view(int *shape, int *strides, int v_dims);
void show_tensor(tensor T, int v_index);
void clean_tensors(void);


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
  Here, by default our tensor device is the mundane cpu.
  Tensor triad: Device, Layout, Dtype
*/

tensor make_tensor(float *data, int *shape, int dims){
  // Validate NULL pointer, maybe make T a tensor pointer
  // Validate malloc()
  tensor T;
  // This is the defacto initialization
  T.data = data;
  view v;
  v.shape = shape;
  //T.dims = dims;
  switch (dims){
  case 1:
    // Make default view, for now only 1d vectors
    // Contigous stride
    *v.strides = 1;
    //T.views = make_view(strides, dims);
    break;
  case 2:
    break;
  case 3:
    break;
  default:
    break;
  }
  v.dims = dims;
  *T.views = v;
  T.v_counts = 1;
}

view* make_view(int *shape, int *strides, int dims){
  view *v = malloc(sizeof(view));
  if (v == NULL)
    return NULL;
  v->strides = strides;
  v->dims = dims;

  return v;
}