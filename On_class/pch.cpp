#include "pch.h"

Fraction::Fraction() {//default value, safe state
	numerator = 0;
	denominator = 1;
}

Fraction::Fraction(int t) {
	numerator = t;
	denominator = 1;
}

//throw
Fraction::Fraction(int num, int deno) { //no data type to return
	if (deno == 0) {
		cout << "error" << endl;
		throw; //-------
	}
	else {
		numerator = num;
		denominator = deno;
	}
}

Fraction::Fraction(const Fraction& a) {
	numerator = a.numerator;
	denominator = a.denominator;

}

void Fraction::display() {
	if (denominator == 1)
		cout << numerator;
	else {
		cout << numerator << "/"
			<< denominator << endl;
	}
}

void Fraction::addX(const Fraction& x) {
	numerator = numerator * x.denominator + x.numerator * denominator;
	denominator = denominator * x.denominator;
	int gcdivisor = gcd(numerator, denominator);
	numerator /= gcdivisor;
	denominator /= gcdivisor;
}

void Fraction::addX(int x) {
	numerator += x * denominator;
	int gcdivisor = gcd(numerator, denominator);
	numerator /= gcdivisor;
	denominator /= gcdivisor;
}

Fraction Fraction::addTwo(Fraction& a, Fraction& b) {
	int nume = a.numerator*b.denominator + b.numerator*a.denominator;
	int deno = a.denominator*b.denominator;
	nume = nume / gcd(nume, deno);
	deno = deno / gcd(nume, deno);
	Fraction c(nume, deno);

	return c;
}

/*int Fraction::compareTwo(const Fraction& a, const Fraction& b) {

Fraction midB(1, 1), midA(1, 1);


}*/

int Fraction::gcd(int a, int b) {
	while (a != b) {
		if (a > b)
			a -= b;
		else
			b -= a;
	}
	return a;
}

Fraction& Fraction::operator=(Fraction& x) {
	numerator = x.numerator;
	denominator = x.denominator;

	return *this;
	//return c;
}

Fraction& Fraction::operator+=(Fraction& x)
{
	numerator = x.numerator*denominator + x.denominator*numerator;
	denominator = numerator*denominator;
	return *this;
}
/*
Fraction Fraction::operator+(const Fraction& x, const Fraction& y)
{
	Fraction tmp(x);
	tmp += y;
	return tmp;

}
*/

Fraction& Fraction::operator+(Fraction& x)
{
	int newdenom = denominator*x.denominator;
	int newnum = numerator*x.denominator + denominator*x.numerator;
	return Fraction(newnum,newdenom);
	
}

Fraction Fraction::operator+(int x)
{
	
	int newnum = numerator + denominator*x;
	return Fraction(newnum,denominator);

}

Fraction& Fraction::operator++() //prefix
{
	numerator += denominator;
	return *this;
}
Fraction Fraction::operator++(int) //postfix
{ // rec is an old version of *this + a copy of *this, it will be deleted immediately after the function finishes.
	// if we return by reference (&), it would be dangerous Fraction will be deleted
	Fraction rec(*this);
	++*this; // other option: numerator= numerator+denominator;
	return rec;

}
//ostream& Fraction::operator<<(ostream& output, const Fraction&x)

MyArr::MyArr(const MyArr& arc)
{
	n = arc.n;
	for (int i = 0; i < n; i++)
	{
		pArr[i] = arc.pArr[i];
	}
}

MyArr& MyArr::operator=(MyArr &a)
{
	if (this == &a) return *this;
	n = a.n;
	pArr = new int[n];
	for (int i = 0; i < n; i++)
	{
		pArr[i] = a.pArr[i];
	}
	return *this;

}

istream& operator>>(istream& input, Fraction x);
istream& operator>>(istream& input, Fraction& x)
{
	input >> x.numerator >> x.denominator;
	return input;
}