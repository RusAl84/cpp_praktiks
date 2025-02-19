﻿#include <iostream>
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
    Shape* sh1 = new Shape();
    sh1->SaveToFile();
}