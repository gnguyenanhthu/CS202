#ifndef _COMPANY_H_
#define _COMPANY_H_

#include <iostream>
#include <string>
#include<vector>

using namespace std;

class dob {
private:
	int d, m, y;
public:
	dob();
	dob(int day, int month, int year);
	dob(const dob &date);
	int month();
	void display();
};

class NhanVien {
private:
int id;
string ten;
dob ngaysinh;
string diachi;
public:
	NhanVien() = default;
	NhanVien(int ms);
	NhanVien(string ht, string dc);
	NhanVien(dob ns);
	NhanVien(int day, int month, int year);
	NhanVien(int ms, int day, int month, int year, string ht, string dc);
	virtual string name();
	virtual int month();
	virtual void input();
	virtual void output();
	virtual double TinhLuong();
};

class NVSanXuat : public NhanVien {
private:
	int sosp;
public:
	double TinhLuong() {
		return NhanVien::TinhLuong() + sosp * 20000;
	}
	NVSanXuat() : NhanVien() {};
	NVSanXuat(int ms) : NhanVien(ms) {};
	NVSanXuat(string ht, string dc) : NhanVien(ht, dc) {};
	NVSanXuat(dob ns) : NhanVien(ns) {};
	NVSanXuat(int day, int month, int year) : NhanVien(day, month, year) {};
	NVSanXuat(int ms, int day, int month, int year, string ht, string dc) : NhanVien(ms, day, month, year, ht, dc) {};
	void input();
	void output();
};

class NVCongNhat : public NhanVien {
private:
	int songay;
public:
	double TinhLuong() {
		return NhanVien::TinhLuong() + songay * 300000;
	}
	NVCongNhat() : NhanVien() {};
	NVCongNhat(int ms) : NhanVien(ms) {};
	NVCongNhat(string ht, string dc) : NhanVien(ht, dc) {};
	NVCongNhat(dob ns) : NhanVien(ns) {};
	NVCongNhat(int day, int month, int year) : NhanVien(day, month, year) {};
	NVCongNhat(int ms, int day, int month, int year, string ht, string dc) : NhanVien(ms, day, month, year, ht, dc) {};
	void input();
	void output();
};

class CongTy {
private:
	string name;
	vector<NhanVien*> a;
public:
	void NhapDS();
	double TinhTongLuong();
	int SoNVSX();
	void TimNV(string x);
	void SNthang5();
};

void CongTy::NhapDS() {
	int n;
	int type;
	NhanVien *p;
	cout << "Nhap so luong nhan vien: ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "Nhap thong tin nhan vien thu " << i << endl;
		cout << "Loai nhan vien (1: NVSX; 2: NVCN): ";
		cin >> type;

		p = NULL;

		if (type == 1) {
			p = new NVSanXuat;
		}
		else if (type == 2) {
			p = new NVCongNhat;
		}

		p->input();
		a.push_back(p);
	}
}

double CongTy::TinhTongLuong() {
	double sum = 0;
	for (int i = 0; i < a.size(); i++) {
		sum += a[i]->TinhLuong();
	}
	return sum;
}

int CongTy::SoNVSX() {

}

void CongTy::TimNV(string x) {
	for (int i = 0; i < a.size(); i++) {
		if (x == a.at(i)->name)
			a.at(i)->output();
	}
}

void CongTy::SNthang5() {
	for (int i = 0; i < a.size(); i++) {
		if (a.at(i)->month==5)
			a.at(i)->output();
	}
}

void f1(NhanVien nv) {
	cout << nv.TinhLuong() << endl;
}
void f2(NhanVien& nv) {
	cout << nv.TinhLuong() << endl;
}
void f3(NhanVien* nv) {
	cout << nv->TinhLuong() << endl;
}


#endif // !_COMPANY_H_
