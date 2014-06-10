
/** \file mycomplex.h
   - Project:     SOFTSUSY 
   - Author:      Ben Allanach 
   - Manual:      hep-ph/0104145, Comp. Phys. Comm. 143 (2002) 305 
   - Webpage:     http://hepforge.cedar.ac.uk/softsusy/
   - Description: complex numbers and operators between them

   \brief Complex class - standard complex algebra
*/

#ifndef COMPLEX_H
#define COMPLEX_H

#include <cstdlib>
#include <iostream>
#include <cmath>
#include "def.h"
#include "utils.h"

/// "Home-grown" complex class with some complex algebra included
class Complex {
private:
  double re, im; ///< Real and imaginary parts
public:
  Complex() : re(0.0), im(0.0) {}; ///< Empty (zero) constructor
  Complex(double r) : re(r), im(0.0) {}; ///< Real number constructor
  Complex(double r, double i) : re(r), im(i) {}; ///< General constructor
  /// Constructor, setting equal to another Complex number
  Complex(const Complex & cc) : re(cc.re), im(cc.im) {};
  /// Sets contents equal to another Complex number
  const Complex &operator=(const Complex & s);

  double real() const { return re; } ///< returns real part
  double imag() const { return im; } ///< returns imaginary part
  
  void setRe(double a) { re = a; } ///< sets real part
  void setIm(double a) { im = a; } ///< sets imaginary part

  double mod() const; ///< returns modulus of number
  double arg() const; ///< returns angle (in Argand diagram): theta=-pi->pi

  Complex conj() const; ///< Complex conjugate

  Complex operator/(double b) const;
  Complex operator*(const Complex & b) const;  
  Complex operator*(const double & a) const;
  /// Returns true if either real part or imaginary part is bigger than
  /// relevant bit of a
  bool operator>=(const Complex & a) const;
  Complex operator/(const Complex & a) const;
  Complex cc() const; ///< Complex conjugate
  Complex operator-(const Complex & a) const;
};

Complex log(const Complex &a); ///< Principal log
Complex exp(const Complex &a);
Complex sqrt(const Complex &a);

Complex operator*(double a, const Complex & b);
Complex operator+(const Complex & a, const Complex & b);
Complex operator/(double a, const Complex & b);
Complex operator-(double b, const Complex & a);
/// Formatted output
ostream & operator <<(ostream & , const Complex &);
/// Formatted input
inline istream & operator >> (istream & left, Complex & v){
  double r, i;
  left >> r >> i;
  v.setRe(r); v.setIm(i);
  return left;
}

#endif
