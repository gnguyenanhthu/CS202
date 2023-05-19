#include <iostream>
using namespace std;

class MyArray {
private:
	int *a;
	int n;
public:
	MyArray();
	MyArray(int n);
	MyArray(int b[], int m);
	~MyArray();
};

MyArray::MyArray() {
	a = NULL;
	n = 0;
}

MyArray::MyArray(int n) {
	this->n = n;
	a = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
}

MyArray::MyArray(int b[], int m) {
	n = m;
	a = new int[n];
	for (int i = 0; i < n; i++) {
		b[i] = a[i];
	}
}

MyArray::~MyArray() {
	delete[] a;
	n = 0;
}
