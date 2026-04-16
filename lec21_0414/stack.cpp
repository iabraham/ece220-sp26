#include "LinkedList.h"
#include <iostream>

void LinkedList::print_list() {
  Person *cursor = head;
  while (cursor) {
    cursor->print();
    cursor = cursor->next;
  }
}

void LinkedList::add_at_head(Person p) {
  Person *new_p = new Person(p);
  if (head == NULL)
    head = new_p;
  else {
    new_p->next = head;
    head = new_p;
  }
}

void LinkedList::del_at_head() {
  if (head == NULL)
    return;
  else {
    Person *temp = head;
    head = head->next;
    delete temp;
  }
}

LinkedList::~LinkedList() {
  while (head)
    del_at_head();
}

class Stack : protected LinkedList {
public:
  void push(Person p) { add_at_head(p); }

  Person pop() {
    Person temp = *head;
    del_at_head();
    return temp;
  }

  void print_stack() { LinkedList ::print_list(); }
};

int main() {
  // Define the names and birth years of some presidents
  const char *blue_names[] = {"Biden", "Carter", "Obama", "Clinton"};
  unsigned int blue_years[] = {1942, 1924, 1961, 1946};

  // Define the names and birth years of some presidents
  const char *red_names[] = {"Reagan", "Bush", "Trump", "Nixon"};
  unsigned int red_years[] = {1911, 1946, 1946, 1913};

  Stack prez_list;

  for (int i = 0; i < 4; i++) {
    Person p = Person(blue_names[i], blue_years[i]);
    prez_list.push(p);
  }

  prez_list.print_stack();
  std::cout << "----------------" << std::endl;
  Person pp = prez_list.pop();
  std::cout << "We popped:" << std::endl;
  pp.print();
  std::cout << "----------------" << std::endl;
  prez_list.print_stack();
}
