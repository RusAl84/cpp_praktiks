// var_0.cpp : 

#include <iostream>
#include <windows.h>

using namespace std;


void DrawLine() {
	for (int i = 0; i < 80; i++) {
		cout << "-";
	}
		
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	char surName1[17], surname2[17], surname3[17];
	char initials1[12], initials2[12], initials3[12];
	unsigned short year1, year2, year3;
	float salary1, salary2, salary3;


    cout << "Hello World!\n";
	DrawLine();
}
