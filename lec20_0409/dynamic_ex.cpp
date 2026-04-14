#include <iostream>

using namespace std;

int main() {
  int *p, *q;

  // Allocating an integer’s worth of space
  p = new int(2);
  cout << "Value of p: " << *p << endl;
  // Deallocating    delete p;
  delete p;

  q = new int[5]; // Allocating an array of 5 integers
  for (int i = 0; i < 5; i++) {
    q[i] = i + 1;
  }
  cout << "Values in q[2]: " << q[2] << endl;

  // Deallocating whole array
  delete[] q;
}
