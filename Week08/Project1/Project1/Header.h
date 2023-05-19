#ifndef _HEADER_H_
#define _HEADER_H_

#include <iostream>
#include <string>
using namespace std;

class Fraction {
public:
	int num, denom;
	Fraction() {
		num = 0; denom = 1;
	}
	Fraction(int a, int b) {
		num = a; denom = b;
	}
};

void inputfraction(Fraction &x) {
	cout << "Num : "; cin >> x.num;
	cout << "Denom : "; cin >> x.denom;
}

class ZeroException {
public:
	char *Error();
};

char* ZeroException::Error() {
	return "Devided by zero";
}

template <class T>
void init(T *a, int &n) {
	a = new int[n];
	for (int i = 0; i < n; i++) 
		a[i] = 0;
	
}

template <class T>
void add(T *a, int &n, T x) {
	for (int i = 0; i < n; i++) {
		if (a[i]==0) {
			a[i] = x;
			break;
		}
	}
}

template <class T>
void remove(T *a, int &n) {
	for (int i = 0; i < n-1; i++) {
		if (a[i+1] == 0) {
			a[i] = 0;
			break;
		}
	}
	a[n] = 0;
}

template <class T>
void search(T *a, int &n, T x) {
	for (int i = 0; i < n; i++) {
		if (a[i]==x) {
			cout << "Found your element at." << i << endl;
		}
	}
	cout << "Can't find your element." << endl;
}

template <class T>
void inputarray(T *a, int &n) {
	a = new T[n];
	for (int i = 0; i < n; i++) {
		cout << "Input " << i + 1 << " element: ";
		cin >> a[i];
	}
}

template <class T>
void output(T *a, int &n) {
	for (int i = 0; i < n; i++) {
		cout << "Output array: ";
		cout << a[i] << " ";
	}
	cout << endl;
}

template <>
void inputarray(string *a, int &n) {
	a = new string[n];
	for (int i = 0; i < n; i++) {
		cout << "Input string: ";
		getline(cin, a[i]);
	}
}

template<>
void inputarray(Fraction *a, int &n) {
	a = new Fraction[n];
	for (int i = 0; i < n; ++i) {
		cout << "Input " << i + 1 << " element:";
		try {
			cout << "Input numerator : ";
			cin >> a[i].num;
			cout << "Input denominator";
			cin >> a[i].denom;
			if (a[i].denom == 0) throw new ZeroException;
		}
		catch (ZeroException *ex) {
			cout << "ERROR :" << ex->Error() << endl;
		}
	}
}


ostream& operator <<(ostream& out, const Fraction& x) {
	out << x.num << "/" << x.denom << endl;
	return out;
}


Fraction& operator >(Fraction& x, Fraction& y) {
	if (x.num*y.denom > y.num*x.denom)
		return x;
	return y;
}

bool operator ==(const Fraction& x, const Fraction& y) {
	if (((float)x.num / x.denom) == ((float)y.num / y.denom))
		return true;
	return false;
}

Fraction& operator +=(const Fraction& a, const Fraction& b) {
	Fraction temp;
	temp.num = a.num*b.denom + b.num*a.denom;
	temp.denom = a.denom * b.denom;
	return temp;
}

template <class T>
int count(T *a, int &n, T x) {
	int c;
	for (int i = 0; i < n; i++) {
		if (a[i] == x)
			++c;
	}
	return c;
}

template <class T>
int size(T *a, int &n) {
	int c;
	for (int i = 0; i < n; i++) {
		if (a[i]==0) return c;
		c++;
	}
	return c;
}


template<class T>
T sum(T *a, int& n) {
	T s = a[0];
	for (int i = 1; i < n; ++i) {
		s += a[i];
	}
	return s;
}

#endif 

