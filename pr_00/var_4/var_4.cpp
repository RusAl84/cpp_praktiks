// var_4.cpp : 
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
	char product[12];
	unsigned short unitCount;
	float cost;
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

void Draw(struct Record* records) {
	cout << endl;	cout.width(79); cout.fill('-'); cout << "-" << endl;
	cout.fill(' '); cout.width(78);  cout << left << "|Офисные пакеты"; cout << "|" << endl;
	cout.width(79); cout.fill('-'); cout << "-" << endl;
	cout.fill(' ');	
	cout << left << "|"; myCentr("Наименование", 10);
	cout << left << "|"; myCentr("Производитель", 10);
	cout << left << "|"; myCentr("Количество сост.частей", 24);
	cout << left << "|"; myCentr("Цена($)", 10);
	cout << left << " |"; myCentr("Дата релиза", 11);
	cout << "|" << endl;
	cout.width(79); cout.fill('-'); cout << "-" << endl;
	cout.fill(' ');
	for (int i = 0; i < 3; i++) {
		cout << left << "|"; cout.width(16); cout << left << records[i].name;
		cout << left << "|"; cout.width(11); cout << left << records[i].product;
		cout << left << "|+"; cout.width(10); cout << left << records[i].unitCount;
		std::cout.precision(2);
		cout << left << "|"; cout.width(11); cout << left << fixed << records[i].cost;
		cout << left << "|";
		printDate(records[i].date.day, records[i].date.month, records[i].date.year, 26);
		cout << "|" << endl;
	}
	cout.width(79); cout.fill('-'); cout << "-" << endl;
	cout.fill(' '); cout.width(78);  cout << left << "|Примечание: возможно бесплатно получить продукт StarOffice через Internet "; cout << "|" << endl;
	cout.width(79); cout.fill('-'); cout << "-" << endl;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	struct Record records[10];

	records[0] = { "Office", "Microsoft", 4, 870.99, {11,01,2011} };
	records[1] = { "SmartSute", "Lotus", 5, 1020.99, {21,10,2012} };
	records[2] = { "StarOffice", "Sun", 4, 9.99, {21,10,2020} };

	Draw(records);
}
