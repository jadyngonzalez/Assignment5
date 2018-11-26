#ifndef LISTNODE_H
#define LISTNODE_H

using namespace std;

template <class T>
class ListNode
{


public:
  ListNode *next;
  ListNode *prev;
  T data;

  ListNode()
  {
    next = NULL;
    prev = NULL;


  };
  ListNode(T d)
  {
    ListNode();
    data = d;
  };
  ~ListNode()
  {


    next = NULL;

    prev = NULL;
  };
};
#endif
