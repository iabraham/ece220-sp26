#include "Person.h"
#include <iostream>

class LinkedList {

protected:
  Person *head;

public:
  LinkedList() { head = NULL; }

  void print_list();
  void add_at_head(Person p);
  void del_at_head();
  ~LinkedList();
};
