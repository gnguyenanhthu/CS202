#include "University.h"

Staff::Staff(int i, int t) {
	id = i; tel = t;
}

Staff::Staff(string n) {
	name = n;
}

Staff::Staff(int i, string n, string a, int t) {
	id = i; name = n; address = a; tel = t;
}

Staff::Staff(const Staff &other) {
	id = other.id;
	name = other.name;
	tel = other.tel;
}

void Staff::input() {
	cout << "Input ID: "; cin >> id;
	cout << "Input telephone number: ";
	cin >> tel;
	cin.ignore();
	cout << "Input name: ";
	getline(cin, name);
	cout << "Input address: ";
	getline(cin, address);
}

void Staff::output() {
	cout << "ID: " << id << endl;
	cout << "Telephone number: " << tel << endl;
	cout << "Name: " << name << endl;
	cout << "Address: " << address << endl;
}