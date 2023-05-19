#include "Date.h"

Date::Date() {
	day = 1;
	month = 1;
	year = 1;
}

void Date::input(int d, int m, int y) {
	day = d;
	month = m;
	year = y;
}

void Date::output() {
	cout << day << "/" << month << "/" << year << endl;
}

bool Date::isleapyear() {
	if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
		return true;
	return false;
}

Date Date::increase_1_day() {
	Date next;
	next.day = day+1;
	next.month = month;
	next.year = year;
	if ((next.day == 29 && next.month == 2 && !next.isleapyear()) || (next.day == 31 && (next.month == 4 || next.month == 6 || next.month == 9)) || (next.day == 32 && (next.month == 1 || next.month == 3 || next.month == 5 || next.month == 7 || next.month == 8 || next.month == 10))) {
		next.day = 1;
		next.month++;
	}
	if (next.day == 31 && next.month == 12) {
		next.day = 1;
		next.month = 1;
		next.year++;
	}
	return next;
}

Date Date::increase_n_days(int n) {
	Date next;
	next.day = day;
	next.month = month;
	next.year = this->year;
	while (n != 0) {
		next.day++;
		if ((next.day == 29 && next.month == 2 && !next.isleapyear()) || (next.day == 31 && (next.month == 4 || next.month == 6 || next.month == 9)) || (next.day == 32 && (next.month == 1 || next.month == 3 || next.month == 5 || next.month == 7 || next.month == 8 || next.month == 10))) {
			next.day = 1;
			next.month++;
		}
		if (next.day==31&&next.month == 12) {
			next.day = 1;
			next.month = 1;
			next.year=next.year+1;
		}
		--n;
	}
	return next;
}

Date Date::decrease_1_day() {
	Date pre;
	pre.day = day-1;
	pre.month = month;
	pre.year = this->year;
	if (pre.day == 0) {
		if (pre.month == 3 && pre.isleapyear()) {
			pre.day = 29; pre.month = 2;
		}
		if (pre.month == 3 && !pre.isleapyear()) {
			pre.day = 28; pre.month = 2;
		}
		if (pre.month == 2 || pre.month == 4 || pre.month == 6 || pre.month == 8 || pre.month == 9 || pre.month == 11) {
			pre.day = 31; pre.month--;
		}
		if (pre.month == 5 || pre.month == 7 || pre.month == 10 || pre.month == 12) {
			pre.day = 30; pre.month--;
		}
		if (pre.month == 1) {
			pre.year--; pre.month = 12; pre.day = 31;
		}
	}
	return pre;
}

Date Date::decrease_n_days(int n) {
	Date pre;
	pre.day = day;
	pre.month = month;
	pre.year = this->year;
	while (n != 0) {
		pre.day--;
		if (pre.day == 0) {
			if (pre.month == 3 && pre.isleapyear()) {
				pre.day = 29; pre.month = 2;
			}
			if (pre.month == 3 && !pre.isleapyear()) {
				pre.day = 28; pre.month = 2;
			}
			if (pre.month == 2 || pre.month == 4 || pre.month == 6 || pre.month == 8 || pre.month == 9 || pre.month == 11) {
				pre.day = 31; pre.month--;
			}
			if (pre.month == 5 || pre.month == 7 || pre.month == 10 || pre.month == 12) {
				pre.day = 30; pre.month--;
			}
			if (pre.month == 1) {
				pre.year=pre.year-1; pre.month = 12; pre.day = 31;
			}
		}
		n--;
	}
	return pre;
}

void Date::compare(Date date) {
	if ((date.year < year) || (date.year == year&&date.month < month) || (date.year == year&&date.month == month&&date.day < day)) {
		cout << "Past" << endl;
		return;
	}
	cout << "Future" << endl;
}

int Date::countleapyear() {
	int y = year;
	if (month <= 2)
		y--;
	return y / 4 - y / 100 + y / 400;
}

int Date::order1_1_1() {
	int r;
	r = year * 365 + day;
	for (int i = 0; i<month - 1; i++)
		r += monthdays[i];
	r+= +countleapyear();
	return r;
}

int Date::order1_1_2018() {
	int r1;
	r1 = year * 365 + day;
	for (int i = 0; i<month - 1; i++)
		r1 += monthdays[i];
	r1 += countleapyear();

	int r2 = 2017 * 365 + 1 + (2017 / 4 - 2017 / 100 + 2017 / 400);
	return (r1 - r2);
}