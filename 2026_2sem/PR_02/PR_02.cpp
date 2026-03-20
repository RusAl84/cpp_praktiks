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

    // Для второго варианта
    //A a1;
    //a1.display();
    //cout << endl << "Введите r: ";
    //int r=0;
    //cin >> r;
    //a1.calculate(r);

    // Для 14 варианта
    //A a1;
    //a1.display();
    //cout << endl << "Введите A: ";
    //int A=0;
    //cin >> A;
    //cout << endl << "Введите B: ";
    //int b = 0;
    //cin >> b;
    //a1.calculate(A, b);

    B b1;
    b1.display();
    b1.calculate();

    C c1;
    c1.display();
    c1.calculate();
    c1.display();
}
