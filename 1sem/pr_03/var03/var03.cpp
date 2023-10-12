#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251); // Ввод с консоли в кодировке 1251
    SetConsoleOutputCP(1251);
    int ch = 'M';
    //1 - +
    //2 - -
    //3 - *
    //4 – все остальные
    switch (ch) {
    case '+': 
        printf("1\n");
    default:
        printf("4\n");
    }


    return 0;
}