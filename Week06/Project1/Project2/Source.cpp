#include <iostream>
#include <string.h>
using namespace std;
class A {
private:
	char *m_s;
public:
	A() { m_s = _strdup("default"); }
	A(char *s) { m_s = s; }
	virtual void prepare() { cout << "A "; }
	void display() {
		prepare();
		cout << m_s << endl;
	}
	friend istream& operator>>(istream& input, A x)
	{
		input >> x.m_s;
		return input;
	}
};
class B : public A {
public:
	B(char *s) : A(s) { }
	B(const B &b) { }
	void prepare() { cout << "B "; }
};
void foo(A *obj1, A obj2) {
	obj1->display();
	obj2.display();
}
void main() {
	B obj1("text");
	A *obj2 = new B(obj1);
	foo(&obj1, *obj2);
	system("pause");
}