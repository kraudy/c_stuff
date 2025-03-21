#ifndef TENSOR_H
#define TENSOR_H

typedef struct{

} autograd_meta;

typedef struct {
  int *shape;
  int *strides;
  int dims;
} view;

typedef struct {
  float *data;
  view *views;
  int v_counts;
} tensor;

//TODO: Add a struct to keep track of all tensors pointers

tensor make_tensor(float *data, int *shape, int dims);
tensor* make_view_contiguous(tensor *T, int *shape, int v_dims);
void show_tensor(tensor T);
void free_tensor(tensor T);

#endif