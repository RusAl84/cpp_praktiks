// Очистка_буфера_ввода_2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.

#include <iostream>

// для <streamsize>
#include<ios>     
// для numeric_limits
#include<limits> 

using namespace std;

int main()
{
	char a, b;
	char str[80];
	// ввод a b
	//cin >>str>>b>>a;

	cin >> a;
	cin >> b;
	//cin >> str;

	// отбрасывает входной буфер

	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	// Получить ввод от пользователя -
	cin.getline(str, 80);

	// печатает a b
	cout << a << endl << b << endl;
	// Печать строки
	cout << str << endl;
	return 0;
}
