//Person interface
#ifndef IPERSON_H
#define IPERSON_H
#include <iostream>
#include <sstream>

class iPerson
{
  public:
    string name;
    unsigned int id;

    iPerson();
    ~iPerson()

    bool operator == (const Person& s);
    bool operator == (const int s);
    bool operator != (const Person& s);
    bool operator < (const Person& s);
    bool operator > (const Person& s);

    operator string()
    {
      stringstream s;
      s << id;
      return s.str();
    };
};
