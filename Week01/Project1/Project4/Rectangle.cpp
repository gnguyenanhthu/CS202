#include "Rectangle.h"

Rectangle::Rectangle() {
	tl.x = 0; tl.y = 0;
	br.x = 0; br.y = 0;
}

void Rectangle::input(int x1, int y1, int x2, int y2) {
	tl.x = x1; tl.y = y1;
	br.x = x2; br.y = y2;
}

void Rectangle::output() {
	cout << "Top left: " << "(" << tl.x << "," << tl.y << ")" << endl;
	cout << "Bottom right: " << "(" << br.x << "," << br.y << ")" << endl;
}

float Rectangle::diagonal() {
	return sqrt((tl.x - br.x)*(tl.x - br.x) + (tl.y - br.y)*(tl.y - br.y));
}

float Rectangle::perimeter() {
	return 2 * ((br.x - tl.x) + (tl.y - br.y));
}

float Rectangle::area() {
	return ((br.x - tl.x)*(tl.y - br.y));
}