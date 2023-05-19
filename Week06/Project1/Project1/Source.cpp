#include "Header.h"

Prince::Prince(int a, int b, int c) {
	money = a; academic = b; power = c;
}
void Prince::inputprince() {
	cout << "Create your prince." << endl;
	cout << "Input money: "; cin >> money;
	cout << "Input academice: "; cin >> academic;
	cout << "Input power: "; cin >> power;
}

void Prince::outputprince() {
	cout << "Academic: " << academic << endl;
	cout << "Money: " << money << endl;
	cout << "Power: " << power << endl;
}
int Prince::getmoney() {
	return money;
}
int Prince::getacademic() {
	return academic;
}
int Prince::getpower() {
	return power;
}
void Prince::setmoney(int m) {
	money = m;
}
void Prince::setpower(int p) {
	power = p;
}