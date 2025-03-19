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
view* make_view_contiguous(int *shape, int v_dims);
void show_tensor(tensor T, int v_index);
void free_tensor(tensor T);


int main(void){
  // do something like make_data
  float a[6] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0};
  int shape[1] = {6};
  int dims = 1;
  tensor T = make_tensor(a, shape, dims);
  show_tensor(T, 0);
  /* I need a way here to make another view of the same tensor */
  free_tensor(T);
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
    .views = make_view_contiguous(shape, dims), 
    .v_counts = 1
  };

  puts("end tensor");

  return T;
}

view* make_view_contiguous(int *shape, int dims){
  view *v = malloc(sizeof(view));
  puts("inside view");
  if (v == NULL)
    return NULL;
  v->shape = shape;
  v->strides = malloc(dims * sizeof(int));
  /* The number of strides deppends on the number of dimensions*/
  if (v->strides == NULL){
    free(v);
    return NULL;
  }

  /* Strides of contiguous view
  [1 if i == (dims-1) else shape[i+1] for i in range(dims)]*/
  for (int i=0; i<dims; i++){
    v->strides[i] = (i == dims-1) ? 1 : shape[i+1];
  }

  v->dims = dims;
  puts("end view");
  return v;
}

void show_tensor(tensor T, int v_index){
  if (v_index > T.v_counts){
    puts("View index out of range");
    return;
  }
  // Get tensor data storage
  float *data = T.data;
  // Get view pointer out
  view *v = &T.views[v_index];

  if (v == NULL){
    puts("Null view");
    return;
  }
  // Get view dims
  int dims = v->dims;
  int *shape = v->shape;
  int *strides = v->strides;

  switch (dims){
  case 1:
    for (int dim=0; dim<dims; dim++){
      for (int i=0; i<shape[dim]; i++)
        printf("%.4f ", data[i * strides[dim]]);
      puts("");
    }
    break;
  case 2:
    break;
  case 3:
    break;
  default:
    break;
  }
}

void free_tensor(tensor T){
  for (int i=0; i<T.v_counts; i++){
    free(T.views[i].strides);
    //free(T.views[i].shape); // Not allocated
  }
  free(T.views);
  //free(T.data); // Stack data
}