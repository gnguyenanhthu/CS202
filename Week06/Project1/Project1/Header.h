#ifndef _HEADER_H_
#define _HEADER_H_

#include <iostream>
#include <string>
#include<vector>

using namespace std;

class Prince {
private:
	int money, academic, power;
public:
	Prince() = default;
	Prince(int a, int b, int c);
	void inputprince();
	void outputprince();
	int getmoney();
	int getacademic();
	int getpower();
	void setmoney(int m);
	void setpower(int p);
};

class Gate {
public:
	virtual void input() {
		cout << "New gate!" << endl;
	}
	virtual bool pass(Prince &ht) {
		return true;
	}
};

class Business : public Gate {
private:
	int price, number;
public:
	void input() {
		input();
		cout << "Input number of products: "; cin >> number;
		cout << "Input price: "; cin >> price;
	}
	bool pass(Prince &ht) {
		if (price*number <= ht.getmoney()) {
			ht.setmoney(ht.getmoney() - price*number);
			return true;
		}
		else {
			return false;
		}
	}
};

class Academic : public Gate {
private:
	int a;
public:
	void input() {
		input();
		cout << "Input academic of gate: "; cin >> a;
	}
	bool pass(Prince &ht) {
		if (ht.getacademic() >= a) {
			return true;
		}
		else {
			return false;
		}
	}
};

class Power : public Gate {
private:
	int p;
public:
	void input() {
		input();
		cout << "Input power of gate: "; cin >> p;
	}
	bool pass(Prince &ht) {
		if (ht.getpower() >= p) {
			ht.setpower(0);
			return true;
		}
		else {
			return false;
		}
	}
};

class Castle {
private:
	string name;
	vector<Gate*> a;
public:
	void InputGates();
	bool Win(Prince &ht);
};

void Castle::InputGates() {
	int n;
	int type;
	Gate *p;
	cout << "Input number of gates: ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "Type of gate " << i << endl;
		cout << "(1: Business; 2: Academic; 3: Power): ";
		cin >> type;

		p = NULL;

		if (type == 1) {
			p = new Business;
		}
		else if (type == 2) {
			p = new Academic;
		}
		else if (type == 3) {
			p = new Power;
		}

		p->input();
		a.push_back(p);
	}
}

bool Castle::Win(Prince &ht) {
	for (int i = 0; i < a.size(); i++) {
		if (a[i]->pass(ht) == false)
			return false;
	}
	return true;
}

#endif
