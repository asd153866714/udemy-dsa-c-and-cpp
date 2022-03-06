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
  printf("\n");
}

// 遞迴列出
void rDisplay(struct Node *p) {
  if (p != NULL) {
    printf("%d ", p->data);
    rDisplay(p->next);
  }
}

// 迭代計算節點數量
int count(struct Node *p) {
  int count = 0;
  while (p) {
    count++;
    p = p->next;
  }
  return count;
}

// 遞迴計算節點數量
// 最後一個函數回傳後才開始加總
int rCount(struct Node *p) {
  if (p != NULL) {
    return rCount(p->next) + 1;

  } else {
    return 0;
  }
}

// 計算節點資料總和
int sum(struct Node *p) {
  int sum = 0;
  while (p != NULL) {
    sum += p->data;
    p = p->next;
  }
  return sum;
}

// 遞迴計算節點總和
int rSum(struct Node *p) {
  if (p == NULL) {
    return 0;
  } else {
    return rSum(p->next) + p->data;
  }
}

// 尋找資料最大的節點
int Max(struct Node *p) {
  int max = INT_MIN;

  while (p != NULL) {
    if (p->data > max) {
      max = p->data;
    }
    p = p->next;
  }
  return max;
};

// 遞迴尋找最大的節點
int rMax(struct Node *p) {

  int x = 0;

  if (p == 0) {
    return INT_MIN;
  }
  x = rMax(p->next);

  if (x > p->data) {
    return x;
  } else {
    return p->data;
  }
}

// 線性搜尋
// 該函數傳回值的型態: a pointer to struct
struct Node *lSearch(struct Node *p, int key) {
  while (p != NULL) {
    if (key == p->data) {
      return p;
    }
    p = p->next;
  }
  return NULL;
}

// 遞迴版本搜尋
struct Node *rSearch(struct Node *p, int key) {
  if (p == NULL) {
    return NULL;
  }
  if (key == p->data) {
    return p;
  }
  return rSearch(p->next, key);
}

// 優化搜尋 (move to front operation)，把已經搜尋過的元素移到串列前面
struct Node *moveToFrontLinearSearch(struct Node *p, int key) {
  // 指向 p 前一個的元素
  struct Node *q = NULL;

  while (p != NULL) {
    if (key == p->data) {
      // 把 p 移動到串列前面
      q->next = p->next;
      p->next = first;
      first = p;
      return p;
    }
    q = p;
    p = p->next;
  }
  return NULL;
}

// insert node after given position
void insert(struct Node *p, int index, int x) {

  // declare a pointer to new node
  struct Node *t;

  // check whether index is valid
  if (index < 0 || index > count(p)) {
    return;
  }

  // t 指向分配的記憶體空間，並賦予值
  t = (struct Node *)malloc(sizeof(struct Node));
  t->data = x;

  // if index is 0, insert before first node
  if (index == 0) {
    t->next = first;
    first = t;
  }
  // if index isn't 0, insert after given position
  else {
    // 指標 p 遍歷到要插入的位置
    for (int i = 0; i < index - 1; i++) {
      p = p->next;
    }
    t->next = p->next;
    p->next = t;
  }
}

// 由小到大插入節點
void sortedInsert(struct Node *p, int x) {
  struct Node *t, *q = NULL;

  t = (struct Node *)malloc(sizeof(struct Node));
  t->data = x;
  t->next = NULL;

  if (first == NULL) {
    first = t;
  } else {
    while (p && p->data < x) {
      q = p;
      p = p->next;
    }
    if (p == first) {
      t->next = first;
      first = t;
    } else {
      // t 指向 p, q 指向 t
      t->next = q->next;
      q->next = t;
    }
  }
}

// prev current next
// Delete node at given position
int deleteNode(struct Node *p, int index) {
  // create following pointer q point to previous node, and delete processing
  struct Node *q;
  // x
  int x = -1;

  // check if given index is valid
  if (index < 1 || index > count(p)) {
    return -1;
  }
  // check if given index is 1, we delete first node
  if (index == 1) {
    q = first;
    x = first->data;
    first = first->next;
    free(q);
    return x;
  } else {
    for (int i = 1; i < index - 1; i++) {
      q = p;
      p = p->next;
    }
    q->next = p->next;
    x = p->data;
    free(p);
    return x;
  }
}

int main() {
  sortedInsert(first, 50);
  sortedInsert(first, 10);
  sortedInsert(first, 1);
  display(first);

  printf("Deleted element is %d\n", deleteNode(first, 1));
  display(first);
  return 0;
}