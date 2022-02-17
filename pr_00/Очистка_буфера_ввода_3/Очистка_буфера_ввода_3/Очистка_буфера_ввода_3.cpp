#// C ++ код, объясняющий, как "cin >> ws"
// сбрасывает входной буфер вместе с
// начальные пробелы строки

#include<iostream>
#include<vector>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
	int a;
	string s;
	cin >> a;

	// Сбрасывает входной буфер и
	// начальные пробелы строки
	cin >> ws;
	// Получить ввод от пользователя -
	getline(cin, s);
	// выполнит print a и s
	cout.fill('*');
	cout <<   setw(6) << a << endl;
	cout << s << endl;

	return 0;
}