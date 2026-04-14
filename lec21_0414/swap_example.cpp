#include <iostream>

using namespace std;

// void swap(int *a, int *b) {
//   int temp = *a;
//   *a = *b;
//   *b = temp;
// }

void swap(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}

int main() {

  int a = 10;
  int b = 20;
  cout << "A = " << a << endl;
  cout << "B = " << b << endl;
  swap(a, b);
  cout << " ------- " << endl;
  cout << "A = " << a << endl;
  cout << "B = " << b << endl;
}
