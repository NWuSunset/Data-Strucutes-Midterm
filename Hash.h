#ifndef HASH_H
#define HASH_H

struct Node {
  Node* next = nullptr;
  int data;

  Node(int data) {
    this->data = data;
  }
};

class Hash { //Key is the data to be stored basically
 public:
  Hash(); 
  void insert(int key, int data);
  void deleteData(int key);
  int hashFunction(int key);
  void rehash();
  void displayTable();


 private:
  int tableSize = 100;
  Node** table = new Node*[100]{}; //table array of linked lists
  
};


#endif
