#include "Array.h"

IntArray::IntArray() {
	n = 0;
	a = NULL;
}

IntArray::IntArray(int x) {
	n = x;
	a = new int[n];
}

IntArray::IntArray(int p[], int x) {
	n = x;
	a = new int[n];
	for (int i = 0; i < n; i++) {
		a[i] = p[i];
	}
}

IntArray::IntArray(const IntArray &other) {
	n = other.n;
	a = new int[n];
	for (int i = 0; i < n; i++) {
		a[i] = other.a[i];
	}
}

IntArray& IntArray::operator=(const IntArray &other) {
	n = other.n;
	a = new int[n];
	for (int i = 0; i < n; i++) {
		a[i] = other.a[i];
	}
	return *this;
}

int& IntArray::operator[](const int x) {
	return a[x];
}

IntArray::operator int() {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += a[i];
	}
	return sum;
}