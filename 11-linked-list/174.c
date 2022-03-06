#include <stdio.h>
#include <stdlib.h>

// 定義結構型態作為鏈結串列的節點，並宣告一個指向該結構的指標變數 frist 指向
// NULL
struct Node {
  int data;
  struct Node *next;
} *first = NULL;

void create(int A[], int n) {
  int i;
  struct Node *t, *last;

  // first 指標指向一塊動態分配的記憶體
  first = (struct Node *)malloc(sizeof(struct Node));
  // 把陣列的第一個元素賦予給 first 節點，作為該節點的值
  first->data = A[0];
  // 只有一個節點，first->next 指向 NULL
  first->next = NULL;
  // last 指向最後一個元素
  last = first;

  // 加入第一個之後的元素
  for (int i = 1; i < n; i++) {
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = A[i];
    t->next = NULL;
    // last 原本指向 first，代表 first->next 指向 t
    last->next = t;
    // last 跟著新增的元素向後移動
    last = t;
  }
}

// 迭代印出
void display(struct Node *p) {
  while (p != NULL) {
    printf("%d ", p->data);
    p = p->next;
  }
  printf("%n");
}

int main() {
  // 建立要新增的元素
  int A[] = {3, 5, 7, 10, 15};
  create(A, 5);
  display(first);
  return 0;
}