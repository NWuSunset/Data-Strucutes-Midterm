#include "Stack.h"
#include <stdexcept>

Stack::Stack() = default;

void Stack::push(int data) {
  Node* node = new Node(data);
  node->next = top;
  top = node;
}

Node* Stack::pop() {
  if (top == nullptr) {
    return nullptr;
  } // cehck if top is null
  
   Node* toPop = top;
  top = top->next;
  return toPop;
}

int Stack::peek() {
  if (top == nullptr) {
    throw std::runtime_error("Stack is empty");
  }
  return top->data;
}

Queue::Queue() = default;

void Queue::enqueue(int data) {
  //add to last in quque
  Node* node = new Node(data);

  if (last == nullptr) {
    first = last = node;
    return;
  }
  
  last->next = node;
  last = node;
}

Node* Queue::dequeue() {
  //dequeue first in the queue
  if (first == nullptr) {
    return nullptr;
  }

  Node* toReturn = first;
  first = first->next;

  if (first == nullptr) {
    last = nullptr;
  }
  
  return toReturn;
}


