
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
	cout << left << "| Наименование ";
	cout << left << "| Производитель";
	cout << left << "| Количество сост. частей";
	cout << left << "| Цена($)";
	cout << left << " | Дата релиза";
	cout << "|" << endl;
	cout.width(79); cout.fill('-'); cout << "-" << endl;
	cout.fill(' ');
	for (int i = 0; i < 3; i++) {
		cout << left << "|"; cout.width(14); cout << left << records[i].name;
		cout << left << "|"; cout.width(14); cout << left << records[i].product;
		cout << left << "|"; cout.width(24); cout << left << records[i].unitCount;
		std::cout.precision(2);
		cout << left << "|"; cout.width(9); cout << left << fixed << records[i].cost;
		cout << left << "|";
		printDate(records[i].date.day, records[i].date.month, records[i].date.year, 11);
		cout << "|" << endl;
	}
	cout.width(79); cout.fill('-'); cout << "-" << endl;
	cout.fill(' '); cout.width(78);  cout << left << "|Примечание: возможно бесплатно получить продукт StarOffice через Internet "; cout << "|" << endl;
	cout.width(79); cout.fill('-'); cout << "-" << endl;
}

vector<int> getMinDayDate(struct Record* records) {
	vector<int> indexes;
	int minDay = 32;
	for (int i = 0; i < 10; i++) {
		if (records[i].date.day < minDay) {
			minDay = records[i].date.day;
		}
	}
	for (int i = 0; i < 10; i++) {
		if (minDay == records[i].date.day) {
			indexes.push_back(i);
		}
	}

	return indexes;
}

vector<int> getMaxDayDate(struct Record* records) {
	vector<int> indexes;
	int maxDay = 0;
	for (int i = 0; i < 10; i++) {
		if ((maxDay < records[i].date.day) and (records[i].date.day < 32)) {
			maxDay = records[i].date.day;
		}
	}
	for (int i = 0; i < 10; i++) {
		if (maxDay == records[i].date.day) {
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

	records[0] = { "Office", "Microsoft", 4, 870.99, {11,01,2011} };
	records[1] = { "SmartSute", "Lotus", 5, 1020.99, {21,10,2012} };
	records[2] = { "StarOffice", "Sun", 4, 9.99, {21,10,2020} };

	Draw(records);

	vector<int> minIndexes = getMinDayDate(records);
	vector<int> maxIndexes = getMaxDayDate(records);
	for (auto i : minIndexes)
		cout << endl << "minIndexes = " << i << ' ';
	for (auto i : maxIndexes)
		cout << endl << "maxIndexes = " << i << ' ';

	cout << endl << "Поменять местами записи(элементы массива структур),";
	cout << endl << "содержащие минимальный и максимальный номер дня даты" << endl;

	struct Record tmpRecord = records[maxIndexes[0]];
	for (auto i : maxIndexes)
		records[i] = records[minIndexes[0]];
	for (auto i : minIndexes)
		records[i] = tmpRecord;


	Draw(records);

}