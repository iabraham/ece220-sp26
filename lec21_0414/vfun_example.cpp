#include <iostream>
using namespace std;

class Animal {
public:
  virtual void eat() { cout << "I'm eating food." << endl; }
};

class Cat : public Animal {
public:
  void eat() { cout << "I'm eating a mouse." << endl; }
};

class Dog : public Animal {
public:
  void eat() { cout << " I am eating kibble" << endl; }
};

void eat_lunch(Animal *a) { a->eat(); }

int main() {

  Dog *bruno = new Dog();
  bruno->eat();

  eat_lunch(bruno);

  return 0;
}
