#include <stdio.h>
#include <stdlib.h>

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
view* make_view(int *shape, int v_dims);
void show_tensor(tensor T, int v_index);
void clean_tensors(void);


int main(void){
  // do something like make_data
  float a[6] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0};
  int shape[1] = {6};
  int dims = 1;
  tensor T = make_tensor(a, shape, dims);
  show_tensor(T, 0);
  puts("Fin!");
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
  puts("inside tensor");
  tensor T = {
    .data = data,
    .views = make_view(shape, dims), 
    .v_counts = 1
  };

  puts("end tensor");

  return T;
}

view* make_view(int *shape, int dims){
  view *v = malloc(sizeof(view));
  puts("inside view");
  if (v == NULL)
    return NULL;
  v->shape = shape;
  v->strides = malloc(dims * sizeof(int));
  if (v->strides == NULL){
    free(v);
    return NULL;
  }

  switch (dims){
  case 1:
    // Make default view, for now only 1d vectors
    // Contigous stride
    // v->strides[0] = 1;
    v->strides[0] = 1;
    break;
  case 2:
    break;
  case 3:
    break;
  default:
    break;
  }
  v->dims = dims;
  puts("end view");
  return v;
}

void show_tensor(tensor T, int v_index){
  // get view pointer out
  switch (T.views[0].dims){
  case 1:
    for (int i=0; i<T.views[v_index].shape[0]; i++)
      printf("%.4f ", T.data[i * T.views[v_index].strides[0]]);
    puts("");
    break;
  case 2:
    break;
  case 3:
    break;
  default:
    break;
  }
}