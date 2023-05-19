#ifndef  _DATE_H_
#define  _DATE_H_

#include<iostream>
using namespace std;

class Date {
private:
	int day, month, year;
public:
	Date();
	Date(int y);
	Date(int y, int m);
	Date(int y, int m, int d);
	Date(const Date &other);

	Date& operator=(const Date &other);

	bool isleapyear();
	Date Tomorrow();
	Date Yesterday();

	bool operator==(const Date &other);
	bool operator!=(const Date &other);
	bool operator>=(const Date &other);
	bool operator<=(const Date &other);
	bool operator<(const Date &other);
	bool operator>(const Date &other);

	Date& operator+(int n);
	Date& operator-(int n);

	Date& operator++();
	Date& operator++(int);
	Date& operator--();
	Date& operator--(int);

	int countleapyear();
	operator int();
	operator long();

	Date& operator+=(int n);
	Date& operator-=(int n);

	friend ostream& operator<<(ostream& output, Date x)
	{
		output << x.day << "/" << x.month << "/" << x.year << endl;
		return output;
	}
	friend istream& operator>>(istream& input, Date x)
	{
		input >> x.day >> x.month >> x.year;
		return input;
	}
};

const int monthdays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

#endif // ! _DATE_H_
