#include <iostream>

// You need to make "LinkedList.h" based on 3_linked_list.cpp
// Modify it appropriately to create a new header file
// so that this file compiles and executes

#include "LinkedList.h"

using namespace std;

class Person {
  const char *name;
  unsigned int byear;

public:
  Person *next;
  Person(const char *name, unsigned int byear);
  Person(const Person &p);
  friend ostream &operator<<(ostream &os, const Person &p);
  void print() { cout << (*this); }
};

/* Cosntructor */
Person::Person(const char *name, unsigned int byear) {
  this->name = name;
  this->byear = byear;
}

/* Copy Constructor */
Person::Person(const Person &p) {
  this->name = p.name;
  this->byear = p.byear;
}

/* Overloading << operator, allows the print() function above to work. */
ostream &operator<<(ostream &os, const Person &p) {
  os << "(" << p.name << ", " << p.byear << ")";
  return os;
}

int main() {

  const char *names_dems[] = {"Biden", "Carter", "Obama", "Clinton"};
  unsigned int years_dems[] = {1942, 1924, 1961, 1946};

  const char *names_reps[] = {"Reagan", "Bush", "Trump", "Nixon"};
  unsigned int years_reps[] = {1911, 1946, 1946, 1913};

  // A proper LinkedList.h file will remove error from below line
  LinkedList<Person> PrezList;

  for (int i = 0; i < 4; i++) {
    Person p = Person(names_dems[i], years_dems[i]);
    PrezList.add_at_head(p);
  }
  PrezList.print_list();
  printf("\n------------------------\n");

  for (int i = 0; i < 4; i++) {
    Person p = Person(names_reps[i], years_reps[i]);
    PrezList.add_at_head(p);
  }
  PrezList.print_list();
}
