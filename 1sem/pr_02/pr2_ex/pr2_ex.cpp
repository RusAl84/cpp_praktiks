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
    double x = 1, y = 1;
    double a = 12.5, b = 1.3;
    double c = 14.1, d = 2.7;
    double t1, t2;
    double ax;
    printf("Введите x, y >");
    
    //scanf("%lf %lf", &x, &y);
    
    double t1_p1 = 1 / (pow(b,3));
    // todo деление на ноль
    double t1_p2 = log(y / x);
    double t1_p3 = (pow(a, 2) * pow(x, 2)) / (2 * pow(y, 2));
    double t1_p4 = t1_p2 - t1_p3;
    t1 = t1_p1 * t1_p4;
    t2 = y;

    printf("t1 = %lg\n", t1); printf("t2 = %lg\n", t2);
    printf("\nЧисло Pi: %lg\n", M_PI);
}
