#ifndef _LINE_H_
#define _LINE_H_

#include<iostream>
using namespace std;

struct Point {
	int x, y;
};

class Line {
private:
	Point p1, p2;
public:
	Line();
	void input(int a, int b, int c, int d);
	void output();
	float distance();
};

#endif