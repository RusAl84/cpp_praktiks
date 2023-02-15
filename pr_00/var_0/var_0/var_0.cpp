// var_0.cpp : 
#include <iostream>
#include <windows.h>
#include <string>

using namespace std;

void DrawLine() {
	for (int i = 0; i < 80; i++) {
		cout << "-";
	}
	cout << "\n";
}

char* GetSpacebar(int count) {
	char* msg = new char[count];
	for (int i = 0; i < count; i++)
	{
		msg[i] = ' ';
	}
	msg[count] = '\0';
	return msg;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	struct Line
	{
		char surName[17]; 
		char ident[12];
		unsigned short year;
		double salary;
	};

	struct Line lines[3];

	lines[0] = { "Иванов", "И. И.", 1975, 517.50 };
	lines[1] = { "Петренко", "П.П.", 1956, 219.10 };
	lines[2] = { "Панковский", "М.С.", 1967, 300.00 };
	
	DrawLine();
	cout << "| Отдел кадров" <<  GetSpacebar(80-sizeof("| Отдел кадров")) << "|\n";
	DrawLine();
	//|Фамилия |Инициалы |Год рожд | Оклад|
	cout << "| Фамилия" << GetSpacebar(21 - sizeof("| Фамилия")) ;
	cout << "| Инициалы" << GetSpacebar(21 - sizeof("| Инициалы"));
	cout << "| Год рожд" << GetSpacebar(21 - sizeof("| Год рожд"));
	cout << "| Оклад" << GetSpacebar(20 - sizeof("| Оклад")) << "|\n";
	DrawLine();
	cout << "|" << lines[0].surName << GetSpacebar(21 - sizeof(lines[0].surName)) << "|";
	cout << lines[0].ident << GetSpacebar(21 - sizeof(lines[0].ident)) << "|";
	cout << lines[0].year << GetSpacebar(21 - sizeof(lines[0].year)) << "|";
	cout << lines[0].salary << GetSpacebar(20 - sizeof(lines[0].salary)) << "|\n";
	DrawLine();
	cout << sizeof(to_string(lines[0].salary)) << endl;
}
