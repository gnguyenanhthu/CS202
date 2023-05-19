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

class Line {
private:
	Point start, end;
public:
	Line();
	Line(int a, int b, int c, int d);
	Line(Point &s, Point &e);
	Line(const Line &other);
	~Line();
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

Line::Line() {
	Point start, end;
	this->start = start;
	this->end = end;
}

Line::Line(int a, int b, int c, int d) {
	Point start(a,b), end(c,d);
	this->start = start;
	this->end = end;
}

Line::Line(Point &s, Point &e) {
	start = s; end = e;
}

Line::Line(const Line &other) {
	start = other.start;
	end = other.end;
}

Line::~Line() {
	start.~Point(); end.~Point();
}
