#include <iostream>
using namespace std;

// Create templated definition of Add

// Overload templated Add definition to add T1 to T2 and return T2

int main() {
  cout << Add(1, 3) << endl;      // Integers
  cout << Add(1.2, 3.5) << endl;  // Doubles
  cout << Add(1.2, 3.5f) << endl; // Mixed
  cout << Add(2, 'C') << endl;
}
