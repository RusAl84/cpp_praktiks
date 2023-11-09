#include <iostream>
#include <windows.h>
#include <stdio.h>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251); // Ввод с консоли в кодировке 1251
    SetConsoleOutputCP(1251);
    double x = 0;
    double y = 0;
    bool getIntoArea = false;
    //https://www.desmos.com/calculator?lang=ru
    if ((x <= 1) && (x >= -1) && (y >= -1) && (y <= 1)  ) {           // Проверка что точка входит в квадрат
        if ((x >= 0) && (y >= 0)) {       // Проверка для четверти I
                if (y <= (1 - x))
                    getIntoArea = true; //1
                if ((pow(y, 2) + pow(x, 2)) >= 1)
                    getIntoArea = true; //2
        }
        if ((x >= 0) && (y <= 0)) {          // Проверка для четверти II
                if ((pow(y, 2) + pow(x, 2)) >= 1)
                    getIntoArea = true; //3
        }
        if ((x <= 0) && (y <= 0)) {          // Проверка для четверти III
                if ((pow(y, 2) + pow(x, 2)) >= 1)
                    getIntoArea = true; //4
                if (y <= (1 - x))
                    getIntoArea = true; //5
        }
        if ((x <= 0) && (y >= 0)) {          // Проверка для четверти IV
                if ((pow(y, 2) + pow(x, 2)) >= 1)
                    getIntoArea = true; //6
        }
    }
    if (getIntoArea) {
        printf("Точка x = %f  y = %f \n", x, y);
        printf("попадает в заштрихованную область");
    }
    return 0;
}