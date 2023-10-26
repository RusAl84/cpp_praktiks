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
    //проверка для четверти I
    if ((x >= 0) && (y >= 0)) {
        if (y <= (1 - x)) {
            getIntoArea = true; //1
        }
        if ( (( (pow(y,2) + pow(x, 2)) >= 1) )  && ((x <= 1) && (y <= 1)) ) {
            getIntoArea = true; //2
        }
    }
    //проверка для четверти II
    if ((x >= 0) && (y <= 0)) {

    }
    //проверка для четверти III
    if ((x <= 0) && (y <= 0)) {

    }
    //проверка для четверти IV
    if ((x <= 0) && (y >= 0)) {

    }

    if (getIntoArea) {
        printf("Точка x = %f  y = %f \n", x, y);
        printf("попадает в заштрихованную область");
    }
    return 0;
}