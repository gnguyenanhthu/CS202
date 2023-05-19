#ifndef _FRACTION_H_
#define _FRACTION_H_

#include <iostream>
using namespace std;

class Fraction {
private:
	int num, denom;
public:
	void reduce();
	Fraction();
	Fraction(int n, int d);
	Fraction(const Fraction &other);
	Fraction(int n);

	Fraction& operator=(const Fraction &other);

	Fraction& operator+(const Fraction &other);
	Fraction& operator-(const Fraction &other);
	Fraction& operator*(const Fraction &other);
	Fraction& operator/(const Fraction &other);

	bool operator==(const Fraction &other);
	bool operator!=(const Fraction &other);
	bool operator>=(const Fraction &other);
	bool operator<=(const Fraction &other);
	bool operator>(const Fraction &other);
	bool operator<(const Fraction &other);

	Fraction& operator+=(const Fraction &other);
	Fraction& operator-=(const Fraction &other);
	Fraction& operator*=(const Fraction &other);
	Fraction& operator/=(const Fraction &other);

	Fraction& operator++();
	Fraction operator++(int);
	Fraction& operator--();
	Fraction operator--(int);

	friend Fraction operator+(const Fraction &x, const Fraction &y);
	friend Fraction operator*(const Fraction &x, const Fraction &y);
	friend Fraction operator-(const Fraction &x, const Fraction &y);

	float operatorfloat();

	friend ostream& operator<<(ostream& output, Fraction x)
	{
		//if we leave it void, it can only return once
		output << x.num << "/" << x.denom << endl;
		return output;
	}
};




#endif // !_FRACTION_H_
