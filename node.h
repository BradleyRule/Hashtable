#include <iostream>
#include <cstring>
#include "student.h"

using namespace std;

class Node{
 public:
  Node();
  ~Node();
  void setStudent(Student*);
  Student* getStudent();
  void setNext(Node*);
  Node* getNext();
 private:
  Node* next;
  Student* student;
};
