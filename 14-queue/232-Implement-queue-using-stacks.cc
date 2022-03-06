// leetcode 232. Implement Queue using Stacks
#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
public:
  stack<int> s1, s2;
  /** Initialize your data structure here. */
  MyQueue() {}

  /** Push element x to the back of queue. */
  void push(int x) { s1.push(x); }

  /** Removes the element from in front of queue and returns that element. */
  int pop() {
    int x = -1;
    if (s1.empty() && s2.empty()) {
      return x;
    }
    if (s2.empty()) {
      while (!s1.empty()) {
        s2.push(s1.top());
        s1.pop();
      }
    }
    x = s2.top();
    s2.pop();
    return x;
  }

  /** Get the front element. */
  int peek() {
    int x = -1;
    if (s1.empty() && s2.empty()) {
      return x;
    }
    if (s2.empty()) {
      while (!s1.empty()) {
        s2.push(s1.top());
        s1.pop();
      }
    }
    x = s2.top();
    return x;
  }

  /** Returns whether the queue is empty. */
  bool empty() {
    if (s1.empty() && s2.empty()) {
      return true;
    } else {
      return false;
    }
  }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */