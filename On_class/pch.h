#pragma once
#ifndef PCH_H
#define PCH_H

#include <iostream>
using namespace std;

class Fraction {
private:
	int numerator;
	int denominator;
public:
	//Constructors overload
	Fraction();//default 0/1
			   //new standard: Fraction() = default; 
	Fraction(int t); // t/1
	Fraction(int numer, int deno); // numer/deno
								   //construct new fraction c based on a: Fraction c(a);
	Fraction(const Fraction& a);
	void addX(const Fraction& x);
	void addX(int x);
	//Fraction addTwo(const Fraction& a, const Fraction& b);
	Fraction addTwo(Fraction& a, Fraction& b);
	int compareTwo(const Fraction& a, const Fraction& b);
	void subtract(const Fraction& x);
	void display();
	float showInDecimal();
	bool isNegative();
	bool isLowestTerm();
	Fraction showLowestTerm();
	bool isRational();
	void convertToMixedNumber();
	int compare(Fraction& x);
	int gcd(int a, int b);


	Fraction& operator=(Fraction &x); //copy constructor - shallow copy
	Fraction& operator+=(Fraction& x);
	Fraction& operator+(Fraction& x);
	//Fraction operator+(const Fraction& x, const Fraction& y);
	Fraction operator+(int x);
	//Fraction& operator=(int a);
	Fraction& operator++();
	Fraction operator++(int);
	friend ostream& operator<<(ostream& output, Fraction x)
	{
		//if we leave it void, it can only return once
		output << "numerator: " << x.numerator << " denominator: " << x.denominator <<endl;
		return output;
	}
	friend istream& operator>>(istream& input, Fraction& x);
	// we can either declare ostream and istream in class or outclass, in source.cpp or anywhere else in the project
	
};

class MyArr {
public:
	MyArr();
	MyArr(int k);
	MyArr(const MyArr& prc);
	MyArr & operator=(MyArr & a);
private:
	int n; //number of elements
	int* pArr; //dynamically allocated array
};

#endif