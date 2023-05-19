#include "Company.h"

dob::dob() {
	d = 1; m = 1; y = 1;
}

dob::dob(int day, int month, int year) {
	d = day; m = month; y = year;
}

dob::dob(const dob &date) {
	d = date.d; m = date.m; y = date.y;
}

void dob::display() {
	cout << d << "/" << m << "/" << y << endl;
}

void NhanVien::input() {
	int a, b, c;
	cout << "Nhap ID: "; cin >> id;
	cout << "Nhap ngay thang nam sinh: ";
	cin >> a >> b >> c;
	dob ns(a, b, c);
	ngaysinh = ns;
	cin.ignore();
	cout << "Nhap ho va ten: ";
	getline(cin,ten);
	cout << "Nhap dia chi: ";
	getline(cin,diachi);
}

void NhanVien::display() {
	cout << "ID: " << id << endl;
	cout << "Ho ten: " << ten << endl;
	cout << "Ngay sinh: "; ngaysinh.display();
	cout << "Dia chi: " << diachi << endl;
}

NhanVien::NhanVien(int ms) {
	id = ms;
}

NhanVien::NhanVien(string ht, string dc) {
	ten = ht; diachi = dc;
}

NhanVien::NhanVien(dob ns) {
	ngaysinh = ns;
}

NhanVien::NhanVien(int day, int month, int year) {
	dob ns(day, month, year);
	ngaysinh = ns;
}

NhanVien::NhanVien(int ms, int day, int month, int year, string ht, string dc) {
	id = ms;
	dob ns(day, month, year);
	ngaysinh = ns;
	ten = ht; diachi = dc;
}