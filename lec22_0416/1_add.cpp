#include <iostream>
using namespace std;

// Create templated definition of Add
template <typename T> T Add(T a, T b) { return a + b; }

// Overload templated Add definition to add T1 to T2 and return T2
template <typename T1, typename T2> T1 Add(T1 a, T2 b) { return a + b; }

int main() {
  cout << Add(1, 3) << endl;      // Integers
  cout << Add(1.2, 3.5) << endl;  // Doubles
  cout << Add(1.2, 3.5f) << endl; // Mixed
  cout << Add(2, 'C') << endl;
}
