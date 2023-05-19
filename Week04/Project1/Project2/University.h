#ifndef _UNIVERSITY_H_
#define _UNIVERSITY_H_

#include <iostream>
#include <string>
using namespace std;

class Staff {
private:
	std::string name;
	int id;
	int age;
public:
	Staff() = default;
	Staff(int i, int a);
	Staff(std::string n);
	Staff(int i, std::string n, int a);
	Staff(const Staff &other);
	void input();
	void output();
};

class TeachAssistant : public Staff {
private:
	int Number_Of_Work_Hours, Base_Salary;
public:
	TeachAssistant() : Staff() {};
	TeachAssistant(int i, int a) : Staff(i, a) {};
	TeachAssistant(string n) : Staff(n) {};
	TeachAssistant(int i, string n, int a) : Staff(i, n, a) {};
	double Salary() {
		return 0.8 * Number_Of_Work_Hours * Base_Salary;
	}
	void inputTA() {
		cout << "Teaching Assistant" << endl;
		input();
		cout << "Input Number Of Work Hours: "; cin >> Number_Of_Work_Hours;
		cout << "Input Base Salary: "; cin >> Base_Salary;
	}
	void outputTA() {
		output();
		cout << "Salary: " << Salary() << endl;
	}
};

class Lecturer : public Staff {
private:
	int Number_Of_Papers, Number_Of_Lecturing_Hours, Base_Salary, Paper_Support;
public:
	Lecturer() : Staff() {};
	Lecturer(int i, int a) : Staff(i, a) {};
	Lecturer(string n) : Staff(n) {};
	Lecturer(int i, string n, int a) : Staff(i, n, a) {};
	double Salary() {
		return 1.2 * Number_Of_Lecturing_Hours * Base_Salary + Paper_Support *
			Number_Of_Papers;
	}
	void inputLec() {
		cout << "Teaching Assistant" << endl;
		input();
		cout << "Input Number Of Papers: "; cin >> Number_Of_Papers;
		cout << "Input Base Salary: "; cin >> Base_Salary;
		cout << "Input Number Of Lecturing Hours: "; cin >> Number_Of_Lecturing_Hours;
		cout << "Input Paper Support: "; cin >> Paper_Support;
	}
	void outputLec() {
		output();
		cout << "Salary: " << Salary() << endl;
	}
};

class Researcher : public Staff {
private:
	int Number_Of_Research_Projects, Number_Of_Papers, Project_Salary, Paper_Support;
public:
	Researcher() : Staff() {};
	Researcher(int i, int a) : Staff(i, a) {};
	Researcher(string n) : Staff(n) {};
	Researcher(int i, string n, int a) : Staff(i, n, a) {};
	double Salary() {
		return Number_Of_Research_Projects * Project_Salary + 1.1 * Paper_Support *
			Number_Of_Papers;
	}
	void inputRe() {
		cout << "Teaching Assistant" << endl;
		input();
		cout << "Input Number Of Papers: "; cin >> Number_Of_Papers;
		cout << "Input Number Of Research Projects: "; cin >> Number_Of_Research_Projects;
		cout << "Input Project Salary: "; cin >> Project_Salary;
		cout << "Input Paper Support: "; cin >> Paper_Support;
	}
	void outputRe() {
		output();
		cout << "Salary: " << Salary() << endl;
	}
};



#endif // !_UNIVERSITY_H_
