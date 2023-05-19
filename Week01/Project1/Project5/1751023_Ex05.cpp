#include "Date.h"

int main() {
	Date a, b, next1, pre1, nextn, pren;
	int d, m, y, n;
	cout << "Input date: ";
	cin >> d >> m >> y;
	a.input(d, m, y);
	a.output();

	next1=a.increase_1_day();
	cout << "The next day is: ";
	next1.output();

	pre1 = a.decrease_1_day();
	cout << "The previous day is: ";
	pre1.output();

	cout << "Number of days from 1/1/1: " << a.order1_1_1() << endl;
	cout << "Number of days from 1/1/2018: " << a.order1_1_2018() << endl;

	cout << "Input n day(s) you want to increase/decrease: ";
	cin >> n;
	nextn = a.increase_n_days(n);
	cout << "After "<<n<<" days is: ";
	nextn.output();
	pren = a.decrease_n_days(n);
	cout << "Before " << n << " days is: ";
	pren.output();


	cout << "Input another date you want to compare: ";
	cin >> d >> m >> y;
	b.input(d, m, y);
	a.compare(b);

	system("pause");
	return 0;
}