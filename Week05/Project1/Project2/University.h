#ifndef _UNIVERSITY_H_
#define _UNIVERSITY_H_

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Staff {
private:
	string name;
	string address;
	int id;
	int tel;
public:
	Staff() = default;
	Staff(int i, int t);
	Staff(std::string n);
	Staff(int i, string n, string a, int t);
	Staff(const Staff &other);
	void input();
	void output();
	virtual void input();
	virtual void output();
	virtual double Salary();
};

class TeachAssistant : public Staff {
private:
	double salary;
public:
	TeachAssistant() : Staff() {};
	TeachAssistant(int i, int t) : Staff(i, t) {};
	TeachAssistant(string n) : Staff(n) {};
	TeachAssistant(int i, string n, string a, int t) : Staff(i, n, a, t) {};
	double Salary() {
		return salary;
	}
	void inputTA() {
		cout << "Teaching Assistant" << endl;
		input();
		cout << "Input salary: "; cin >> salary;
	}
	void outputTA() {
		output();
		cout << "Salary: " << Salary() << endl;
	}
};

class Contract_based: public Staff {
private:
	int cnumber;
	float rate;
public:
	Contract_based() : Staff() {};
	Contract_based(int i, int t) : Staff(i, t) {};
	Contract_based(string n) : Staff(n) {};
	Contract_based(int i, string n, string a, int t) : Staff(i, n, a, t) {};
	double Salary() {
		return rate*cnumber;
	}
	void inputLec() {
		cout << "Contract based lecturer" << endl;
		input();
		cout << "Input number of classes: "; cin >> cnumber;
		cout << "Input rate: "; cin >> rate;
	}
	void outputLec() {
		output();
		cout << "Salary: " << Salary() << endl;
	}
};

class Full_time : public Staff {
private:
	int fix, cnumber;
	float rate;
public:
	Full_time() : Staff() {};
	Full_time(int i, int a) : Staff(i, a) {};
	Full_time(string n) : Staff(n) {};
	Full_time(int i, string n, string a, int t) : Staff(i, n, a, t) {};
	double Salary() {
		return fix + rate*cnumber;
	}
	void inputRe() {
		cout << "Full time lecturer" << endl;
		input();
		cout << "Input number of classes: "; cin >> cnumber;
		cout << "Input rate: "; cin >> rate;
	}
	void outputRe() {
		output();
		cout << "Salary: " << Salary() << endl;
	}
};

class School {
private:
	string name;
	vector<Staff*> a;
public:
	void InputStaff();
	double FullSalary();
};

void School::InputStaff() {
	int n;
	int type;
	Staff *p;
	cout << "Input number of Staffs: ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "Input Staff number " << i << endl;
		cout << "Type (1: TA; 2: Contract base; 3:Full time): ";
		cin >> type;

		p = NULL;

		if (type == 1) {
			p = new TeachAssistant;
		}
		else if (type == 2) {
			p = new Contract_based;
		}
		else if (type == 3) {
			p = new Full_time;
		}

		p->input();
		a.push_back(p);
	}
}

double School::FullSalary() {
	double sum = 0;
	for (int i = 0; i < a.size(); i++) {
		sum += a[i]->Salary();
	}
	return sum;
}

#endif // !_UNIVERSITY_H_
