#include <stdio.h>
#include <stdlib.h>

struct Queue {
  int size;
  int front;
  int rear;
  int *Q;
};

void create(struct Queue *q, int x) {
  // printf("Please Enter size of queue: ");
  // scanf("%d", q->size);
  q->size = x;
  q->front = q->rear = -1;
  q->Q = (int *)malloc(q->size * sizeof(int));
  return;
}

void enqueue(struct Queue *q, int x) {
  // check whether queue is full
  if (q->rear == q->size - 1) {
    printf("Queue is full\n");
    return;
  } else {
    q->rear++;
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
    /**
     * q->front store the element before frist element in queue
     * so we shoud increse front by 1 to get the first element in queue
     *
     *          f           r
     * array: | x | 1 | 2 | 3 |
     * index:  -1   0   1   2
     */
    q->front++;
    x = q->Q[q->front];

    printf("Dequeue element is %d\n", x);
    return x;
  }
}

void display(struct Queue q) {
  // q->front store the element before frist element in queue
  // so first element is store in index: q->front + 1
  for (int i = q.front + 1; i <= q.rear; i++) {
    printf("%d ", q.Q[i]);
  }
  printf("\n");
}

int main() {

  struct Queue q;
  create(&q, 3);

  enqueue(&q, 1);
  enqueue(&q, 2);
  enqueue(&q, 3);
  dequeue(&q);
  display(q);
  return 0;
}

/**
 * create()
 *
 *         f/r
 * array: | x |
 * index:  -1
 *
 * enqueue()
 *
 *          f   r
 * array: | x | 1 |
 * index:  -1   0
 *
 * enqueue()
 *
 *          f       r
 * array: | x | 1 | 2 |
 * index:  -1   0   1
 *
 * enqueue()
 *
 *          f           r
 * array: | x | 1 | 2 | 3 |
 * index:  -1   0   1   2
 *
 * dequeue()
 *
 *              f       r
 * array: | x | 1 | 2 | 3 |
 * index:  -1   0   1   2
 *
 * Drawback of queue using array:
 * If We keep dequeue, the front may reach the end of the array,
 * and We can't reuse the space being deleted.
 * The solution is to use circular queue.
 */