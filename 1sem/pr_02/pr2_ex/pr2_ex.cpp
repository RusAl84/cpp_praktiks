#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES

#include <stdio.h>
#include <math.h>
#include <Windows.h>
#include <iostream>
#include <math.h>

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251); // Ввод с консоли в кодировке 1251
    SetConsoleOutputCP(1251);
    double x, y;
    double a = 12.5, b = 1.3;
    double c = 14.1, d = 2.7;
    double t1, t2;
    double ax;
    printf("Введите x, y >");
    
    scanf("%lf %lf", &x, &y);

    t1 = x;
    t2 = y;

    printf("t1 = %lg\n", t1); printf("t2 = %lg\n", t2);
    printf("\nЧисло Pi: %lg\n", M_PI);
}
