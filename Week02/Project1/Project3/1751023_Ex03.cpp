#include <iostream>
using namespace std;

class Point {
private:
	int x, y;
public:
	Point();
	Point(int a, int b);
	~Point();
};

class Triangle {
private:
	Point a, b, c;
public:
	Triangle();
	Triangle(int x1, int y1, int x2, int y2, int x3, int y3);
	Triangle(Point &a, Point &b, Point &c);
	Triangle(const Triangle &other);
	~Triangle();
};

Point::Point() {
	x = 0; y = 0;
}

Point::Point(int a, int b) {
	x = a; y = b;
}

Point::~Point() {
	x = 0; y = 0;
}

Triangle::Triangle() {
	Point a, b, c;
	this->a = a;
	this->b = b;
	this->c = c;
}

Triangle::Triangle(int x1, int y1, int x2, int y2, int x3, int y3) {
	Point a(x1, y1), b(x2, y2), c(x3, y3);
	this->a = a;
	this->b = b;
	this->c = c;
}

Triangle::Triangle(Point &a, Point &b, Point &c) {
	this->a = a;
	this->b = b;
	this->c = c;
}

Triangle::Triangle(const Triangle &other) {
	a = other.a;
	b = other.b;
	c = other.c;
}

Triangle::~Triangle() {
	a.~Point; b.~Point; c.~Point;
}