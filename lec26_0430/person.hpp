#include <iostream>

using namespace std;

class Person {
  string name;
  int age;

public:
  Person(string n, int age) {
    name.assign(n);
    this->age = age;
  }

  Person(const Person &p) {
    name.assign(p.name);
    age = p.age;
  }

  friend ostream &operator<<(ostream &os, const Person &p) {
    os << "(" << p.name << ", " << p.age << ")";
    return os;
  }

  bool operator<(const Person &right) const { return (age < right.age); }

  string get_name() const { return name; }
};
