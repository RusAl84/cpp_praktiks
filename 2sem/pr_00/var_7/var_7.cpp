// var_7.cpp : 
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
	char transportType[5];
	char route[5];
	double lengthRoute;
	char timeMin[5];
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
	int width = 78 + 16;
	cout << endl;	cout.width(width + 1); cout.fill('-'); cout << "-" << endl;
	cout.fill(' '); cout.width(width);  cout << left << "|Ведомость общественного транспорта"; cout << "|" << endl;
	cout.width(width + 1); cout.fill('-'); cout << "-" << endl;
	cout.fill(' ');
	cout << left << "| Вид транспорта ";
	cout << left << "| маршрута";
	cout << left << "| Протяженность маршрута (км)";
	cout << left << "| Время в дороге (мин)";
	cout << left << " |     Дата     |" << endl;
	cout.width(width + 1); cout.fill('-'); cout << "-" << endl;
	cout.fill(' ');
	for (int i = 0; i < 3; i++) {
		cout << left << "|";  cout << left; myCentr(records[i].transportType,16);
		cout << left << "| ";  cout << left; myCentr(records[i].route, 8);
		cout.precision(3);
		cout << left << "|           "; cout << left << fixed << records[i].lengthRoute;
		cout << left << "           ";
		cout << left << "|"; cout.width(20); cout << left; myCentr(records[i].timeMin, 22);
		cout << left << "|";
		printDate(records[i].date.day, records[i].date.month, records[i].date.year, 16);
		cout << "|" << endl;
	}
	cout.width(width + 1); cout.fill('-'); cout << "-" << endl;
	cout.fill(' '); cout.width(width);  cout << left << "|Примечание: Тр - трамвай, Тс - троллейбус, А - автобус"; cout << "|" << endl;
	cout.width(width + 1); cout.fill('-'); cout << "-" << endl;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	struct Record records[10];

	records[0] = { "Тр.", "12 ", 27.550, "75 ", {03,04,2022} };
	records[1] = { "Т-с", "17 ", 13.600, "57 ", {03,04,2020} };
	records[2] = { "А", "12а",  57.300, "117", {04,03,2022} };

	Draw(records);
}
