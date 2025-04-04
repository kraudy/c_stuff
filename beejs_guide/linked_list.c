#include <stdio.h>
#include <stdlib.h>

struct node {
  //tensor T
  int data;
  struct node *next;
  //uns n_prev;
  //struct node *prev;
};

void test1(void){
  struct node *head;

  /* Interesting how a struct is a pointer to the first element, similar to an array*/
  head = malloc(1 * sizeof(struct node));  
  head->data = 11;
  head->next = malloc(1 * sizeof(struct node));
  head->next->data = 22;
  head->next->next = malloc(1 * sizeof(struct node));
  head->next->next->data = 33;
  head->next->next->next = NULL;

  for (struct node *cur = head; cur!=NULL; cur = cur->next)
    printf("%d\n", cur->data);

  //for (struct node *cur = head; cur!=NULL; cur = cur->next)
  //  free(cur->next); 
}

struct parent {
    int a, b;
};

struct child {
    struct parent super; 
    int c, d;
};

void print_parent(void *p){
  /* This let us defference the pointer */
  struct parent *self = p;
  printf("Parent: %d, %d\n", self->a, self->b);

  struct child *self_child = p;
  printf("Child from parent pointer: %d, %d\n", self_child->c, self_child->d);
}

void print_child(struct child *self){
  printf("Child: %d, %d\n", self->c, self->d);
}

void child_test(void){
  /* Initialize both structs */
  struct child c = {.super.a=1, .super.b=2, .c=3, .d=4};
  print_child(&c);
  print_parent(&c);
}

struct foo{
  unsigned a:1;
  unsigned b:1;
  unsigned c;
  unsigned d;
};

struct foo2{
  unsigned char a:2;
  unsigned char dummy:5;
  unsigned char b:1;
};

void bits_length(void){
  printf("Foo: %zu\n", sizeof(1 * sizeof(struct foo)));
  printf("Foo2: %zu\n", sizeof(1 * sizeof(struct foo2)));
}

int main(void){
  test1();
  child_test();
  bits_length();
}

