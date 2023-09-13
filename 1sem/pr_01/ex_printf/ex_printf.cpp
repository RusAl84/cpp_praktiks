#include <iostream>
#include <stdio.h>
#include <windows.h>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251); // Ввод с консоли в кодировке 1251
	SetConsoleOutputCP(1251);

	//https://codelessons.ru/ru/printf-in-c-cplusplus/

	printf("1. просто строка \n");
	printf("2. целое число: %d \n", 1234);
	printf("3. дробное число: %f \n", 12.34);
	printf("4. Символ: %c  \n", 'C');
	printf("5. строка: %s \n", "C++");
	printf("6. процент: 100%% \n");

	for (int i = 0; i < 80; i++)
		printf("-");
	printf("\n");

	int a = 10;
	float b = 20.5;
	char c = 'A';
	printf("целое: %d, дробное: %f, символ: %c \n", a, b, c);

	for (int i = 0; i < 80; i++)
		printf("-");
	printf("\n");

	printf("1. несколько аргументов: %d, %f \n", 1234, 12.34);
	printf("2. минимальная ширина: %10d \n", 1234);
	printf("3. лидирующие нули: %010d \n", 1234);
	printf("4. количество знаков после запятой: %.9f, %.0f \n", 12.34, 12.34);
	printf("5. шестнадцатеричное число: %x \n", 1234);




	return 0;
}