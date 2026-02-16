#include <iostream>
#include <windows.h>
#include <stdio.h>
#include "DinoBaraClass.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout << "Практическая работа 1\n";
    DinoBaraClass* d1 = new DinoBaraClass();
    d1->Add(1);
    d1->Add(9);
    d1->Add(8);
    d1->Add(4);
    d1->display();
}

