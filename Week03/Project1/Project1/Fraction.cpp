#include "Fraction.h"

static int gcd(int a, int b) {
	if (a%b == 0) return b;
	return gcd(b, a%b);
}

void Fraction::reduce() {
	int x = gcd(num, denom);
	num = num / x;
	denom = denom / x;
}

Fraction::Fraction() {
	num = 0; denom = 1;
}

Fraction::Fraction(int n, int d) {
	num = n; denom = d;
}

Fraction::Fraction(const Fraction &other) {
	num = other.num; denom = other.denom;
}

Fraction::Fraction(int n) {
	num = n; denom = 1;
}

Fraction& Fraction::operator=(const Fraction &other) {
	num = other.num;
	denom = other.denom;
	return *this;
}

Fraction& Fraction::operator+(const Fraction &other) {
	return Fraction(num*other.denom + other.num*denom, denom*other.denom);
}

Fraction& Fraction::operator-(const Fraction &other) {
	return Fraction(num*other.denom - other.num*denom, denom*other.denom);
}

Fraction& Fraction::operator*(const Fraction &other) {
	return Fraction(num*other.num, denom*other.denom);
}

Fraction& Fraction::operator/(const Fraction &other) {
	return Fraction(num*other.denom, denom*other.num);
}

bool Fraction::operator==(const Fraction &other) {
	return (num*other.denom == other.num*denom);
}

bool Fraction::operator!=(const Fraction &other) {
	return !(*this == other);
}

bool Fraction::operator>=(const Fraction &other) {
	return (*this == other) || (num*other.denom > other.num*denom);
}

bool Fraction::operator<=(const Fraction &other) {
	return (*this == other) || (num*other.denom < other.num*denom);
}

bool Fraction::operator>(const Fraction &other) {
	return (num*other.denom > other.num*denom);
}

bool Fraction::operator<(const Fraction &other) {
	return (num*other.denom < other.num*denom);
}

Fraction operator+(const Fraction &x, const Fraction &y) {
	Fraction temp(x);
	temp += y;
	return temp;
}

Fraction operator*(const Fraction &x, const Fraction &y) {
	Fraction temp(x);
	temp *= y;
	return temp;
}

Fraction operator-(const Fraction &x, const Fraction &y) {
	Fraction temp(x);
	temp -= y;
	return temp;
}

Fraction& Fraction::operator+=(const Fraction &other) {
	return *this = (*this + other);
}

Fraction& Fraction::operator-=(const Fraction &other) {
	return *this = (*this - other);
}

Fraction& Fraction::operator*=(const Fraction &other) {
	return *this = (*this * other);
}

Fraction& Fraction::operator/=(const Fraction &other) {
	return *this = (*this / other);
}
Fraction& Fraction::operator++() {
	num += denom;
	reduce();
	return *this;
}

Fraction Fraction::operator++(int) {
	Fraction temp(*this);
	num += denom;
	reduce();
	return temp;

}
Fraction& Fraction::operator--() {
	num -= denom;
	reduce();
	return *this;
}

Fraction Fraction::operator--(int) {
	Fraction temp(*this);
	num -= denom;
	reduce();
	return temp;
}

float Fraction::operatorfloat() {
	float r;
	r = num / denom;
	return (r);
}



