#ifndef _ARRAY_H_
#define _ARRAY_H_

#include <iostream>
using namespace std;

class IntArray {
private:
	int n;
	int *a;
public:
	IntArray();
	IntArray(int x);
	IntArray(int p[], int x);
	IntArray(const IntArray &other);

	IntArray& operator=(const IntArray &other);

	int& operator[](const int x);

	operator int();

	friend istream& operator>>(istream& input, IntArray x)
	{
		for (int i = 0; i < x.n; i++) {
			input >> x.a[i];
		}
		return input;
	}

	friend ostream& operator<<(ostream& output, IntArray x)
	{
		for (int i = 0; i < x.n; i++) {
			output << "a[" << i << "] = " << x.a[i] << endl;
		}
		return output;
	}
};

#endif