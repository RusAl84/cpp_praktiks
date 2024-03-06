// var 30
#include <iostream>
#include <windows.h>
#include <string>
#include <vector>

using namespace std;

struct Date {
	unsigned short day;
	unsigned short month;
	unsigned short year;
};

struct Record
{
	char surName[17];
	char ident[12];
	unsigned short year;
	float salary;
	struct Date date;
	//bool isEmpty;
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
	cout.fill(' '); cout.width(78);  cout << left << "|Отдел кадров"; cout << "|" << endl;
	cout.width(79); cout.fill('-'); cout << "-" << endl;
	cout.fill(' ');
	//cout.width(17); cout << "| Фамилия";
	//cout.width(12); cout << "| Инициалы";
	//cout.width(12); cout << "| Год рожд" ;
	//cout.width(12); cout << "| Оклад";
	//cout.width(25); cout << "| Дата приема на работу";
	cout << left << "|"; myCentr("Фамилия", 16);
	cout << left << "|"; myCentr("Инициалы", 11);
	cout << left << "|"; myCentr("Год рожд", 10);
	cout << left << "|"; myCentr("Оклад", 10);
	cout << left << " |"; myCentr("Дата приема на работу", 24);
	cout << "|" << endl;
	cout.width(79); cout.fill('-'); cout << "-" << endl;
	cout.fill(' ');
	for (int i = 0; i < 3; i++) {
		cout << left << "|"; cout.width(16); cout << left << records[i].surName;
		cout << left << "|"; cout.width(11); cout << left << records[i].ident;
		cout << left << "|+"; cout.width(10); cout << left << records[i].year;
		std::cout.precision(2);
		cout << left << "|"; cout.width(11); cout << left << fixed << records[i].salary;
		cout << left << "|";
		printDate(records[i].date.day, records[i].date.month, records[i].date.year, 26);
		cout << "|" << endl;
	}
	cout.width(79); cout.fill('-'); cout << "-" << endl;
	cout.fill(' '); cout.width(78);  cout << left << "|Примечание: оклад установлен по состоянию на 1 января 2000 года"; cout << "|" << endl;
	cout.width(79); cout.fill('-'); cout << "-" << endl;
}

vector<int> getMinMonthDate(struct Record* records) {
	vector<int> indexes;
	int minMonth = 13;
	for (int i = 0; i < 10; i++) {
		if (records[i].date.month < minMonth) {
			minMonth = records[i].date.month;
		}
	}
	for (int i = 0; i < 10; i++) {
		if (minMonth == records[i].date.month) {
			indexes.push_back(i);
		}
	}
	return indexes;
}

vector<int> getMaxMonthDate(struct Record* records) {
	vector<int> indexes;
	int maxMonth = 0;
	for (int i = 0; i < 10; i++) {
		if ((maxMonth < records[i].date.month) and (records[i].date.month < 13)) {
			maxMonth = records[i].date.month;
		}
	}
	for (int i = 0; i < 10; i++) {
		if (maxMonth == records[i].date.month) {
			indexes.push_back(i);
		}
	}
	return indexes;
}


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	struct Record records[10];

	records[0] = { "Иванов", "И.И.", 1975, 517.50, {01,02,2010} };
	records[1] = { "Петренко", "П.П.", 1956, 219.10, {02,03,2020} };
	records[2] = { "Панковский", "М.С.", 1967, 300.10, {12,12,2012} };

	Draw(records);


	cout << endl << "Вариант 30" << endl;
	cout << "Поменять местами записи(элементы массива структур)," << endl;
	cout <<"содержащие минимальный и максимальный номер месяца даты" << endl;

	vector<int> minIndexes = getMinMonthDate(records);
	vector<int> maxIndexes = getMaxMonthDate(records);
	for (auto i : minIndexes)
		cout << endl << "minIndexes = " << i << ' ';
	for (auto i : maxIndexes)
		cout << endl << "maxIndexes = " << i << ' ';

	struct Record tmpRecord = records[maxIndexes[0]];
	for (auto i : maxIndexes)
		records[i] = records[minIndexes[0]];
	for (auto i : minIndexes)
		records[i] = tmpRecord;


	Draw(records);
}