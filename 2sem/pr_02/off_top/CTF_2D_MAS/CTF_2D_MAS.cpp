#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>



int main(void)
{
	int** table; // указатель для блока памяти для массива указателей
	int* rows; // указатель для блока памяти для хранения информации по строкам
	int rowscount; // количество строк
	int d; // вводимое число

	// ввод количества строк
	printf("Rows count=");
	scanf("%d", &rowscount);
	// выделяем память для двухмерного массива
	table = (int **)calloc(rowscount, sizeof(int*));
	rows = (int*)malloc(sizeof(int) * rowscount);
	// цикл по строкам
	for (int i = 0; i < rowscount; i++)
	{
		printf("\nColumns count for row %d=", i);
		scanf("%d", &rows[i]);
		table[i] = (int*) calloc(rows[i], sizeof(int));
		for (int j = 0; j < rows[i]; j++)
		{
			printf("table[%d][%d]=", i, j);
			scanf("%d", &d);
			table[i][j] = d;
		}
	}
	printf("\n");
	// вывод введенных чисел на консоль
	for (int i = 0; i < rowscount; i++)
	{
		printf("\n");
		for (int j = 0; j < rows[i]; j++)
		{
			printf("%d \t", table[i][j]);
		}
		// освобождение памяти для одной строки
		free(table[i]);
	}

	// освобождение памяти
	free(table);
	free(rows);
	return 0;
}
