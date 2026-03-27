#include <iostream>
#include <windows.h>
#include <stdio.h>
#include "CapyStringHandle.h"

using namespace std;


int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout << "Практическая работа 3" << endl;
    CapyStringHandle sh1;
    sh1.ReadFromFile("data.txt");
}
