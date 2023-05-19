#include <iostream>
using namespace std;

class Fraction {
private:
	int num, denom;
public:	
	Fraction();
	Fraction(int x);
	Fraction(int nu, int de);
	Fraction(const Fraction &other);
	Fraction(char *s); // "1/2"
	~Fraction();
};

Fraction::Fraction() {
	num = 0; denom = 1;
}

Fraction::Fraction(int x) {
	num = x; denom = 1;
}

Fraction::Fraction(int nu, int de) {
	if (de == 0) {
		cout << "Zero denominator";
		throw; //sth wrong, can't go further -> stop
	}
	num = nu; denom = de;
}

Fraction::Fraction(const Fraction &other) {
	num = other.num; denom = other.denom;
}

Fraction::Fraction(char *s) {
	int i = 0;
	num = int(s[i]);
	++i;
	while (s[i] != '/') {
		num = num * 10 + int(s[i]);
		++i;
	}
	++i;
	denom = s[i];
	while (s[i]) {
		denom= denom * 10 + int(s[i]);
		++i;
	}
}

Fraction::~Fraction() {
	num = 0; denom = 0;
}