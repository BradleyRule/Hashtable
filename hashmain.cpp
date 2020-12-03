#include <iostream>
#include <cstring>
#include "student.h"
#include "node.h"
#include <fstream>
#include <time.h>

using namespace std;

void deleteStudent(Node**&, Node**, int);
void print(Node**);
void createStudent(Node**&, Node**);
void rehash(Node**&, Node**);
void addStudent(Student*, Node**&, Node**);
void generate(Node**&, Node**, char**, char**, int);

int main(){

  srand(time(NULL));

  char* firstList[99];
  char* lastList[99];
  for(int i = 0; i <= 99; i++){
    firstList[i] = new char[20];
    lastList[i] = new char[20];
  }
  
  ifstream firstNames ("firstNames.txt");
  ifstream lastNames ("lastNames.txt");

  if (firstNames.is_open()){
    for (int i = 0; i <= 99; i++){
      firstNames >> firstList[i];
      //getline(firstNames, firstList[i]);
    }
    firstNames.close();
  }
  else {
    cout << "could not open firstnames" << endl;
  }

  if (lastNames.is_open()){
    for (int i = 0; i <= 99; i++){
      lastNames >> lastList[i];
      //getline(lastNames, lastList[i]);
    }
    lastNames.close();
  }
  else{
    cout << "could not open lastnames" << endl;
  }


  
  
  int id = 0;
  bool running =  1;
  char input[30];


  
  Node** table = NULL;
  table = new Node* [100];
  
  for(int i = 0; i <= 100; i++){
    table[i] = NULL;
  }

  

  while(running == 1){
    cout << endl;
    cout << "What would you like to do? (Commands: ADD, PRINT, DELETE, QUIT, GENERATE)" << endl;
    
    cin.get(input, 30);
    cin.get();

    if(strcmp(input, "ADD") == 0){
      createStudent(table, table);
    }

    else if(strcmp(input, "PRINT") == 0){
      print(table);
    }

    else if(strcmp(input, "DELETE") == 0){
      cout << "Enter the id of the student you would like to remove:" << endl;
      cin >> id;
      cin.get();
      deleteStudent(table, table, id);
      id = 0;
    }

    else if(strcmp(input, "QUIT") == 0){
      running = 0;
    }
    else if(strcmp(input, "GENERATE") == 0){
      cout << "Enter the number of students you would like to generate:" << endl;
      cin >> id;
      cin.get();
      generate(table, table, firstList, lastList, id);
      id = 0;
    }

    for (int i = 0; i <= 30; i++){
      input[i] = '\0';
    }

    
  }





  
  return 0;
}


void createStudent(Node** &table, Node** table2){
  char* first = new char[40];
  char* last = new char[40];
  int id = 0;
  float gpa = 0;
  cout << "Enter first name:" << endl;
  cin.get(first, 40);
  cin.get();
  cout << "Enter last name:" << endl;
  cin.get(last, 40);
  cin.get();
  cout << "Enter ID number:" << endl;
  cin >> id;
  cin.get();
  cout << "Enter GPA:" << endl;
  cin >> gpa;
  cin.get();

  Student* newstudent = new Student(first);
  newstudent->setLastName(last);
  newstudent->setID(id);
  newstudent->setGPA(gpa);

  addStudent(newstudent, table, table2);
}

void generate(Node** &table, Node** table2, char** firstList, char** lastList, int numberStudents){
  char* first = new char[40];
  char* last = new char[40];
  int id = 0;
  float gpa = 0;
  int count = 0;
  Node* current = NULL;
  bool idcheck = 0;
  Node** temp = table;
  
  cout << "test" << endl;/*DELETE LATER*/
  
  while (count < numberStudents){

    
    strcpy(first, firstList[rand()%100]);
    cout << first << endl;/*DELETE LATER*/
    strcpy(last, lastList[rand()%100]);
    cout << last << endl;/*DELETE LATER*/
    gpa = ((rand()% 399 + 1) * 0.01);
    id = count + 1;

    if(temp[id%sizeof(temp)] != NULL){
      if (temp[id%sizeof(temp)]->getStudent()->getID() != id){
	if(temp[id%sizeof(temp)]->getNext() == NULL){
	  Student* newstudent = new Student(first);
	  newstudent->setLastName(last);
	  newstudent->setID(id);
	  newstudent->setGPA(gpa);
	  cout << "test1a" << endl;/*DELETE LATER*/
	  addStudent(newstudent, table, table2);
	  cout << "test1b" << endl;/*DELETE LATER*/
	  count++;
	}
	else if(temp[id%sizeof(temp)]->getNext() != NULL){
	  current = temp[id%sizeof(temp)];
	  while(current != NULL){
	    if(current->getStudent()->getID() == id){
	      idcheck = 1;
	    }
	    current = current->getNext();
	  }
	  if(idcheck != 1){
	    Student* newstudent = new Student(first);
	    newstudent->setLastName(last);
	    newstudent->setID(id);
	    newstudent->setGPA(gpa);
	    cout << "test2a" << endl;/*DELETE LATER*/
	    addStudent(newstudent, table, table2);
	    cout << "test2b" << endl;/*DELETE LATER*/
	    count++;
	  }
	}
      }
    }
    else if(temp[id%sizeof(temp)] == NULL){
      Student* newstudent = new Student(first);
      newstudent->setLastName(last);
      newstudent->setID(id);
      newstudent->setGPA(gpa);
      cout << "test3a" << endl;/*DELETE LATER*/
      addStudent(newstudent, table, table2);
      cout << "test3b" << endl;/*DELETE LATER*/
      count++;
    }

    for (int i = 0; i <= 40; i++){
      first[i] = '\0';
      last[i] = '\0';
    }
    id = 0;
    gpa = 0;
    idcheck = 0;
    current = NULL;
    temp = table;
  }
  
}

