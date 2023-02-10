// var_0.cpp : 
#include <iostream>
#include <windows.h>

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
	struct Line line1 = { "Иванов", "И. И.", 1975, 517.50 };
	struct Line line2 = { "Петренко", "П.П.", 1956, 219.10 };
	struct Line line3 = { "Панковский", "М.С.", 1967, 300.00 };

	DrawLine();
	cout << "| Отдел кадров" <<  GetSpacebar(80-15) << "|\n";
	DrawLine();
}
