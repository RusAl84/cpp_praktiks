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

int GetSize(char* msg) {
	int size = 0;
	while (msg[size] != '\0')
		size++;
	return size;
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
		float salary;
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
	for (int i=0; i<3; i++){
		cout << "| " << lines[i].surName << GetSpacebar(18 - GetSize(lines[i].surName));
		cout << "| " << lines[i].ident << GetSpacebar(18 - GetSize(lines[i].ident));
		cout << "| " << lines[i].year << GetSpacebar(18 - to_string(lines[i].year).size());
		cout << "| " << lines[i].salary << GetSpacebar(22 - to_string(lines[i].salary).size()) << "|\n";
		DrawLine();
	}
	cout << "| Примечание: оклад установлен по состоянию на 1 января 2000 года" << GetSpacebar(80 - sizeof("| Примечание: оклад установлен по состоянию на 1 января 2000 года")) << "|\n";
	DrawLine();
}
