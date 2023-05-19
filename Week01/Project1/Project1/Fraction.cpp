#include "Fraction.h"

int gcd(int a, int b){
	if (a%b == 0) return b;
	return gcd(b, a%b);
}

Fraction::Fraction() {
	num = 0;
	denom = 1;
}

void Fraction::input(int n, int d) {
	if (d == 0) {
		cout << "Zero denominator!" << endl;
		return;
	}
	num = n;
	denom = d;
}

void Fraction::output() {
	cout << num << "/" << denom << endl;
}

void Fraction::reduce() {
	int x = gcd(num, denom);
	num = num / x;
	denom = denom / x;
}

Fraction Fraction::add(Fraction x) {
	Fraction temp;
	temp.denom = denom*x.denom;
	temp.num = num*x.denom + x.num*denom;
	temp.reduce();
	return temp;
}
Fraction Fraction::substract(Fraction x) {
	Fraction temp;
	temp.denom = denom*x.denom;
	temp.num = num*x.denom - x.num*denom;
	temp.reduce();
	return temp;
}

Fraction Fraction::multiply(Fraction x) {
	Fraction temp;
	temp.num = num*x.num;
	temp.denom = denom*x.denom;
	return temp;
}

Fraction Fraction::divide(Fraction x) {
	Fraction temp;
	temp.num = num*x.denom;
	temp.denom = denom*x.num;
	return temp;
}
void Fraction::compare(Fraction x) {
	Fraction temp;
	temp.num = num; temp.denom = denom;
	temp=temp.substract(x);
	if (temp.num == 0) {
		cout << "2 fractions are equal" << endl;
		return;
	}
	if (temp.denom*temp.num < 0) {
		cout << "The new fraction is bigger" << endl;
		return;
	}
	cout << "The new fraction is smaller" << endl;
}

void Fraction::sign() {
	if (num == 0) {
		cout << "Equal to 0" << endl;
		return;
	}
	if (num*denom < 0) {
		cout << "Negative" << endl;
		return;
	}
	cout << "Positive" << endl;
}