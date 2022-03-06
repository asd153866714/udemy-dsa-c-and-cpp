#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
  int data;
} Node;

typedef struct Node Node;

void change(int **p) {
  printf("address of new pointer in function is %d\n", &p);
  printf("address of pointer that pointed by pointer in function is %d\n", p);
  printf("value of integer pointed by p is %d\n", *p);
}

int main() {
  // Node *a = (Node *)malloc(sizeof(Node));
  // Node **b = &a;
  // a->data = 3;
  // printf("%d\n", a->data);

  Node *n = NULL;

  int a = 3;
  int *b = &a;
  int **c = &b;

  printf("%d %d \n", n, &n);

  printf("address of a is %d\n", &a);
  printf("address of b is %d\n", &b);
  printf("address of c is %d\n", &c);

  printf("address pointed by b is %d\n", b);
  printf("address pointed by c is %d\n", c);

  printf("value of a is %d\n", a);
  printf("value pointed by b is %d\n", *b);
  printf("value pointed by c is %d\n", *c);
  printf("value pointed by c is %d\n", *(*c));

  change(&b);
  printf("value of var pointed by b is %d\n", b);

  // printf("address pointed by a is %d\n", a);
  // printf("address of a is %d\n", &(*a));

  // printf("address pointed by b is %d\n", b);
  // printf("address of b is %d\n", &(**b));
  // printf("%d\n", **b);

  return 0;
}
