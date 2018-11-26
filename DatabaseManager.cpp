#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include "DatabaseManager.h"

using namepsace std;

DatabaseManager::DatabaseManager()
{
  srand(time(NULL));
  string input = "";
  version = 0;

  load("Defaullt.txt");

  do
  {
    cout << "Welcome to the Registrar Database. What would you like to do?" << endl;
    cin >> input;
  }
  while(start(atoi(input.c_str())));
}

DatabaseManager::~DataBaseManager()
{
  save("Default.txt");
  cout << "Saved. Now Exiting." << endl;
}

bool DatabaseManager::start(int input)
{
  //prompt user
  switch(input)
  {
    case 0: //Show options
    {
      displayOptions();
      return true;
    }
    case 1: //Print all students and their information (sorted by ascending id #)
    {
      cout << "Printing all students..." << endl;
      if(studentTree.printTree(1) == "")
      {
        cout << "No students found."
        return true;
      }
      cout << studentTree.printTree(1) << endl;
      return true;
    }
    case 2: //Print all faculty and their information (sorted by ascending id #)
    {
      cout << "Printing all faculty..." << endl;
      if(facultyTree.printTree(1) == "")
      {
        cout << "No faculty found.";
        return true;
      }
      cout << facultyTree.printTree(1) << endl;
      return true;
    }
    case 3: //Find and display student information given the students id
    {
      cout << "Enter the student's id #." << endl;
      string s;
      cin >> s;
      printStudents(atoi(s.c_str()));
      return true;
    }
    case 4: //Find and display faculty information given the faculty id
    {
      cout << "Enter the faculty member's id #." << endl;
      string s;
      cin >> s;
      printFaculty(atoi(s.c_str()));
      return true;
    }
    case 5: //Given a student’s id, print the name and info of their faculty advisor
    {
      cout << "Enter the student's id #." << endl;
      string s;
      cin >> s;
      cout << "Displaying advisor." << endl;
      printAdvisor(atoi(in.c_str()));
      return true;
    }
    case 6: //Given a faculty id, print ALL the names and info of his/her advisees
    {
      cout << "Enter the faculty member's id #." << endl;
      string s;
      cin >> s;
      cout << "Displaying Advisees." << endl;
      printAdvisees(atoi(in.c_str()));
      return true;
    }
    case 7: //Add a new student
    {
      string name;
      string level;
      string major;
      string gpa;

      cout << "Enter the new student's name." << endl;
      cin >> name;
      cout << "Enter his/her grade level." << endl;
      cin >> level;
      cout << "Enter his/her major." << endl;
      cin >> major;
      cout << "Enter his/her GPA." << endl;
      cin >> gpa;

      addStudent(name, level, major, atof(gpa.c_str()));
      return true;
    }
    case 8: //Delete a student given the id
    {
      cout << "Enter the id of the student you want to remove." << endl;
      string s;
      cin >> s;
      deleteStudent(atoi(s.c_str()));
      return true;
    }
    case 9: //Add a new faculty member
    {
      string name;
      string level;
      string department;

      cout << "Enter the new member's name." << endl;
      cin >> name;
      cout << "Enter his/her level." << endl;
      cin >> level;
      cout << "Enter his/her department." << endl;
      cin >> department;

      addFaculty(name, level, department);
      return true;
    }
    case 10: //Delete a faculty member given the id
    {
      cout << "Enter the id of the faculty member you want to remove." << endl;
      string s;
      cin >> s;
      deleteFaculty(atoi(in.c_str()));
      return true;
    }
    case 11: //Change a student’s advisor given the student id and the new faculty id
    {
      string s;
      string f;
      cout << "Enter the student's id #." << endl;
      cin >> s;
      cout "Enter the faculty member's id #" << endl;
      cin >> f;
      changeAdvisor(atoi(s.c_str()), atoi(f.c_str()));
      return true;
    }
    case 12: //Remove an advisee from a faculty member given the ids
    {
      string s;
      string f;
      cout << "Enter the student's id #." << endl;
      cin >> s;
      cout "Enter the faculty member's id #." << endl;
      cin >> f;
      removeAdvisee(atoi(s.c_str()), atoi(f.c_str()));
      return true;
    }
    case 13: //Rollback
    {
      /*
        history.pop();
        upate new trees
        delete old tree
      */
      return true;
    }
    case 14: //Exit;
    {
      /*
        save to file and exit
      */
      exit(0);
    }
  }
}

