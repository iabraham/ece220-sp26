#include <iostream>

class Person {
  const char *name;
  unsigned int byear;

public:
  Person *next;
  Person(const char *name, unsigned int byear) {
    this->name = name;
    this->byear = byear;
    this->next = NULL;
  }

  Person(const Person &p) {
    this->name = p.name;
    this->byear = p.byear;
    this->next = NULL;
  }

  void print() {
    std::cout << "(" << this->name << " , " << this->byear << ")" << std::endl;
  }
};
