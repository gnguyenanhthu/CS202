#include "Triangle.h"

Triangle::Triangle() {
	a.x = 0; a.y = 0;
	b.x = 0; b.y = 0;
	c.x = 0; c.y = 0;
}

void Triangle::input(float x1, float y1, float x2, float y2, float x3, float y3) {
	a.x = x1; a.y = y1;
	b.x = x2; b.y = y2;
	c.x = x3; c.y = y3;
}

void Triangle::output() {
	cout << "Vertex 1" << "(" << a.x << "," << a.y << ")" << endl;
	cout << "Vertex 2" << "(" << b.x << "," << b.y << ")" << endl;
	cout << "Vertex 3" << "(" << c.x << "," << c.y << ")" << endl;
}

float edge(float x1, float y1, float x2, float y2) {
	return sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1));
}

void Triangle::type() {
	float m, n, p;
	m = edge(a.x, a.y, b.x, b.y);
	n = edge(a.x, a.y, c.x, c.y);
	p = edge(b.x, b.y, c.x, c.y);
	if ((m == n) && (n == p) && (m == p)) {
		cout << "Equilateral triangle" << endl;
		return;
	}
	if (((m == n) && (m == p)) || ((n == m) && (n == p)) || ((p == m) && (p == n))) {
		cout << "Isosceles triangle" << endl;
		return;
	}
	if ((m*m + n*n == p*p) || (m*m == n*n + p*p) || (m*m + p*p == n*n)) {
		cout << "Square triangle" << endl;
		return;
	}
	cout << "Normal Triangle" << endl;
}

float Triangle::perimeter() {
	float m, n, p;
	m = edge(a.x, a.y, b.x, b.y);
	n = edge(a.x, a.y, c.x, c.y);
	p = edge(b.x, b.y, c.x, c.y);
	return m + n + p;
}

float Triangle::area() {
	float m, n, p, per;
	m = edge(a.x, a.y, b.x, b.y);
	n = edge(a.x, a.y, c.x, c.y);
	p = edge(b.x, b.y, c.x, c.y);
	per = (m + n + p) / 2;
	return sqrt(per*(per - m)*(per - n)*(per - p));
}
 
Point Triangle::centerpoint() {
	Point cp;
	cp.x = (a.x + b.x + c.x) / 3;
	cp.y = (a.y + b.y + c.y) / 3;
	return cp;
}