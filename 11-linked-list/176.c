#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
} *first = NULL;

void create(int A[], int n) {
  int i;
  struct Node *t, *last;

  first = (struct Node *)malloc(sizeof(struct Node));
  first->data = A[0];
  first->next = NULL;
  // last 指向最後一個元素
  last = first;

  // 加入第一個之後的元素
  for (int i = 1; i < n; i++) {
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = A[i];
    t->next = NULL;
    // last 原本指向 first，代表 first->next 指向 t，
    last->next = t;
    // last 跟著新增的元素向後移動
    last = t;
  }
}

// 迭代列出
void display(struct Node *p) {
  while (p != NULL) {
    printf("%d ", p->data);
    p = p->next;
  }
  printf("%n");
}

// 遞迴列出
void rDisplay(struct Node *p) {
  if (p != NULL) {
    printf("%d ", p->data);
    rDisplay(p->next);
  }
}

int main() {
  // 建立要新增的元素
  int A[] = {3, 5, 7, 10, 15};
  create(A, 5);
  rDisplay(first);
  return 0;
}