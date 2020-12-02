#include <iostream>
#include <cstring>
#include "node.h"

using namespace std;

Node::Node() {//this sets student and next to nothing when node is created
  student = NULL;
  next = NULL;
}

Node::~Node(){//deletes the student from memory
  delete &student;
  next = NULL;
}

void Node::setStudent(Student* newstudent) {//sets the student pointer
  student = newstudent;
}

Student* Node::getStudent(){//returns the student pointer
  return student;
}

void Node::setNext(Node* newnext){//sets next node
  next = newnext;
}

Node* Node::getNext() {//gets next node
  return next;
}
