#include <stdio.h>
#include <stdlib.h>
#include "tensor.h"

void test1(void) {
  /* Vector of data */
  float data[12] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0,  // Slice 0
                  7.0, 8.0, 9.0, 10.0, 11.0, 12.0}; // Slice 1

  printf("\ntest1 vector\n");
  /* Make vector */
  int shape[1] = {12};
  int dims = 1;
  tensor *T = malloc(1 * sizeof(tensor));
  make_tensor(T, data, shape, dims);
  show_tensor(T);

  printf("\ntest1 matrix\n");
  /* Make matrix */
  int shape2[2] = {4, 3};
  int dims2 = 2;
  make_view_contiguous(T, shape2, dims2);
  show_tensor(T);

  printf("\ntest1 3d tensor\n");
  /* Make 3d tensor */
  int shape3[3] = {2, 2, 3};
  int dims3 = 3;
  make_view_contiguous(T, shape3, dims3);
  show_tensor(T);

  free_tensor(T);
  puts("Fin!");
}

int main(void){
  test1();
}

/*
  So, when a tensor is made, by defacto a view wich shows all the elements
  in the full tensor shape is created. This will be the view at index 0.
  Here, by default our tensor device is the mundane cpu.
  Tensor triad: Device, Layout, Dtype
*/

tensor* make_tensor(tensor *T ,float *data, int *shape, int dims){
  // Validate NULL pointer, maybe make T a tensor pointer
  // Validate malloc()
  puts("inside tensor");
  T->data = data;
  T->views = NULL;
  T->v_counts = 1;

  make_view_contiguous(T, shape, dims); 

  puts("end tensor");

  return T;
}

tensor* make_view_contiguous(tensor *T, int *shape, int dims){
  puts("inside view");
  
  view *new_view = realloc(T->views, T->v_counts * sizeof(view));
  if(new_view == NULL)
    return NULL;

  T->views = new_view;
  // Get last view address
  view *v = &T->views[T->v_counts-1];

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

  return T;
}

void show_tensor(tensor *T){
  /* By default, use last view */
  int v_index = T->v_counts-1;

  //if (v_index >= T->v_counts){
  //  puts("View index out of range");
  //  return;
  //}
  // Get tensor data address
  float *data = T->data;
  // Get view pointer out
  view *v = &T->views[v_index];

  if (v == NULL){
    puts("Null view");
    return;
  }
  //TODO: Add something here to traverse the tensor giving the required data.
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

void free_tensor(tensor *T){
  for (int i=0; i<T->v_counts; i++){
    free(T->views[i].strides);
    //free(T->views[i].shape); // Not allocated
  }
  free(T->views);
  //free(T->data); // Stack data
  free(T);
}