#include <iostream>

using namespace std;

class Person {
  const char *name;
  unsigned int byear;

public:
  Person *next;
  Person(const char *name, unsigned int byear) {
    this->name = name;
    this->byear = byear;
  }
  Person(const Person &p) {
    this->name = p.name;
    this->byear = p.byear;
  }

  friend ostream &operator<<(ostream &os, const Person &p);
  void print() { cout << (*this); }
};

ostream &operator<<(ostream &os, const Person &p) {
  os << "(" << p.name << ", " << p.byear << ")";
  return os;
}

int main() {
  Person *p1 = new Person("Alice", 1990);
  Person *p2 = new Person("Bob", 1985);
  cout << *p1 << endl;
  cout << *p2 << endl;
  return 0;
}
