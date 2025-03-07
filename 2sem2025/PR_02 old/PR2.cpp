#include <iostream>
#include <windows.h>
#include <stdio.h>   
#include "Shape.h"   
#include "RingSector.h"     
#include "IsoscelesTriangle.h"
#include "RegularPolygon.h"   


using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout << "Практическая работа 2\n";
    auto author = []()
        {
            cout << "Русаков Алексей БИСО-02-24" << endl;
        };
    author();

    Shape* shapes[3];
    shapes[0] = new RingSector(10, 8, 37);
    shapes[1] = new IsoscelesTriangle(18, 30, 34);
    shapes[2] = new RegularPolygon(10, 10, 7);

    for (int i = 0; i < 3; ++i)
    {
        cout << "Фигура " << i + 1 << ": ";
        shapes[i]->display();
        cout << endl;
        cout << "Площадь: " << shapes[i]->Area() << endl;
        cout << "Периметр: " << shapes[i]->Perimetr() << endl;
        cout << endl;
    }

    char fileName[20]="log.txt";

    ofstream outfile(fileName, ios_base::out);
    if (!outfile.is_open())
    {
        cout << "Ошибка открытия файла" << endl;
        return -1;
    }
    else
    {
        for (int i = 0; i < 3; ++i)
        {
            shapes[i]->SaveToFIle(outfile);
        }
    }

    for (int i = 0; i < 3; ++i)
    {
        delete shapes[i];
    }
    return 0;
}