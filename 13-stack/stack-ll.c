#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *next;
} Node;

void push(Node **top, int data) {
  // create new node
  struct Node *newNode;
  newNode = (Node *)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = *top;
  *top = newNode;
}
int isEmpty(Node *top) {
  // if address of top is NULL, stack is empty
  // return !top;
  if (top == NULL) {
    return 1;
  }
  return 0;
}

void pop(Node **top) {
  // create pointer temp for free memory for deleted memory
  Node *temp = *top;
  int x = -1;
  if (isEmpty(*top)) {
    printf("Stack is empty\n");
  } else {
    *top = (*top)->next;
    x = temp->data;
    free(temp);
    printf("Popped element is %d\n", x);
  }
}
void display(Node *top) {
  // create pointer to store current node
  Node *cur;
  cur = top;
  while (cur != NULL) {
    printf("%d ", cur->data);
    cur = cur->next;
  }
  printf("\n");
}
void stackTop(Node *top) {
  if (isEmpty(top)) {
    printf("Stack is empty\n");
  } else {
    printf("Top of stack is %d\n", top->data);
  }
}
int main() {
  Node *top = NULL;
  push(&top, 1);
  push(&top, 2);
  push(&top, 3);
  display(top);
  pop(&top);
  stackTop(top);
  display(top);

  return 0;
}
