// CPP program to implement Queue using
// two stacks with costly deQueue()
#include <iostream>
#include <stack>
using namespace std;

// in CPP, you can have function inside struct.

struct Queue {
  // delcare two stacks for queue
  stack<int> s1, s2;

  void enqueue(int x) { s1.push(x); }

  int dequeue() {
    // if both stack is empty
    if (s1.empty() && s2.empty()) {
      cout << "Queue is empty" << endl;
      exit(0);
    }
    // if s2 is empty, move elements from s1
    if (s2.empty()) {
      while (!s1.empty()) {
        s2.push(s1.top());
        s1.pop();
      }
    }
    int x = s2.top();
    s2.pop();
    cout << "Dequeue element is " << x << endl;
    return x;
  }
};

int main() {
  Queue q;
  q.enqueue(10);
  q.enqueue(20);
  q.enqueue(30);

  q.dequeue();
  q.dequeue();
  q.dequeue();
  q.dequeue();

  return 0;
}

/**
 * When implement Queue by 2 Stacks, there are 2 methods
 * 1. costly on enQueue(
 * 2. costly on deQueue()
 *
 * Method 2 is better than method 1, Method 1 moves all the elements twice in
 * enQueue operation, while method 2 (in deQueue operation) moves the elements
 * once and moves elements only if stack2 empty. So, the amortized complexity of
 * the dequeue operation becomes \Theta (1).
 */
