
/** \file mycomplex.cpp
   - Project:     SOFTSUSY 
   - Author:      Ben Allanach 
   - Manual:      hep-ph/0104145, Comp. Phys. Comm. 143 (2002) 305 
   - Webpage:     http://hepforge.cedar.ac.uk/softsusy/

*/

#include "mycomplex.h"

const Complex & Complex::operator=(const Complex & s) {
  if (this == &s) return *this;
  re = s.re; im = s.im; 
  return *this;
}

bool Complex::operator>=(const Complex & a) const {
  if (real() >= a.real() || imag() >= a.imag()) return true;
  else
  return false;
}

double Complex::mod() const { return sqrt(sqr(real()) + sqr(imag())); }

double Complex::arg() const { 
  if (real() == 0. && imag() == 0.) return 0.;
  if (fabs(real() / imag()) < EPSTOL) 
      {
	if (imag() < 0.0) return - PI * 0.5;
	return PI * 0.5;
      }
  if (real() < 0.0 && imag() < 0.0) return -PI + atan( imag() / real() );
  if (real() < 0.0) return PI + atan( imag() / real() );
  return atan( imag() / real() ); 
}

Complex Complex::conj() const {
  return Complex( real(), -imag() );
}

Complex operator+(const Complex & a, const Complex & b) {
  return Complex(a.real() + b.real(), a.imag() + b.imag());
}

Complex Complex::operator*(const Complex & b) const {
  return Complex(re * b.re - im * b.im, im * b.re + b.im * re);
}

Complex operator*(double a, const Complex & b) {
  return Complex(a * b.real(), a * b.imag());
}

Complex Complex::operator*(const double & b) const {
  return Complex(b * real(), b * imag());
}

Complex Complex::operator/(double b) const {
  return Complex(real() / b, imag() / b);
}

Complex Complex::cc() const {
  return Complex(real(), -imag());
}

Complex Complex::operator/(const Complex & a) const {
  return Complex(*this * a.cc()) / sqr(a.mod());
}

Complex Complex::operator-(const Complex & a) const {
  return Complex(real() - a.real(), imag() - a.imag());
}

Complex operator/(double a, const Complex & b) {
  Complex one(a);
  return one / b;
}

Complex operator-(double b, const Complex & a) {
  return Complex(b - a.real(), -a.imag());
}

ostream & operator <<(ostream &left, const Complex &s) {
  left << s.real();
  if (s.imag() >= 0.0) left << "+";
  left << s.imag() << "i";
  return left;
}

// Principal log
Complex log(const Complex & a) {
  double theta = a.arg();
  if ((theta / PI) > 1.0 || (theta / PI) < -1.0)
    {
      theta = theta - floor(theta / PI) * PI;
    }

  Complex temp(log(a.mod()), a.arg());
  return temp;
}

Complex sqrt(const Complex & a) {
  return exp(0.5 * log(a));
}

Complex exp(const Complex & a) {
  double r = exp(a.real()), theta = a.imag();
  Complex temp(r * cos(theta), r * sin(theta));
  return temp;
}



