#ifndef STACK_H
#define STACK_H

struct Node {
  Node* next;
  int data;
  
  Node(int data) {
    this->data = data;
  }
};

class Stack {
 public:
  Stack();
  int peek();
  Node* pop();
  void push(int data);
  
 private:
  Node* top = nullptr; //head of linked lsit
};


class Queue {
 public:
  Queue();
  void enqueue(int data);
  Node* dequeue();

 private:
  Node* first = nullptr; //to be dequeued (linkedl ist head)
  Node* last = nullptr; //tail of linked list
};


#endif
