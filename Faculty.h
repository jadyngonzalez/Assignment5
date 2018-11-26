#ifndef FACUILTY_H
#define FACUILTY_H
#include "iPerson.h"
#include "DoublyLinkedList.h"

class Faculty : public iPerson
{
  public:
    Faculty();
    ~Faculty();
    Faculty(string name, string department, unsigned int id);

    string department;
    DoublyLinkedList<unsigned int> students;

    operator string()
    {
      stringstream s;
      s << id << "|" << name << "|" << department;
      ListNode<unsigned int> *curr;
      curr = students.front;
      while(curr != NULL)
      {
        s << "|" << curr->data;
        curr = curr->next;
      }
      return s.str();
    };
};
#endif