void addStudent(Student* newstudent, Node** &table, Node** table2){
  int stepcount = 0;
  int hashValue = newstudent->getID() % (sizeof(table2));
  Node** temp = table;
  if(temp[hashValue] == NULL){
    Node* newnode = new Node();
    newnode->setStudent(newstudent);
    table[hashValue] = newnode;
    
  }
  else if (temp[hashValue] != NULL){
    cout << "previous break" << endl;/*DELETE LATER*/
    Node* current = temp[hashValue];
    
    while (current->getNext() != NULL){
      current = current->getNext();
      stepcount++;
    }
    Node* newnode = new Node();
    newnode->setStudent(newstudent);
    current->setNext(newnode);
    if (stepcount >= 2){
      rehash(table, table2);
    }
  }
}


void rehash(Node** &table, Node** table2){
  cout << "REHASH" << endl;/*DELETE LATER*/
  Node** temp = NULL;
  temp = table;

  Node* searcher = NULL;
  Node* current = NULL;
  Node* next = NULL;
  
  Node** newtable = NULL;
  newtable = new Node* [2*sizeof(temp)];
  for(int i = 0; i <= sizeof(temp); i++){
    newtable[i] = NULL;
  }

  for (int i = 0; i <= sizeof(temp); i++){
    if (temp[i] != NULL){
      current = temp[i];
      next = temp[i];
      while(current != NULL){
	next = current->getNext();
	  if(newtable[current->getStudent()->getID() % sizeof(newtable)] == NULL){
	    current->setNext(NULL);
	    newtable[current->getStudent()->getID() % sizeof(newtable)] = current;
	    current = next;
	  }
	  else if (newtable[current->getStudent()->getID() % sizeof(newtable)] != NULL){
	    searcher = newtable[current->getStudent()->getID() % sizeof(newtable)];
	    while(searcher->getNext() != NULL){
	      searcher = searcher->getNext();
	    }
	    current->setNext(NULL);
	    searcher->setNext(current);
	    current = next;
	  }
      }
    }
  }
    delete temp;
    temp = NULL;
    table = newtable;
}

void print(Node** table){
  Node * current = NULL;
  for(int i = 0; i <= sizeof(table); i++){
    if(table[i] != NULL){
      current = table[i];
      while(current != NULL){
	
	cout << current->getStudent()->getFirstName() << " ";
	cout << current->getStudent()->getLastName() << ", ";
	cout << current->getStudent()->getID() << ", ";
	cout.precision(3);
	cout << current->getStudent()->getGPA() << endl;
	current = current->getNext();
      }
    }
  }
}

void deleteStudent(Node** &table, Node** table2, int id){
  bool onlyone = 0;
  if (table2[id % sizeof(table2)] != NULL){
    Node* current = table2[id % sizeof(table2)];
    Node* previous = current;
    while (current != NULL){
      if(current->getStudent()->getID() == id){
	break;
      }
      previous = current;
      current = current->getNext();
    }

    if(current == table2[id % sizeof(table2)]){
      if(current != NULL){
	if (current->getNext() == NULL){
	  delete current;
	  current = NULL;
	  table2[id % sizeof(table2)] = NULL;
	}
	else if(current->getNext() != NULL){
	  table2[id % sizeof(table2)] = current->getNext();
	  delete current;
	  current = NULL;
	}
      }
      else if (current == NULL){
	cout << "Could not find a student with a matching ID" << endl;
      }
    }
    else if (current != table2[id % sizeof(table2)]){
      if(current != NULL){
	previous->setNext(current->getNext());
	delete current;
	current = NULL;
      }
      else if(current == NULL){
	cout << "Could not find a student with a matching ID" << endl;
      }
    }
  }
}


