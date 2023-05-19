#include <iostream>
using namespace std;

class Date {
private:
	int day, month, year;
public:
	Date();
	Date(int d, int m, int y);
	Date(const Date &other);
	Date(char *s); // "26/10/2018"
	~Date();
};

Date::Date() {
	day = 1; month = 1; year = 1;
}

Date::Date(int d, int m, int y) {
	day = d; month = m; year = y;
}

Date::Date(const Date &other) {
	day = other.day;
	month = other.month;
	year = other.year;
}

Date::Date(char *s) {
	int i = 0;
	day = int(s[i]);
	++i;
	while (s[i] != '/') {
		day = day * 10 + int(s[i]);
		++i;
	}
	++i;
	month = s[i];
	while (s[i] != '/') {
		month = month * 10 + int(s[i]);
		++i;
	}
	++i;
	year = s[i];
	while (s[i]) {
		year = year * 10 + int(s[i]);
		++i;
	}
}

Date::~Date() {
	day = 0; month = 0; year = 0;
}