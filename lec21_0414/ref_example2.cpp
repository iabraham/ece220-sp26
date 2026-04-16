#include <iostream>
using namespace std;

struct test {
  double a;
  int &ref;
};

int main() {
  int a = 10;
  test t = {30.0, a};
  cout << "t.a: " << t.a << endl;
  cout << "t.ref: " << t.ref << endl;
  a = 40;
  cout << "t.ref: " << t.ref << endl;

  cout << "Size of test.ref: " << sizeof(t) << endl;
  return 0;
}
