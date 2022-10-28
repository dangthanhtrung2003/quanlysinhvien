#ifndef _SinhVien
#define _SinhVien

#include<iostream>
#include<string>
#include<algorithm>
#include<fstream>
using namespace std;

class SinhVien {
private:
	int id;
	string name;
	int date;
	int month;
	int year;
	string gender;
	string email;
public:
	SinhVien();
	SinhVien(int, string, int, int, int, string, string);
	int getID();
	int getDate();
	int getMonth();
	int getYear();
	string getName();
	string getGender();
	string getEmail();
	bool checkName(string);
	bool checkBirthday(string);
	bool checkGender(string);
	bool checkBirthday(int, int, int);
	bool isChar(char);
	bool isDigit(char);
	bool checkEmail(string);
	void nhapThongTin();
	void suaThongTin();
	void xuatThongTin();
};

#endif
