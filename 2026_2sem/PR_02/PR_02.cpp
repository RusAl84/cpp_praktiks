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
    DinoBaraVirtClass megaKate=d1;
    //megaKate = d1;
    megaKate.display();
}
