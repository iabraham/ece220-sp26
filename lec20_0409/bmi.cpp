#include <iostream>

float bmi(float ht, float wt, bool si = false) {
  float val = wt / (ht * ht);
  if (si)
    return val * 10000;
  else
    return val * 703;
}

using namespace std;

int main(void) {
  char n;
  float ht, wt;
  cout << "Enter height: ";
  cin >> ht;
  cout << "Enter weight: ";
  cin >> wt;

  cout << "From european system?";
  cin >> n;
  if ((n == 'y') || (n == 'Y'))
    cout << "BMI: " << bmi(ht, wt, true) << endl;
  else
    cout << "BMI: " << bmi(ht, wt) << endl;

  return 0;
}
