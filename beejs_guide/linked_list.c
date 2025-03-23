#include <stdio.h>

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

  for (struct node *cur = head; cur!=NULL; cur = cur->next)
    free(cur->next); 
}

int main(void){
  test1();
}

