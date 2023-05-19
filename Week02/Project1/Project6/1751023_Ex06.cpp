#include <iostream>
using namespace std;

class Time {
private:
	int hour, minute, second;
public:
	Time();
	Time(int h, int m, int s);
	Time(const Time &other);
	Time(char *s); // "11:55:00"
	~Time();
};

Time::Time() {
	hour = 0; minute = 0; second = 0;
}

Time::Time(int h, int m, int s) {
	hour = h; minute = m; second = s;
}

Time::Time(const Time &other) {
	hour = other.hour;
	minute = other.minute;
	second = other.second;
}

Time::Time(char *s) {
	int i = 0;
	hour = int(s[i]);
	++i;
	while (s[i] != ':') {
		hour = hour * 10 + int(s[i]);
		++i;
	}
	++i;
	minute = s[i];
	while (s[i] != ':') {
		minute = minute * 10 + int(s[i]);
		++i;
	}
	++i;
	second = s[i];
	while (s[i]) {
		second = second * 10 + int(s[i]);
		++i;
	}
}

Time::~Time() {
	hour = 0; minute = 0; second = 0;
}