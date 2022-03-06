#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
  int size;
  int top;
  int *arr;
} Stack;

void create(Stack *stack) {
  printf("Enter size of Stack: ");
  scanf("%d", &stack->size);
  stack->top = -1;
  // dynamic allocate memory for array
  stack->arr = (int *)malloc(stack->size * sizeof(int));
}

// Traver from top to bottom
void display(Stack stack) {
  for (int i = stack.top; i >= 0; i--) {
    printf("%d ", stack.arr[i]);
  }
  printf("\n");
}

void push(Stack *stack, int data) {
  // check if stack is full
  if (stack->top == stack->size - 1) {
    printf("Stack is full\n");
  } else {
    stack->top++;
    stack->arr[stack->top] = data;
  }
}

int pop(Stack *stack) {
  // create x for store deleted element
  int x = -1;

  // check if stack is empty
  if (stack->top == -1) {
    printf("Stack is empty\n");
  } else {
    x = stack->arr[stack->top];
    stack->top--;
  }
  return x;
}

// get element from given index
// count from top element, not array index
int peek(Stack stack, int index) {
  int x = -1;
  //
  if (stack.top - index + 1 < 0) {
    printf("Invalid index \n");
  } else {
    x = stack.arr[stack.top - index + 1];
  }
  return x;
}

// Check if stack is empty
int isEmpty(Stack stack) {
  if (stack.top == -1) {
    return 1;
  }
  return 0;
}

// Check if stack is full
int isFull(Stack stack) { return stack.top == stack.size - 1; }

// get top element of stack
int stackTop(Stack stack) {
  // check if stack is empty
  if (!isEmpty(stack)) {
    return stack.arr[stack.top];
  }
  return -1;
}

int main() {
  Stack stack;
  create(&stack);
  push(&stack, 1);
  push(&stack, 2);
  push(&stack, 3);
  push(&stack, 4);
  printf("Stack top is %d\n", stackTop(stack));
  printf("peek: %d\n", peek(stack, 2));
  // printf("Deleted element is %d\n", pop(&stack));

  display(stack);

  return 0;
}