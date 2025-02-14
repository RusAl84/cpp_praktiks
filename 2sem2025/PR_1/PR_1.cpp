#include <iostream>
#include <windows.h>
#include <stdio.h>
#include "test_class.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout << "Практическая работа 1\n";
    test_class* dMas = new test_class(7);
    dMas->setElement(0, 0);
    dMas->setElement(1, 1);
    dMas->setElement(2, 2);
    dMas->setElement(3, 3);
    dMas->setElement(4, 4);
    dMas->setElement(5, 5);
    dMas->setElement(6, 6);
    dMas->display();

}

