#include "Line.h"

Line::Line() {
	p1.x = 0; p1.y = 0;
	p2.x = 0; p2.y = 0;
}

void Line::input(int a, int b, int c, int d) {
	p1.x = a; p1.y = b;
	p2.x = c; p2.y = d;
}

void Line::output() {
	cout << "Start point (" << p1.x << "," << p1.y << ")" << endl;
	cout << "End Point (" << p2.x << "," << p2.y << ")" << endl;
}

float Line::distance() {
	return sqrt((p2.x - p1.x)*(p2.x - p1.x) + (p2.y - p1.y)*(p2.y - p1.y));
}