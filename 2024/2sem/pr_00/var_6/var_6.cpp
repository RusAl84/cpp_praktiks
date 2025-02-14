// var_6.cpp : 
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
	char surName[17];
	char commandCode;
	double score;
	unsigned short place;
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

void printWhithZero(int num, int width) {
	if (num > 999 and num < 10000) {
		cout.width(width + 1);
		cout << right << "00" << num;
	}
	if (num > 9999 and num < 100000) {
		cout.width(width);
		cout << right << "0" << num;
	}
}

void Draw(struct Record* records) {
	unsigned short width = 78 + 16;
	cout << endl;	cout.width(width + 1); cout.fill('-'); cout << "-" << endl;
	cout.fill(' '); cout.width(width);  cout << left << "|Ведомость спортивных состязаний"; cout << "|" << endl;
	cout.width(width + 1); cout.fill('-'); cout << "-" << endl;
	cout.fill(' ');
	cout << left << "|  Фамилия участника   ";
	cout << left << "|  Код команды  ";
	cout << left << "|  Количество балов  ";
	cout << left << "|  Место в итоге  ";
	cout << left << " |     Дата     |" << endl;
	cout.width(width + 1); cout.fill('-'); cout << "-" << endl;
	cout.fill(' ');
	for (int i = 0; i < 3; i++) {
		cout << left << "|";  cout.width(22); cout << left << records[i].surName;
		cout << left << "|";  cout.width(15); cout << left << records[i].commandCode;
		cout.precision(4);
		cout << left << "|"; cout << left << fixed << records[i].score;
		unsigned short w = 12;
		if (records[i].score > 9 and records[i].score < 100)
			w += 1;
		cout.width(w); cout.fill(' '); cout << " ";
		cout << left << "|";  cout.width(18); cout << left << records[i].place;
		cout << left << "|";
		printDate(records[i].date.day, records[i].date.month, records[i].date.year, 16);
		cout << "|" << endl;
	}
	cout.width(width + 1); cout.fill('-'); cout << "-" << endl;
	cout.fill(' '); cout.width(width);  cout << left << "|Примечание: Д - \"Динамо\", С - \"Спартак\", Ш - \"Шахтер\""; cout << "|" << endl;
	cout.width(width + 1); cout.fill('-'); cout << "-" << endl;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	struct Record records[10];

	records[0] = { "Баландин", 'С', 123.7000, 2, {06,06,2022} };
	records[1] = { "Шишков", 'Ш', 79.9800, 3, {07,07,2022} };
	records[2] = { "Кравченко", 'Д',  134.8000, 1, {07,06,2022}};

	Draw(records);
}
