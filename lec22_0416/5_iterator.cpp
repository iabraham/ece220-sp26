#include <iostream>
#include <iterator> // for iterators
#include <vector>   // for vectors

using namespace std;

int main() {
  vector<char> cr = {'E', 'C', 'E', '2', '2', '0'};
  vector<int> ir = {1, 2, 3, 4, 5};

  cout << "The vector elements are : ";
  for (auto ptr = cr.begin(); ptr < cr.end(); ptr++)
    cout << *ptr << " ";

  cout << "The vector elements are : ";

  for (auto ptr = ir.begin(); ptr < ir.end(); ptr++)
    cout << *ptr << " ";

  return 0;
}
