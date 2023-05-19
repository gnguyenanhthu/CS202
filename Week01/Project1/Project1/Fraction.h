#ifndef _FRACTION_H_
#define _FRACTION_H_

#include<iostream>
using namespace std;

class Fraction {
private:
	int num, denom;
public:
	Fraction(); //default >>> 0/1
	void input(int n, int d);
	void output();
	void reduce();
	Fraction add(Fraction x);
	Fraction substract(Fraction x);
	Fraction multiply(Fraction x);
	Fraction divide(Fraction x);
	void compare(Fraction x);
	void sign();
};

int gcd(int a, int b); //UCLN

#endif