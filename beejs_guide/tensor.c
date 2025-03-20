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
tensor* make_view_contiguous(tensor *T, int *shape, int v_dims);
void show_tensor(tensor T, int v_index);
void free_tensor(tensor T);

void vector_test(void){
  printf("\nvector_test\n");
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

void matrix_test(void){
  printf("\nmatrix_test\n");
  // do something like make_data
  float a[6] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0};
  int shape[2] = {2, 3};
  int dims = 2;
  tensor T = make_tensor(a, shape, dims);
  show_tensor(T, 0);
  /* I need a way here to make another view of the same tensor */
  free_tensor(T);
  puts("Fin!");
}

void cube_test(void) {
  printf("\ncube_test\n");
  // Example: 2x2x3 tensor (2 slices, 2 rows, 3 columns)
  float a[12] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0,  // Slice 0
                  7.0, 8.0, 9.0, 10.0, 11.0, 12.0}; // Slice 1
  int shape[3] = {2, 2, 3};
  int dims = 3;
  tensor T = make_tensor(a, shape, dims);
  show_tensor(T, 0);
  free_tensor(T);
  puts("Fin!");
}

int main(void){
  vector_test();
  matrix_test();
  cube_test();
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
    .v_counts = 1
  };

  //.views = make_view_contiguous(shape, dims), 
  T = *make_view_contiguous(&T, shape, dims); 


  puts("end tensor");

  return T;
}

tensor* make_view_contiguous(tensor *T, int *shape, int dims){
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

  /* Strides of contiguous view */
  int stride = 1;
  for (int i=dims-1; i>=0; i--){
    v->strides[i] = stride;
    stride *= shape[i];
  }

  v->dims = dims;
  puts("end view");

  
  // This should be realloc
  T->views = malloc(T->v_counts * sizeof(view));
  //T->views[T->v_counts] = *v;
  T->views[T->v_counts-1] = *v;
  
  return T;
}

void show_tensor(tensor T, int v_index){
  if (v_index >= T.v_counts){
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

  //TODO: Make this for N dimensions
  switch (dims){
  case 1:
    printf("stride1 %d\n", strides[0]);
    for (int row=0; row<shape[0]; row++)
      printf("%.4f ", data[(row * strides[0])]);
    puts("");
    break;
  case 2:
    printf("stride1 %d\n", strides[0]);
    printf("stride2 %d\n", strides[1]);
    for (int row=0; row<shape[0]; row++){
      for (int col=0; col<shape[1]; col++)
        printf("%.4f ", data[(row * strides[0]) + (col * strides[1])]);
      puts("");
    }
    break;
  case 3:
    for (int depth=0; depth<shape[0]; depth++){
      for (int row=0; row<shape[1]; row++){
        for (int col=0; col<shape[2]; col++){  
          int idx = (depth * strides[0]) + (row * strides[1]) + (col * strides[2]);
          printf("%.4f ", data[idx]);
        }
        puts("");
      }
      puts("");
    }
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