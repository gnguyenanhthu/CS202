#ifndef _RECTANGLE_H_
#define _RECTANGLE_H_

#include<iostream>
using namespace std;

struct Point {
	int x, y;
};

class Rectangle {
private:
	Point tl, br;
public:
	Rectangle();
	void input(int x1, int y1, int x2, int y2);
	void output();
	float diagonal();
	float perimeter();
	float area();
};
#endif