#include "Header.h"

int main() {
	int choose = 0, n;
	cout << "Type of array: ";
	cout << "1/ Integer numbers." << endl;
	cout << "2/ Float numbers." << endl;
	cout << "3/ Fractions." << endl;
	cout << "4/ Strings." << endl;
	cout << "Input your choice : "; cin >> choose;
	
	cout << "Number of elements : ";
	cin >> n;
	switch (choose) {
	case 1: {
		int *a = NULL;
		int x;

		inputarray(a, n);
		output(a, n);
		cout << "Input x: ";
		cin >> x;
		search(a, n, x);
		add(a, n, x);
		cout << "Added x to the end of the array." << endl;
		cout << "Size of the aray: " << size(a, n) << endl;
		cout << "Sum of element : " << sum(a, n) << endl;
		cout << x << " frequency : " << count(a, n, x) << endl;
		remove(a, n);
		cout << "Removed the last element." << endl;

		delete[] a;
		a = NULL;
	}
	case 2: {
		float *a = NULL;
		float x;

		inputarray(a, n);
		output(a, n);
		cout << "Input x: ";
		cin >> x;
		search(a, n, x);
		add(a, n, x);
		cout << "Added x to the end of the array." << endl;
		cout << "Size of the aray: " << size(a, n) << endl;
		cout << "Sum of element : " << sum(a, n) << endl;
		cout << x << " frequency : " << count(a, n, x) << endl;
		remove(a, n);
		cout << "Removed the last element." << endl;

		delete[] a;
		a = NULL;
	}
	case 3: {
		Fraction* a = NULL;
		Fraction x;

		inputarray(a, n);
		output(a, n);
		cout << "Input x: ";
		inputfraction (x);
		search(a, n, x);
		add(a, n, x);
		cout << "Added x to the end of the array." << endl;
		cout << "Size of the aray: " << size(a, n) << endl;
		cout << "Sum of element : " << sum(a, n) << endl;
		cout <<"Frequency : " << count(a, n, x) << endl;
		remove(a, n);
		cout << "Removed the last element." << endl;

		delete[] a;
		a = NULL;
	}
	}
	system("pause");
	return 0;
}