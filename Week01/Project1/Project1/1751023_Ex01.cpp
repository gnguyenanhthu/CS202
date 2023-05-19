#include "Fraction.h"

int main() {
	int n, d;
	Fraction f1, f2;

	cout << "Input 1st numerator and denominator: ";
	cin >> n >> d;
	f1.input(n, d);
	f1.output();

	cout << "Input 2nd numerator and denominator: ";
	cin >> n >> d;
	f2.input(n, d);
	f2.output();

	cout << "Add" << endl;
	f1.add(f2).output();

	cout << "Substract" << endl;
	f1.substract(f2).output();

	cout << "Multiply" << endl;
	f1.multiply(f2).output();

	cout << "Divide" << endl;
	f1.divide(f2).output();

	cout << "Compare" << endl;
	f1.compare(f2);

	cout << "Sign" << endl;
	f1.sign();

	system("pause");
	return 0;
}