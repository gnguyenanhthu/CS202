#include "Date.h"

Date::Date() {
	day = 2; month = 11; year = 2012;
}

Date::Date(int y) {
	day = 1; month = 1; year = y;
}

Date::Date(int y, int m) {
	day = 1; month = m; year = y;
}

Date::Date(int y, int m, int d) {
	day = d; month = m; year = y;
}

Date::Date(const Date &other) {
	day = other.day;
	month = other.month;
	year = other.year;
}

Date& Date::operator=(const Date &other) {
	day = other.day;
	month = other.month;
	year = other.year;
	return *this;
}

bool Date::isleapyear() {
	if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
		return true;
	return false;
}

Date Date::Tomorrow() {
	day = day + 1;
	if ((day == 29 && month == 2 && !isleapyear()) || (day == 31 && (month == 4 || month == 6 || month == 9)) || (day == 32 && (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10))) {
		day = 1;
		month++;
	}
	if (day == 31 && month == 12) {
		day = 1;
		month = 1;
		year++;
	}
	return *this;
}

Date Date::Yesterday() {
	day = day - 1;
	if (day == 0) {
		if (month == 3 && isleapyear()) {
			day = 29; month = 2;
		}
		if (month == 3 && !isleapyear()) {
			day = 28; month = 2;
		}
		if (month == 2 || month == 4 || month == 6 || month == 8 || month == 9 || month == 11) {
			day = 31; month--;
		}
		if (month == 5 || month == 7 || month == 10 || month == 12) {
			day = 30; month--;
		}
		if (month == 1) {
			year--; month = 12; day = 31;
		}
	}
	return *this;
}

bool Date::operator==(const Date &other){
	return (day == other.day&&month == other.month&&year == other.year);
}

bool Date::operator!=(const Date &other) {
	return !(*this == other);
}

bool Date::operator>=(const Date &other) {
	return (*this == other) || (year > other.year) || (year == other.year && month > other.year) || (year == other.year && month == other.month && day > other.day);
}

bool Date::operator<=(const Date &other) {
	return (*this == other) || (year < other.year) || (year == other.year && month < other.year) || (year == other.year && month == other.month && day < other.day);
}

bool Date::operator>(const Date &other) {
	return !(*this <= other);
}

bool Date::operator<(const Date &other) {
	return !(*this >= other);
}


Date& Date::operator+(int n) {
	Date temp(*this);
	while (n != 0) {
		temp=temp.Tomorrow();
		--n;
	}
	return temp;
}

Date& Date::operator-(int n) {
	Date temp(*this);
	while (n != 0) {
		temp=temp.Yesterday();
		--n;
	}
	return temp;
}

Date& Date::operator++() {
	return *this = Tomorrow();
}

Date& Date::operator++(int) {
	Date temp(*this);
	*this = Tomorrow();
	return temp;
}

Date& Date::operator--() {
	return *this = Yesterday();
}

Date& Date::operator--(int) {
	Date temp(*this);
	*this = Yesterday();
	return temp;
}

int Date::countleapyear() {
	int y = year;
	if (month <= 2)
		y--;
	return y / 4 - y / 100 + y / 400;
}

Date::operator int() {
	int r1;
	r1 = year * 365 + day;
	for (int i = 0; i<month - 1; i++)
		r1 += monthdays[i];
	r1 += countleapyear();

	int r2 = 2017 * 365 + 1 + (2017 / 4 - 2017 / 100 + 2017 / 400);
	return (r1 - r2);
}

Date::operator long() {
	int r;
	r = year * 365 + day;
	for (int i = 0; i<month - 1; i++)
		r += monthdays[i];
	r += +countleapyear();
	return r;
}

Date& Date::operator+=(int n) {
	while (n != 0) {
		*this = Tomorrow();
		--n;
	}
	return *this;
}

Date& Date::operator-=(int n) {
	while (n != 0) {
		*this = Yesterday();
		--n;
	}
	return *this;
}