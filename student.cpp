#include <iostream>
#include <cstring>
#include "student.h"
#include "node.h"

using namespace std;

Student::Student(char* input){//sets first name of student when created
  firstname = input;
}

char* Student::getFirstName(){//returns the first name of the student
  return firstname;
}

void Student::setLastName(char* input){//sets the last name of student
  lastname = input;
}

char* Student::getLastName(){//returns last name of student
  return lastname;
}

void Student::setID(int input){//sets the student id
  id = input;
}

int Student::getID(){//returns the student id
  return id;
}

void Student::setGPA(float input){//sets the gpa of the student
  gpa = input;
}

float Student::getGPA(){//returns the gpa of the student
  return gpa;
}
