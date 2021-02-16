/*
  Starting code for the first part of Lecture 7's worksheet.
*/

#include <iostream>

using namespace std;

class Complex {
public:
  Complex(double re = 0.0, double im = 0.0);

  // addition of complex numbers
  Complex operator+(Complex rhs);
  Complex operator-(Complex rhs);
  Complex operator*(Complex rhs);
  Complex operator~();
  friend istream& operator>>(istream& in, Complex cplx);

  // declaring a function a "friend" means it can access
  // the private members of the class
  friend ostream& operator<<(ostream& out, Complex cplx);

private:
  double real, imag;
};

Complex::Complex(double re, double im) {
  real = re;
  imag = im;
}

Complex Complex::operator-(Complex rhs) {
  return Complex(real - rhs.real, imag - rhs.imag);
}

Complex Complex::operator*(Complex rhs) {
  return Complex(((real * rhs.real) - (imag * rhs.imag)), ((real * rhs.imag) - (imag * rhs.real)));
}

Complex Complex::operator~() {
  return Complex(-real, -imag);
}

Complex Complex::operator+(Complex rhs) {
  return Complex(real + rhs.real, imag + rhs.imag);
}

istream& Complex::operator>>(istream& in, Complex cplx){
  return in >> cplx.real >> cplx.imag;
}

ostream& Complex::operator<<(ostream& out, Complex cplx) {
  // even though this is not in the scope of Complex, we can still
  // access the .real and .imag attributes because this function was
  // declared a friend
  return out << cplx.real << ' ' << cplx.imag << 'i';
}


int main() {
  Complex a(1.0, 2.0), b(3.4, 5.0);

  cout << a+b << endl;
  cout << a-b << endl;
  cout << a * b << endl;
  cout << ~a << endl;

  return 0;
}
