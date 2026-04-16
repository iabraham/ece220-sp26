#include "classdefs.h"
using namespace std;

void inspectVTable(Base *obj) {
  /* Get a pointer to vptr (which is itself a pointer) -> LHS
     RHS -> Make compiler reinterpret Base * as void *** to access vptr

     obj  →  [ vptr | data members... ]
           |
           └──→  [ &func1 | &func2 | &func3 ]  ← the vtable

*/
  void **vptr = *(void ***)obj;

  cout << "Object address: " << obj << endl;
  cout << "vptr (vtable address): " << vptr << endl;

  // Print first few entries of vtable
  cout << "VTable entries:\n";
  for (int i = 0; i < 2; ++i) {
    cout << "  [" << i << "] = " << vptr[i] << endl;
  }

  // Call functions via vtable manually
  cout << "\nCalling via vtable:\n";

  typedef void (*FuncType)(Base *);

  FuncType f0 = (FuncType)vptr[0];
  FuncType f1 = (FuncType)vptr[1];

  f0(obj);
  f1(obj);
}

// driver code
int main() {
  // defining base class pointers
  Base *ptr1 = new Base();
  Base *ptr2 = new Derived1();
  Base *ptr3 = new Derived2();

  // calling all functions
  cout << "----------- using ptr1 -----------" << endl;
  ptr1->function1();
  ptr1->function2();
  ptr1->function3();
  cout << "----------- using ptr2 -----------" << endl;
  ptr2->function1();
  ptr2->function2();
  ptr2->function3();
  cout << "----------- using ptr3 -----------" << endl;
  ptr3->function1();
  ptr3->function2();
  ptr3->function3();

  cout << "\n----------- inspecting vtable for ptr1 -----------" << endl;
  inspectVTable(ptr1);
  cout << "\n----------- inspecting vtable for ptr2 -----------" << endl;
  inspectVTable(ptr2);
  cout << "\n----------- inspecting vtable for ptr3 -----------" << endl;
  inspectVTable(ptr3);

  // deleting objects
  delete ptr1;
  delete ptr2;
  delete ptr3;

  return 0;
}
