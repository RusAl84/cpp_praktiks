// var_93.cpp : 
#include <iostream>
#include <windows.h>
#include <string>

using namespace std;

struct Date {
	int day;
	int month;
	int year;
};

struct Record
{
	char author[20];
	char title[20];
	int year;
	char group;
	struct Date date;
	bool isEmpty;
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
	int width = 78 + 9;
	cout << endl;	cout.width(width + 1); cout.fill('-'); cout << "-" << endl;
	cout.fill(' '); cout.width(width);  cout << left << "|Каталог библиотеки"; cout << "|" << endl;
	cout.width(width + 1); cout.fill('-'); cout << "-" << endl;
	cout.fill(' ');
	cout << left << "|     Автор книги    ";
	cout << left << "|     Название   ";
	cout << left << "| Год выпуска";
	cout << left << "| Группа";
	cout << left << " | Дата подписания рукописи ";
	cout << "|" << endl;
	cout.width(width + 1); cout.fill('-'); cout << "-" << endl;
	cout.fill(' ');
	for (int i = 0; i < 10; i++) {
		//if (records[i].isEmpty == 0){
		if (not records[i].isEmpty){
		cout << left << "|"; cout.width(20); cout << left << records[i].author;
		cout << left << "|"; cout.width(16); cout << left << records[i].title;
		cout << left << "|"; cout.width(12); cout << left << records[i].year;
		cout << left << "|"; cout.width(8); cout << left << records[i].group;
		cout << left << "|";
		printDate(records[i].date.day, records[i].date.month, records[i].date.year, 28);
		cout << "|" << endl;
		}
	}
	cout.width(width + 1); cout.fill('-'); cout << "-" << endl;
	cout.fill(' '); cout.width(width);  cout << left << "|Примечание: Х – худож. лит-ра; У - учебная лит-ра; С - справочная лит-ра. "; cout << "|" << endl;
	cout.width(width + 1); cout.fill('-'); cout << "-" << endl;
}

void delByDate(struct Record* records, struct Date findDate) {
	for (int i = 0; i < 10; i++)
		if ((records[i].date.day == findDate.day) and
			(records[i].date.month == findDate.month) and
			(records[i].date.year == findDate.year)
			)
			records[i].isEmpty = 1;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	struct Record records[10];
	records[0] = { "Танечка", "Yga", 2020, 'Х', {11,11,2020}, 0 };
	records[1] = { "Аделина", "Lamba", 2020, 'У', {11,12,2020}, 0 };
	records[2] = { "Дашенька", "BMW X5",  2010, 'C', {12,12,2010}, 0 };

	Draw(records);

	cout << endl << "Удалить все записи(элементы массива структур)," << endl;
	cout << "содержащее введенное значение дат" << endl;

	struct Date findDate = { 11, 11, 2020 };
	delByDate(records, findDate);
	Draw(records);
}