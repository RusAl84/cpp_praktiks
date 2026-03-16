#include <iostream>
#include <windows.h>
#include <stdio.h>
#include "DinoBaraVirtClass.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout << "Практическая работа 2" << endl;
    DinoBaraVirtClass d1(10);
    d1.display();
    // проверка конструктора копирования 
    DinoBaraVirtClass d2=d1;
    DinoBaraVirtClass d3;
    // проверка переопределения оператора присваивания
    d3 = d1;
    d2.display();
    d3.display();

    A a1;
    a1.display();
    a1.calculate();
}
