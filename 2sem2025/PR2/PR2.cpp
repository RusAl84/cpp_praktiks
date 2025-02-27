#include <iostream>
#include <windows.h>
#include <stdio.h>
#include "Shape.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout << "Практическая работа 2\n";
    auto author = []()
        {
            cout << "Русаков Алексей БББО-02-24" << endl;
        };
    author();

    Shape* shapes[3];

    //shapes[0] = new Trapezia(10, 8, 5);
    //shapes[1] = new Treygolnik(20, 43, 47);
    //shapes[2] = new Romb(20, 10);

    for (int i = 0; i < 3; ++i)
    {
        cout << "Фигура: " << i + 1 << endl;
        cout << "Площадь: " << shapes[i]->Area() << endl;
        cout << "Периметр: " << shapes[i]->Perimetr() << endl;
        cout << endl;
    }


}