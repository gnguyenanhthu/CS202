#include "Header.h"

int main() {
	Prince htu;
	Castle c;
	c.InputGates();
	htu.inputprince();
	if (c.Win(htu)) {
		cout << "Congratulations! You've saved the princess!" << endl;
		htu.outputprince();
	}
	else
		cout << "You died! Hahahahaha :)) Better luck next time." << endl;
	system("pause");
	return 0;
}