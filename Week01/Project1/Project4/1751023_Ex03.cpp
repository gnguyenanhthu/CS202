#include "Rectangle.h"

int main() {
	Rectangle r;
	int x1, y1, x2, y2;
	cout << "Input top left point: ";
	cin >> x1 >> y1;
	cout << "Input bottom right point: ";
	cin >> x2 >> y2;
	r.input(x1, y1, x2, y2);
	r.output();

	cout << "Diagonal:" << r.diagonal() << endl;

	cout << "Perimeter: " << r.perimeter() << endl;

	cout << "Area: " << r.area() << endl;

	system("pause");
	return 0;
}