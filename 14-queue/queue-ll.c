#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
} *front = NULL, *rear = NULL;

void enqueue(int x) {
  // create new node
  struct Node *t;
  t = (struct Node *)malloc(sizeof(struct Node));
  // check whether queue is full
  if (t == NULL) {
    printf("Queue is full\n");
    return;
  } else {
    t->data = x;
    t->next = NULL;
    // check whether queue is empty, new node wiil be the first node
    if (front == NULL) {
      front = t;
      rear = t;
    } else {
      rear->next = t;
      rear = t;
    }
  }
}

int dequeue() {
  // create x to store deleted element
  // create pointer t to free memory pointed by deleted node
  int x = -1;
  struct Node *t;
  // check whether queue is empty
  if (front == NULL) {
    printf("Queue is full\n");
    return x;
  } else {
    x = front->data;
    t = front;
    // move front to point to next ndoe
    front = front->next;
    free(t);
    printf("Dequeue element is %d\n", x);
    return x;
  }
}

void display() {
  struct Node *p = front;
  while (p) {
    printf("%d ", p->data);
    p = p->next;
  }
  printf("\n");
}

int main() {
  enqueue(10);
  enqueue(20);
  enqueue(30);
  dequeue();

  display();
}