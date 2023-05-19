#include <iostream>
using namespace std;

class Student {
private:
	int id;
	char *firstname;
	char *lastname;
	double gpa;
public:
	Student();
	Student(int id);
	Student(int gpa);
	Student(char *s);
	Student(const Student &other);
	~Student();
};

Student::Student() {
	id = 0; gpa = 0;
	firstname = NULL; lastname = NULL;
}

Student::Student(int id) {
	this->id = id;
}

Student::Student(int gpa) {
	this->gpa = gpa;
}

Student::Student(char *s) {
	int i = 0, d = 0;
	while (s[i] != ' ') {
		firstname[i] = s[i];
		++i;
	}
	++i;
	while (s[i]) {
		lastname[d] = s[i];
		++i; ++d;
	}
}

Student::Student(const Student &other) {
	id = other.id;
	firstname = other.firstname;
	lastname = other.lastname;
	gpa = other.gpa;
}

Student::~Student() {
	id = 0; gpa = 0;
	delete[]firstname;
	delete[]lastname;
}

