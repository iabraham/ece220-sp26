#include <iostream>
using namespace std;

int main() {
  int val = 10;
  int aint = 40;
  int *pa = &aint;
  int *ptr = &val; // & to get address
  int &ref = val;  // & to declare reference

  cout << "val  = " << val << endl;
  cout << "*ptr = " << *ptr << endl;
  cout << "ref  = " << ref << endl;

  ref = 20;
  cout << endl << "val = " << val << endl;

  val = 30;
  cout << "ref = " << ref << endl;
  ref = *pa;

  cout << "ptr = " << ptr << endl;
  cout << "ptr = " << ptr << endl;
}
