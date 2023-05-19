#include "Company.h"

int main() {
	CongTy a;
	string x;
	a.NhapDS;
	cout << "Tinh tong luong: " << a.TinhTongLuong << endl;
	cout << "Tim nhan vien: "; getline(cin, x);
	a.TimNV(x);
	cout << "SN thang 5: " << endl;
	a.SNthang5();

	system("pause");
	return 0;
}