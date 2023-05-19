#include "University.h"

Staff::Staff(int i, int a) {
	id = i; age = a;
}

Staff::Staff(string n) {
	name = n;
}

Staff::Staff(int i, string n, int a) {
	id = i; name = n; a = age;
}

Staff::Staff(const Staff &other) {
	id = other.id;
	name = other.name;
	age = other.age;
}

void Staff::input() {
	cout << "Input ID: "; cin >> id;
	cout << "Input age: ";
	cin >> age;
	cin.ignore();
	cout << "Input name: ";
	getline(cin, name);
}

void Staff::output() {
	cout << "ID: " << id << endl;
	cout << "Age: " << age << endl;
	cout << "Name: " << name << endl;
}