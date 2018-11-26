#include "Student.h"

Student::Student():iPerson()
{
  major = "none";
  gpa = 0.0;
  advisor = 0;
}

Student::~Student()
{
  //tbd
}

Student::Student(string n, string m, double g, unsigned int i):iPerson()
{
  name = n;
  major = m;
  gpa = g;
  id = i;
  advisor = 0;
}
