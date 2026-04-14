#include <iostream>
using namespace std;

class PolarComplex {
  double r;
  double theta;

public:
  PolarComplex(double r, double theta) {
    this->r = r;
    this->theta = theta;
  }

  void print() {
    cout << "(" << this->r << " * e^(" << this->theta << "i))" << endl;
  }
};

class Complex {
  double real;
  double imag;

public:
  Complex(double real, double imag) {
    this->real = real;
    this->imag = imag;
  }

  void print() {
    cout << "(" << this->real << " + " << this->imag << ")" << endl;
  }

  Complex operator+(Complex c) {
    return Complex(this->real + c.real, this->imag + c.imag);
  }

  Complex operator*(Complex y) {
    double a = this->real;
    double b = this->imag;
    double c = y.real;
    double d = y.imag;
    return Complex(a * c - b * d, a * d + b * c);
  }

  PolarComplex toPolar() {
    double r = sqrt(this->real * this->real + this->imag * this->imag);
    double theta = atan2(this->imag, this->real);
    return PolarComplex(r, theta);
  }
};

int main() {
  Complex c1 = Complex(2, 4);
  Complex c2 = Complex(3, -5);
  Complex c3 = c1 + c2;
  Complex c4 = c1 * c2;
  Complex c5 = Complex(1, 1);
  PolarComplex p1 = c5.toPolar();
  c3.print();
  c4.print();
  p1.print();
}
