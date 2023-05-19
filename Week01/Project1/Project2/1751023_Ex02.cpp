#include "Line.h"

int main() {
	Line l;
	int a, b, c, d;
	cout << "Input start point: ";
	cin >> a >> b;
	cout << "Input end point: ";
	cin >> c >> d;
	l.input(a, b, c, d);
	l.output();
	cout << "Distance: " << l.distance() << endl;
	system("pause");
	return 0;
}