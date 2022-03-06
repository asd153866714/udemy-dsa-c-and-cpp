#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *next;
} Node;

void insertAtFirst(Node **head, int newData) {
  // allocate memory to a new node
  Node *newNode = (Node *)malloc(sizeof(Node));

  // assign value
  newNode->data = newData;
  newNode->next = *head;

  // move head to point to new node
  *head = newNode;
}

void insertAtEnd(Node **head, int newData) {

  // allocate memory
  Node *newNode = (Node *)malloc(sizeof(Node));
  Node *temp = *head;
  newNode->data = newData;
  newNode->next = NULL;

  // if linked list is empty, make head point to new node
  if (*head == NULL) {
    *head = newNode;
    return;
  }

  // move to last node
  while (temp->next != NULL) {
    temp = temp->next;
  }
  // change head to point to new node
  temp->next = newNode;
}

void delete (Node **head, int key) {

  Node *temp = *head, *prev;

  // if key is first node
  if (temp != NULL && temp->data == key) {
    (*head) = temp->next;
    free(temp);
    return;
  }

  // find the key to be deleted
  while (temp != NULL && temp->data != key) {
    // prev point to previous node
    prev = temp;
    temp = temp->next;
  }
  // if key is not found
  if (temp == NULL) {
    return;
  }
  // delete node
  prev->next = temp->next;

  free(temp);
}
Node *search(Node *head, int key) {
  Node *temp = head;
  while (temp != NULL) {
    if (temp->data == key) {
      printf("%d\n", temp->data);
      return temp;
    }
    temp = temp->next;
  }
  return NULL;
}
void reverse(Node **head_ref) {
  Node *current = *head_ref, *prev = NULL, *next = NULL;
  while (current != NULL) {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }
  *head_ref = prev;
}
// insertAfter
// insertSorted
// sort

void display(Node *head) {
  Node *temp = head;
  while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

int main() {

  Node *head = NULL;
  insertAtFirst(&head, 3);
  insertAtFirst(&head, 5);
  insertAtFirst(&head, 7);
  insertAtEnd(&head, 10);
  display(head);

  delete (&head, 10);
  display(head);
  search(head, 3);

  reverse(&head);
  display(head);
  return 0;
}