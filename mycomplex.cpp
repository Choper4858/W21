#include<iostream>
#include <cmath>
#include "mycomplex.h"

using namespace std;
/**
 *
 * @param aRe
 * @param aIm
 */
Complex::Complex(double aRe, double aIm) {
	Re = aRe;
	Im = aIm;
}
/**
 *
 * @param aRval
 */
Complex::Complex(const Complex &aRval) {
	Re = aRval.Re;
	Im = aRval.Im;
}
/**
 *
 */
Complex::~Complex() {
	Re = 0.0;
	Im = 0.0;
}
/**
 *
 * @param aRe
 * @param aIm
 */
void Complex::Set(double aRe, double aIm) {
	Re = aRe;
	Im = aIm;
}
/**
 *
 * @return
 */
Complex::operator double() {
	return abs();
}
/**
 *
 * @return
 */
double Complex::abs() {
	return sqrt(Re * Re + Im * Im);
}
/**
 *
 * @param aRval
 * @return
 */
Complex Complex::operator+(const Complex &aRval) {
	Complex Result;
	Result.Re = Re + aRval.Re;
	Result.Im = Im + aRval.Im;
	return Result;
}
/**
 *
 * @param aRval
 * @return
 */
Complex Complex::operator-(const Complex &aRval) {
	Complex Result;
	Result.Re = Re - aRval.Re;
	Result.Im = Im - aRval.Im;
	return Result;
}
/**
 *
 * @param aval
 * @return
 */
Complex Complex::operator+(const double &aval) {
	Complex result;
	result.Re = Re + aval;
	result.Im = Im;
	return result;
}
/**
 *
 * @param aRval
 * @return
 */
Complex Complex::operator-(const double &aRval) {
	Complex Result(*this);
	Result.Re = Re - aRval;
	return Result;
}
/**
 *
 * @param aRval
 * @return
 */
Complex Complex::operator*(const Complex &aRval
) {
	Complex Result;
	Result.Re = Re * aRval.Re - Im * aRval.Im;
	Result.Im = Re * aRval.Im + Im * aRval.Re;
	return Result;
}
/**
 *
 * @param aRval
 * @return
 */
Complex Complex::operator*(const double &aRval) {
	Complex Result;
	Result.Re = Re * aRval;
	Result.Im = Im * aRval;
	return Result;
}
/**
 *
 * @param aRval
 * @return
 */
Complex Complex::operator/(const double &aRval) {
	Complex Result;
	Result.Re = Re / aRval;
	Result.Im = Im / aRval;
	return Result;
}
/**
 *
 * @param arval
 * @return
 */
Complex &Complex::operator+=(const Complex &arval) {
	Re += arval.Re;
	Im += arval.Im;
	return *this;
}
/**
 *
 * @param aRval
 * @return
 */
Complex &Complex::operator-=(const Complex &aRval) {
	Re -= aRval.Re;
	Im -= aRval.Im;
	return *this;
}
/**
 *
 * @param aRval
 * @return
 */
Complex &Complex::operator*=(const Complex &aRval) {
	double tmpRe = Re;
	Re = Re * aRval.Re - Im * aRval.Im;
	Im = Im * aRval.Re + tmpRe * aRval.Im;
	return *this;
}
/**
 *
 * @param aRval
 * @return
 */
Complex &Complex::operator+=(const double &aRval) {
	Re += aRval;
	return *this;
}
/**
 *
 * @param aRval
 * @return
 */
Complex &Complex::operator-=(const double &aRval) {
	Re -= aRval;
	return *this;
}
/**
 *
 * @param aRval
 * @return
 */
Complex &Complex::operator*=(const double &aRval) {
	Re *= aRval;
	Im *= aRval;
	return *this;
}
/**
 *
 * @param aRval
 * @return
 */
Complex &Complex::operator/=(const double &aRval) {
	Re /= aRval;
	Im /= aRval;
	return *this;
}
/**
 *
 * @param aRval
 * @return
 */
Complex &Complex::operator=(const Complex &aRval) {
	Re = aRval.Re;
	Im = aRval.Im;
	return *this;
}
/**
 *
 * @param aRval
 * @return
 */
Complex &Complex::operator=(const double &aRval) {
	Re = aRval;
	Im = 0.0;
	return *this;
}
/**
 *
 * @param stream
 * @param a
 * @return
 */
istream &operator>>(istream &stream, Complex &a) {
	char tmp[256];
	stream >> a.Re >>
	       a.Im >> tmp;
	return stream;
}
/**
 * @brief
 * @param stream
 * @param a
 * @return
 */
ostream &operator<<(ostream &stream, Complex &a) {
	stream << a.Re;
	if (!(a.Im < 0)) stream << '+';
	stream << a.Im << 'i';
	return stream;
}
/**
 *
 * @param aLval
 * @param aRval
 * @return
 */
Complex operator+(const double &aLval, const Complex &aRval) {
	Complex Result;
	Result.Re = aLval + aRval.Re;
	Result.Im = aRval.Im;
	return Result;
}
/**
 *
 * @param aLval
 * @param aRval
 * @return
 */
Complex operator-(const double &aLval, const Complex &aRval) {
	Complex Result;
	Result.Re = aLval - aRval.Re;
	Result.Im = -aRval.Im;
	return Result;
}
/**
 *
 * @param aLval
 * @param a
 * @return
 */
Complex operator*(const double &aLval, const Complex &a) {
	Complex r;
	r.Re = aLval * a.Re;
	r.Im = aLval * a.Im;
	return r;
}
