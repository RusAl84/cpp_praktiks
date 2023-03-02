// var_8.cpp : 
#include <iostream>
#include <windows.h>
#include <string>

using namespace std;

struct Date {
	unsigned short day;
	unsigned short month;
	unsigned short year;
};

struct Record
{
	char name[17];
	char propertyType[12];
	int area;
	unsigned short employCount;
	struct Date date;
};

void myCentr(string s, int wLine) {

	int w = s.length();
	int delta = (wLine - w) / 2;
	cout << left;
	cout.width(delta); cout << " ";
	cout << s;
	cout.width(delta + 1); cout << " ";

}

void printDate(unsigned short day, unsigned short month, unsigned short year, int wLine) {
	int w = 10;
	int delta = (wLine - w) / 2 - 1;
	cout << left;
	cout.width(delta); cout << " ";
	if (day > 9) {
		cout << day;
	}
	else {
		cout << "0" << day;
	}
	cout << ".";
	if (month > 9) {
		cout << month;
	}
	else {
		cout << "0" << month;
	}
	cout << ".";
	cout << year;
	cout.width(delta); cout << " ";
}

void printWithZero4(int num, int width) {
	
	if (num < 10) {
		cout << "000" << num;
	}
	if (num > 9 and num < 100) {
		cout.width(width+1);
		cout << "00" << num;
	}
	if (num > 99 and num < 1000) {
		cout.width(width);
		cout << "0" << num;
	}
	if (num > 999 and num < 10000) {
		cout << num;
	}

}

void Draw(struct Record* records) {
	cout << endl;	cout.width(80); cout.fill('-'); cout << "-" << endl;
	cout.fill(' '); cout.width(79);  cout << left << "|Сельскохозяйственные предприятия"; cout << "|" << endl;
	cout.width(80); cout.fill('-'); cout << "-" << endl;
	cout.fill(' ');
	cout << left << "|Название ";
	cout << left << "|Вид собственности";
	cout << left << "|Площадь земли (га)";
	cout << left << "|Кол. работников";
	cout << left << " |Дата документа";
	cout << "|" << endl;
	cout.width(79); cout.fill('-'); cout << "-" << endl;
	cout.fill(' ');
	for (int i = 0; i < 3; i++) {
		cout << left << "|"; cout.width(9); cout << left << records[i].name;
		cout << left << "|"; cout.width(17); cout << left << records[i].propertyType;
		cout << left << "|";  cout << right; printWithZero4(records[i].area, 15);
		//cout.precision(2);
		cout << left << "|"; cout.width(16); cout << right  << records[i].employCount;
		cout << left << "|";
		printDate(records[i].date.day, records[i].date.month, records[i].date.year, 16);
		cout << "|" << endl;
	}
	cout.width(80); cout.fill('-'); cout << "-" << endl;
	cout.fill(' '); cout.width(79);  cout << left << "|Вид собственности: Д - государственная, Ч - частная, К - кооперативная "; cout << "|" << endl;
	cout.width(80); cout.fill('-'); cout << "-" << endl;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	struct Record records[10];

	records[0] = { "Заря", "Д", 0300, 120, {07,03,2022} };
	records[1] = { "Росинка", "К", 0174, 27, {03,07,2022} };
	records[2] = { "Петренко", "Ч", 0056, 6, {8,8,2021} };

	Draw(records);
}
