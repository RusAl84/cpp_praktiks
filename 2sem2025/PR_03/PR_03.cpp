#include <iostream>
#include <windows.h>
#include <stdio.h>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout << "Практическая работа 3\n";
    auto author = []()
        {
            cout << "Русаков Алексей БИСО-02-24" << endl;
        };
    author();
    // Работа со строками
    // https://metanit.com/cpp/tutorial/12.1.php
    // https://metanit.com/cpp/tutorial/12.9.php
    return 0;
}