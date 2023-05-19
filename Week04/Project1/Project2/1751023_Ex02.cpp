#include "University.h"

int main() {
	TeachAssistant a;
	Lecturer b;
	Researcher c;

	a.inputTA();
	a.outputTA();
	cout << endl;

	b.inputLec();
	b.outputLec();
	cout << endl;

	c.inputRe();
	c.outputRe();
	system("pause");
	return 0;
}