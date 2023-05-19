#include "Triangle.h"

int main() {
	Triangle t;
	float x1, x2, x3, y1, y2, y3;
	cout << "Input 1st vertex: ";
	cin >> x1 >> y1;
	cout << "Input 2nd vertex: ";
	cin >> x2 >> y2;
	cout << "Input 3rd vertex: ";
	cin >> x3 >> y3;

	t.input(x1, y1, x2, y2, x3, y3);
	t.output();
	
	cout << "Type: ";
	t.type();

	cout << "Perimeter: " << t.perimeter() << endl;

	cout << "Area: " << t.area() << endl;

	Point cp = t.centerpoint();
	cout << "Center point: (" << cp.x << "," << cp.y << ")" << endl;

	system("pause");
	return 0;
}