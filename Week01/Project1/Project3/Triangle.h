#ifndef _TRIANGLE_H_
#define _TRIANGLE_H_

#include<iostream>
using namespace std;

struct Point {
	float x, y;
};

class Triangle {
private:
	Point a, b, c;
public:
	Triangle();
	void input(float x1, float y1, float x2, float y2, float x3, float y3);
	void output();
	void type();
	float perimeter();
	float area();
	Point centerpoint();
};

float edge(float x1, float y1, float x2, float y2);

#endif
