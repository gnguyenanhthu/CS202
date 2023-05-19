#ifndef _COMPANY_H_
#define _COMPANY_H_

#include <iostream>
#include <string>
#include<stdio.h>
using namespace std;

class dob {
private:
	int d, m, y;
public:
	dob();
	dob(int day, int month, int year);
	dob(const dob &date);
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
	void input();
	void display();
};

class NVSanXuat : public NhanVien {
private:
	int sosp;
public:
	int tienluong() {
		return sosp * 20000;
	}
	NVSanXuat() : NhanVien() {};
	NVSanXuat(int ms) : NhanVien(ms) {};
	NVSanXuat(string ht, string dc) : NhanVien(ht,dc) {};
	NVSanXuat(dob ns) : NhanVien(ns) {};
	NVSanXuat(int day, int month, int year) : NhanVien(day, month, year) {};
	NVSanXuat(int ms, int day, int month, int year, string ht, string dc) : NhanVien(ms, day, month, year, ht, dc) {};
	void inputnvsx() {
		cout << "Nhan vien san xuat" << endl;
		input();
		cout << "Nhap so san pham: ";
		cin >> sosp;
	}
	void displaynvsx() {
		cout << "Nhan vien san xuat" << endl;
		display();
		cout << "So san pham: " << sosp << endl;
		cout << "Tien luong: " << tienluong() << endl;
	}
};

class NVCongNhat : public NhanVien {
private:
	int songay;
public:
	int tienluong() {
		return songay * 300000;
	}
	NVCongNhat() : NhanVien() {};
	NVCongNhat(int ms) : NhanVien(ms) {};
	NVCongNhat(string ht, string dc) : NhanVien(ht, dc) {};
	NVCongNhat(dob ns) : NhanVien(ns) {};
	NVCongNhat(int day, int month, int year) : NhanVien(day, month, year) {};
	NVCongNhat(int ms, int day, int month, int year, string ht, string dc) : NhanVien(ms, day, month, year, ht, dc) {};
	void inputnvcn() {
		cout << "Nhan vien cong nhat" << endl;
		input();
		cout << "Nhap so ngay: ";
		cin >> songay;
	}
	void displaynvcn() {
		cout << "Nhan vien cong nhat" << endl;
		display();
		cout << "So ngay: " << songay << endl;
		cout << "Tien luong: " << tienluong() << endl;
	}
};

#endif // !_COMPANY_H_