void DatabaseManager::displayOptions()
{
  cout << "0. Reprint all the options" << endl;
 cout << "1. Print all students and their information (sorted by ascending id #)" << endl;
 cout << "2. Print all faculty and their information (sorted by ascending id #)" << endl;
 cout << "3. Find and display student information given the students id" << endl;
 cout << "4. Find and display faculty information given the faculty id" << endl;
 cout << "5. Given a student’s id, print the name and info of their faculty advisor" << endl;
 cout << "6. Given a faculty id, print ALL the names and info of his/her advisees." << endl;
 cout << "7. Add a new student" << endl;
 cout << "8. Delete a student given the id" << endl;
 cout << "9. Add a new faculty member" << endl;
 cout << "10. Delete a faculty member given the id." << endl;
 cout << "11. Change a student’s advisor given the student id and the new faculty id." << endl;
 cout << "12. Remove an advisee from a faculty member given the ids" << endl;
 cout << "13. Rollback" << endl;
 cout << "14. Exit" << endl;
}

TreeNode<Faculty>* DataBaseManager::assignAdvisor()
{
  if(facultyTree.isEmpty())
  {
    return NULL;
  }
  else
  {
    unsigned int idx = rand()%facultyTree.getSize();
    return facultyTree.getKey(idx);
  }
}

bool DatabaseManager::assignID(string type)
{
  if(type == "student")
  {
    Student temp;
    unsigned int count = 0;
    do
    {
      temp.id = rand() % 8999999 + 1000000;
      if(++count > 1000000)
      {
        return 0
      }
    }
    while(studentTree.contains(temp));
    return 0;
  }
}

bool DatabaseManager::addStudent(string name, string level, string major, double gpa)
{
  Student new;
  new.name = name;
  new.level = level;
  new.major = major;
  new.gpa = gpa;
  new.id = assignID("student");

  TreeNode<Faculty> *temp;
  temp = assignAdvisor();
  /*
    find advisor
    add student to advisor listd
  */
  return true;
}

bool DatabaseManager::addFaculty(string name, string level, string department)
{
  Faculty new;
  new.name = name;
  new.level = level;
  new.department = department;
  new.id = assignID("faculty");
  facultyTree.insert(new);
  return true;
}

bool DatabaseManager::save(string fileName) //broke program
{
  //tbd
}

bool DatabaseManager::load(string fileName) //broke program many non void and undefined reference errors
{
  //tbd
}

bool DataBaseManager::printStudents(unsigned int id)
{
  Student temp;
  temp.id = id;
  TreeNode<Student> *curr;
  curr = studentTree.find(temp);
  cout << curr->key << endl;
}

bool DataBaseManager::printFaculty(unsigned int id)
{
  Faculty temp;
  temp.id = id;
  TreeNode<Faculty> *curr;
  curr = facultyTree.find(temp);
  cout << curr->key << endl;
}

bool DataBaseManager::printAdvisees(unsigned int id) //tbd
{
  /*
    find faculty from tree
    if found print all students in faculty list
    find each student from student tree and output info.
  */
}

bool DataBaseManager::deleteStudent(unsigned int id)
{
  Student temp;
  temp.id = id;

  //will need to remove from faculty members list

  studentTree.find(temp);
  studentTree.deleteNode(temp);
}

bool DataBaseManager::deleteFaculty(unsigned int id)//tbd
{
  /*
    find faculty in tree
    save students in a temp List
    random add students to new faculty members
    delete faculty member
  */
}

bool DataBaseManager::changeAdvisor(unsigned int sid, unsigned int fid)
{
  /*
    find student in trees
    find faculty member
    save student
    remove from existing faculty
    insert student into new faculty
  */
}

bool DatabaseManager::removeAdvisee(unsigned int sid, unsigned int fid)
{
  /*
    find faculty
    find student
    delete student from List
    delete student from tree
  */
}

bool DatabaseManager::rollback()
{
  /*
    pop off old version of tree from stack
    update current trees with old versions
    continue
  */
}
