#include <iostream>
using namespace std;

// base class
class Base {
public:
  virtual void function1() { cout << "Base function1()" << endl; }
  virtual void function2() { cout << "Base function2()" << endl; }
  virtual void function3() { cout << "Base function3()" << endl; }
};

// class derived from Base
class Derived1 : public Base {
public:
  void function1() { cout << "Derived1 function1()" << endl; }
  // not overriding function2() and function3()
};

// class derived from Derived1
class Derived2 : public Derived1 {
public:
  void function2() { cout << "Derived2 function2()" << endl; }
  // not overriding function1() and function3()
};
