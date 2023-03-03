#include <iostream>
#include <windows.h>
#include <string>
#include <cstdlib>

using namespace std;

struct Date {
	unsigned short day;
	unsigned short month;
	unsigned short year;
};

struct Record
{
	char surName[20];
	char ident[6];
	unsigned short year;
	float salary;
	struct Date date;
};


void myCentr(string s, int wLine) {

	int w = s.length();
	int delta = (wLine - w) / 2;  
	cout << left;
	cout.width(delta); cout << " "; 
	cout << s; 
	cout.width(delta+1); cout << " ";

}

void printDate(unsigned short day, unsigned short month, unsigned short year, int wLine) {
	int w = 10;
	int delta = (wLine - w) / 2 - 1;
	cout << left;
	cout.width(delta); cout << " ";
	if (day > 9) {
		cout << day;
	} else {
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

	cout << left << "|"; myCentr("Фамилия", 16);
	cout << left << "|"; myCentr("Инициалы", 11);
	cout << left << "|"; myCentr("Год рожд", 10);
	cout << left << "|"; myCentr("Оклад", 10);
	cout << left << " |"; myCentr("Дата приема на работу", 24);
	cout <<"|" << endl;
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

struct Date getMinDate(struct Record* records) {
	unsigned short minYear = records[0].date.year;
	for (int i = 1; i < 3; i++) {
		if (records[i].date.year < minYear)
			minYear = records[i].date.year;
	}

	unsigned short minMonth = records[0].date.month;
	for (int i = 1; i < 3; i++) {
		if (records[i].date.year == minYear and records[i].date.month < minMonth)
			minMonth = records[i].date.month;
	}

	unsigned short minDay = records[0].date.day;
	for (int i = 1; i < 3; i++) {
		if (records[i].date.year == minYear and records[i].date.month == minMonth and records[i].date.day < minDay)
			minDay = records[i].date.day;
	}

	struct Date minDate = { minDay, minMonth, minYear };
	return minDate;
};


struct Date getMaxDate(struct Record* records) {
	unsigned short maxYear = records[0].date.year;
	for (int i = 1; i < 3; i++) {
		if (records[i].date.year > maxYear)
			maxYear = records[i].date.year;
	}

	unsigned short maxMonth = records[0].date.month;
	for (int i = 1; i < 3; i++) {
		if (records[i].date.year == maxYear and records[i].date.month > maxMonth)
			maxMonth = records[i].date.month;
	}

	unsigned short maxDay = records[0].date.day;
	for (int i = 1; i < 3; i++) {
		if (records[i].date.year == maxYear and records[i].date.month == maxMonth and records[i].date.day > maxDay)
			maxDay = records[i].date.day;
	}

	struct Date minDate = { maxDay, maxMonth, maxYear };
	return minDate;
};

int  findIndex(struct Record* records, const struct Date date) {
	int ind = -1;
	for (int i = 0; i < 3; i++) {
		if (records[i].date.year == date.year && records[i].date.month == date.month && records[i].date.day == date.day)
			ind = i;
	}
	return ind;
};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	struct Record records[10];

	records[0] = { "Иванов", "И.И.", 1975, 517.50, {01,02,2010} };      // Свой комментарий
	records[1] = { "Петренко", "П.П.", 1956, 219.10, {02,03,2020} };      // Свой комментарий
	records[2] = { "Панковский", "М.С.", 1967, 300.10, {12,12,2012} };      // Свой комментарий
	cout << "Исходные данные:" << endl;
	Draw(records);
	cout << endl << "Вариант задания: Поменять местами записи (элементы массива структур),";
	cout << endl << "содержащие минимальную и максимальную даты" << endl;

	struct Date minDate = getMinDate(records);
	cout << "Минимальная дата: "; cout.fill(' ');
	printDate(minDate.day, minDate.month, minDate.year, 16);
	cout << endl;

	struct Date maxDate = getMaxDate(records);
	cout << "Максимальная дата: "; cout.fill(' ');
	printDate(maxDate.day, maxDate.month, maxDate.year, 16);
	cout << endl;

	int indMaxDate = findIndex(records, maxDate);
	int indMinDate = findIndex(records, minDate);

	struct Record newRecords[10];
	for (int i = 0; i < 3; i++) {
		if (i == indMaxDate)
			newRecords[i] = records[indMinDate];
		else if (i == indMinDate)
			newRecords[i] = records[indMaxDate];
		else
			newRecords[i] = records[i];
	}
	cout << "Данные по варианту задания:" << endl;
	Draw(newRecords);
	
	cout << endl << "Практическая № 2 (Динамические массивы):" << endl;
	
	
	Record* A;
	int n = 3;
	A = (Record*)malloc(n * sizeof(Record));
	//A = (Record*)calloc(n, sizeof(Record)); 
	for (int i = 0; i < n; i++) {
		strcpy_s(A[i].surName, records[i].surName);
	}

	//Record** B;
	//B = (Record**) new Record * [10];
	//for (int i = 0; i < 10; i++) {
	//	B[i] = (Record*) new Record;
	//	*(B[i]) = records[i];
	//}

	//
	//A = (Record*)realloc(A, 10 * sizeof(Record));
	//Record ** B;
	//B = (Record**) new Record * [10];
	//for (int i = 0; i < 10; i++) {
	//	B[i] = (Record*) new Record;
	//	*(B[i]) = A[i];
	//	//B[i].surName = A[i].surName;
	//	//*(B[i])->surName = A[i]->surName;
	//	
	//}

	//адрес а[i], значение a[i]->строковое_поле, адрес в[i], значение в[i]->строковое_поле.
	for (int i = 0; i < 10; i++) {
		cout << endl << "адрес A[i] " << &A[i] << " a[i]->surName " << A[i].surName;
		//cout << endl << "адрес B[i] " << &B[i] << " B[i]->surName " << B[i]->surName;
	}

	//for (int i = 0; i < 10; i++) {
	//	delete B[i];
	//}
	//delete[]B;
	//free(A);
}
