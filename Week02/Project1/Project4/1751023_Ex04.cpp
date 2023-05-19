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

class Rectangle {
private:
	Point tl, br;
public:
	Rectangle();
	Rectangle(int x1, int y1, int x2, int y2);
	Rectangle(Point &a, Point &b);
	Rectangle(const Rectangle &other);
	~Rectangle();
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

Rectangle::Rectangle() {
	Point a, b;
	tl = a;
	br = b;
}

Rectangle::Rectangle(int x1, int y1, int x2, int y2) {
	Point a(x1, y1), b(x2, y2);
	tl = a;
	br = b;
}

Rectangle::Rectangle(Point &a, Point &b) {
	tl = a;
	br = b;
}

Rectangle::Rectangle(const Rectangle &other) {
	tl = other.tl;
	br = other.br;
}

Rectangle::~Rectangle() {
	tl.~Point; br.~Point;
}