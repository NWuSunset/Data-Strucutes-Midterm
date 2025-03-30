#include "Hash.h"
#include <iostream>
Hash::Hash() = default;

void Hash::insert(int key, int data) {
  int index = hashFunction(key);
  int collisions = 0; //defaults to zero

  //Insert into linked list
  //If head is null 
  if (table[index] == nullptr) {
    table[index] = new Node(data);
  } else { //move through the linekd list
    Node* curr = table[index];

    while (curr->next != nullptr) { //1 collision for every extra item in the list
      curr = curr->next;
      collisions++;
    }

    curr->next = new Node(data);
  }

  //rehashing if more than 3 collisions
  if (collisions > 3) {
    rehash();
  }  
}

void Hash::deleteData(int key) { //data is the key
  int index = hashFunction(key);

  //if head condiiton
  if (table[index]->data == key) {
    Node* temp = table[index];
    table[index] = nullptr;
    delete temp;
    return;
  }

  if (table[index] == nullptr) {
    return;
  }

  Node* curr = table[index];
  while (curr->next->data != key && curr->next != nullptr) {
    curr = curr->next;
  }

  if (curr->next == nullptr) {
    std::cout << "Not in table" << std::endl;
    return;
  }

  //once curr->next == key
  Node* temp = curr->next;
  curr->next = curr->next->next;
  delete temp;
}

void Hash::rehash() {
  int oldSize = tableSize;

  tableSize *= 2; //double tagble size

  Node** oldTable = table;
  table = new Node*[tableSize]{}; //new table

  //Fill in new table
  for (int i = 0; i < oldSize; i++) {
    Node* curr = oldTable[i];

    while (curr != nullptr) {
      insert(curr->data, curr->data);
      Node* toDelete = curr;
      curr = curr->next;
      delete toDelete;
    }
  }
  delete[] oldTable;
}

void Hash::displayTable() {
  for (int i = 0; i < tableSize; i++) {
    std::cout << i << ": ";
    Node* curr = table[i];
    
    
    while (curr != nullptr) {
      std::cout << curr->data << "->";
      curr = curr->next;
    }
    std::cout << std::endl;
  }
}

int Hash::hashFunction(int key) {
  return (key % tableSize); //key mod size
}
