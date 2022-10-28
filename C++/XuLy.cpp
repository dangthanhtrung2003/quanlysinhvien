﻿#include "QLSV.h";

QLSV::QLSV() {
	n = 0;
}

void QLSV::Nhap() {
	cout << "\nNhap so luong sinh vien: ";
	cin >> n;
	sv = new SinhVien[n];
	for (int i = 0; i < n; i++) {
		cout << "\nNhap thong tin sinh vien thu " << i + 1 << ": \n";
		sv[i].nhapThongTin();
		while (timMaSoTrung(sv[i].getID()) != 1) {
			int id;
			cout << "Xin loi, ma so " << sv[i].getID() << " da ton tai trong he thong, vui long nhap lai: ";
			cin >> id;
			sv[i] = SinhVien(id, sv[i].getName(), sv[i].getDate(), sv[i].getMonth(), sv[i].getYear(), sv[i].getGender(), sv[i].getEmail());
		}
	}
}

void QLSV::Xuat() {
	cout << "\nDanh sach toan bo sinh vien: \n";
	for (int i = 0; i < n; i++) {
		cout << "Thong tin sinh vien thu " << 1 << ": \n";
		sv[i].xuatThongTin();
		cout << "\n";
	}
}

bool QLSV::kiemTraDanhSach() {
	return n > 0;
}

int QLSV::timKiemTheoID(int ms) {
	int res = -1;
	for (int i = 0; i < n; i++) 
		if (sv[i].getID() == ms)
			res = i;
	return res;
}

int QLSV::timMaSoTrung(int ms) {
	int res = 0;
	for (int i = 0; i < n; i++)
		if (sv[i].getID() == ms)
			res++;
	return res;
}

SinhVien QLSV::getSinhVien(int ms) {
	SinhVien res;
	int kq = timKiemTheoID(ms);
	if (kq != -1) return sv[kq];
	return res;
}

SinhVien* QLSV::timKiemTheoTen(string ten) {
	SinhVien* arr = new SinhVien[n];
	int j = 0;
	for (int i = 0; i < n; i++) {
		if (sv[i].getName() == ten) {
			arr[j] = sv[i];
			j += 1;
		}
	}
	return arr;
}

void QLSV::chinhSuaThongTin(int ms) {
	int res = timKiemTheoID(ms);

	if (res != -1) {		
		cout << "\nNhap cac thong tin minh can chinh sua: \n";

		string name;
		cin.ignore();
		cout << "Nhap ho va ten: ";
		getline(cin, name);

		while (!checkName(name)) {
			cout << "Ten khong hop le, vui long nhap lai: ";
			cin.ignore();
			getline(cin, name);
		}

		int date, month, year;
		cout << "Nhap ngay, thang, nam sinh: ";
		cin >> date >> month >> year;

		string gender;
		cout << "Nhap gioi tinh: ";
		cin >> gender;
		while (!checkGender(gender)) {
			cout << "Gioi tinh khong hop le, vui long nhap lai: ";
			cin >> gender;
		}

		string email;
		cout << "Nhap email: ";
		cin >> email;
		while (!checkEmail(email)) {
			cout << "Email khong hop le, vui long nhap lai: ";
			cin >> email;
		}
		sv[res] = SinhVien(sv[res].getID(), name, date, month, year, gender, email);

		cout << "\nThong tin sinh vien co ma so " << ms << " da duoc cap nhat!\n";
	}
	else {
		cout << "\nXin loi, khong co sinh vien nao co ma so " << ms << ".\n";
	}
}

void QLSV::xoaSinhVienTheoID(int ms) {
	int res = timKiemTheoID(ms);
	if (res != -1) {
		for (int i = res; i < n-1; i++) {
			sv[i] = sv[i + 1];
			
			cout << "\nSinh vien co ma so " << ms << " da xoa khoi he thong thanh cong!\n";
		}
		n--;
	}
	else cout << "\nXin loi, khong co sinh vien nao co ma so " << ms << ".\n";
}

void QLSV::ghiFile() {
	ofstream outfile;
	outfile.open("output.csv");
	outfile << "MSSV, Name, Birthday, Gender, Email" << endl;
	for (int i = 0; i < n; i++) {
		outfile << sv[i].getID() << ", " << sv[i].getName() << ", " << sv[i].getDate() << "/" << sv[i].getMonth() << "/" << sv[i].getYear() << ", " << sv[i].getGender() << ", " << sv[i].getEmail() << endl;
	}
	outfile.close();

	cout << "Xuat du lieu thanh cong!";
}