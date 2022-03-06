#include <stdio.h>
#include <stdlib.h>

struct Queue {
  int size;
  int front;
  int rear;
  int *Q;
};

void create(struct Queue *q, int x) {
  q->size = x;
  q->front = q->rear = 0;
  q->Q = (int *)malloc(q->size * sizeof(int));
  return;
}

void enqueue(struct Queue *q, int x) {
  // check whether queue is full
  if ((q->rear + 1) % q->size == q->front) {
    printf("Queue is full\n");
    return;
  } else {
    q->rear = (q->rear + 1) % q->size;
    q->Q[q->rear] = x;
    return;
  }
}

int dequeue(struct Queue *q) {
  // create x to store deleted element
  int x = -1;
  // check whether queue is empty
  if (q->front == q->rear) {
    printf("Queue is empty\n");
    return x;
  } else {
    q->front = (q->front + 1) % q->size;
    x = q->Q[q->front];
    printf("Dequeue element is %d\n", x);
    return x;
  }
}

void display(struct Queue q) {
  int i = q.front + 1;
  do {
    printf("%d ", q.Q[i]);
    i = (i + 1) % q.size;
  } while (i != (q.rear + 1) % q.size);
  printf("\n");
}

int main() {

  struct Queue q;
  create(&q, 3);

  enqueue(&q, 1);
  enqueue(&q, 2);
  enqueue(&q, 3);
  display(q);
  dequeue(&q);

  return 0;
}
