#include <iostream>
#include <Windows.h>
#include "ext_class/ExamsResultsClass.h"
//https://learn.microsoft.com/ru-ru/visualstudio/ide/class-designer/designing-and-viewing-classes-and-types?view=vs-2022
//https://habr.com/ru/articles/581228/
//https://learn.microsoft.com/ru-ru/cpp/build/adding-references-in-visual-cpp-projects?view=msvc-170

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251); // Ввод с консоли в кодировке 1251
    SetConsoleOutputCP(1251);
    cout << "ExamsResultsClass!\n";
    ExamsResultsClass* erc = new ExamsResultsClass();
    erc->editExamsResults();
    delete erc;
}

