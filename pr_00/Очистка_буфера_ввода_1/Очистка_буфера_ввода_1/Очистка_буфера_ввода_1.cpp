
#include <iostream>
#include<stdio.h>

int main()
{
	char str[80], ch;
	// сканировать ввод от пользователя -
	scanf_s("%s", str, 80);
	// сбрасывает стандартный ввод
	// (очищает входной буфер)

	while ((getchar()) != '\n');

	//сканируем символ от пользователя -
	//ch = getchar();
	ch = getchar();
	// Печать массива символов,
	printf("%s\n", str);
	// напечатаем введенный символ
	printf("%c", ch);

	return 0;

}


