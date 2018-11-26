#ifndef STUDENT_H
#define STUDENT_H
#include "iPerson.h"

class Student : public iPerson
{
  public:
    string major;
    double gpa;
    unsigned int advisor;

    Student();
    ~Student();
    Student(string name, string grade, string major, double gpa, unsigned int id);

    operator string()
    {
      stringstream s;
      s << id << "|" << name << "|" << major << "|" << gpa << "|" << advisor;
      return s.str();
    };
};
#endif
