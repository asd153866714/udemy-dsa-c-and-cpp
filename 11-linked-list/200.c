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

// Check if linked list is sorted (increasing)
int isSorted(struct Node *p) {
  // Create x to store previous node's data, to compare with current node
  // Initialize with a small number, make sure it will shorter than first node
  int x = INT_MIN;
  while (p != NULL) {
    // check if current node is shorter than previous node (false condition)
    // if test is true, linked list is not sorted
    if (p->data < x) {
      printf("Not Sorted\n");
      return 0;
    }
    x = p->data;
    p = p->next;
  }
  printf("Sorted\n");
  return 1;
}

// Remove duplicated node from linked list
void removeDuplicate(struct Node *p) {
  struct Node *q = p->next;
  while (q != NULL) {
    // traverse and check if q and p are similar,
    // if false, keep moving
    // if true, remove q (second node)
    if (p->data != q->data) {
      p = q;
      q = q->next;
    } else {
      p->next = q->next;
      free(q);
      // q should keep moving to the end of linked list
      q = p->next;
    }
  }
}

// Reverse linked list by reversing elements
void reverseByElement(struct Node *p) {
  // create an array for store copy node from linked list,
  // i=0 for index in array
  int *arr, i = 0;
  // pointer q point to current node
  struct Node *q = p;

  arr = (int *)malloc(sizeof(int) * count(p));
  // copy all nodes from linked list to array
  while (q != NULL) {
    arr[i] = q->data;
    q = q->next;
    i++;
  }
  q = p;
  i--;
  // copy each element to linked list
  while (q != NULL) {
    q->data = arr[i];
    q = q->next;
    i--;
  }
}

// Reverse linked list by reversing link
void reverseByLink(struct Node *p) {
  struct Node *q = NULL, *r = NULL;

  while (p != NULL) {
    r = q;
    q = p;
    p = p->next;
    q->next = r;
  }
  first = q;
}

// Reverse linked list by recursion
void reverseByRecursion(struct Node *q, struct Node *p) {
  if (p) {
    reverseByRecursion(p, p->next);
    p->next = q;
  } else {
    first = q;
  }
}

int main() {
  int arr[] = {1, 2, 3, 4, 5};
  create(arr, 5);
  // reverseByElement(first)
  // reverseByLink(first);
  reverseByRecursion(NULL, first);

  display(first);

  return 0;
}