#ifndef _DATE_H_
#define _DATE_H_

#include<iostream>
using namespace std;

class Date {
private:
	int day, month, year;
public:
	Date();
	void input(int d, int m, int y);
	void output();
	bool isleapyear();
	Date increase_1_day();
	Date increase_n_days(int n);
	Date decrease_1_day();
	Date decrease_n_days(int n);
	void compare(Date date);
	int countleapyear();
	int order1_1_1();
	int order1_1_2018();
};

const int monthdays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

#endif