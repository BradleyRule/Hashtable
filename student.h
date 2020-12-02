#ifndef STUDENT
#define STUDENT

#include <iostream>
#include <cstring>

using namespace std;

class Student{
 public:
  Student(char*);
  char* getFirstName();
  void setLastName(char*);
  char* getLastName();
  void setID(int);
  int getID();
  void setGPA(float);
  float getGPA();
 private:
  char* firstname;
  char* lastname;
  int id;
  float gpa;
};
#endif
