#include <iostream>
#include <windows.h>
#include <stdio.h>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251); // Ввод с консоли в кодировке 1251
    SetConsoleOutputCP(1251);

    //Фирма Количество. продуктов Годовой объем продажи ($) Часть рынка (%)
    string brand1 = "Oracle";
    string brand2 = "IBM";
    string brand3 = "Microsoft";
    int count1 = 1;
    int count2 = 2;
    int count3 = 3;
    unsigned int sale1 = 2488000000;
    int sale2 = 2392000000;
    int sale3 = 1048000000;
    float part1 = 31.1;
    float part2 = 29.9;
    float part3 = 13.1;

    int wigth = 80;
    printf("\n");
    for (int i = 0; i < wigth; i++)
        printf("-");
    printf("\n| Фирмы - производители СКБД                                                   |");
    printf("\n");
    for (int i = 0; i < wigth; i++)
        printf("-");
    printf("\n|   Фирма     |Количество продуктов|Годовой объем продажи($)|Часть рынка(проц.)|");
    printf("\n");
    for (int i = 0; i < wigth; i++)
        printf("-");
    printf("\n");

    printf("|%s", brand1.c_str());
    for (int i = 0; i < 13 - brand1.size(); i++)
        printf(" ");
    printf("|%d", count1);
    for (int i = 0; i < 19; i++)
        printf(" ");
    printf("|%u", sale1);
    for (int i = 0; i < 14; i++)
        printf(" ");
    printf("|%.2f", part1);
    for (int i = 0; i < 13; i++)
        printf(" ");
    printf("|\n");
    for (int i = 0; i < wigth; i++)
        printf("-");
    printf("\n");

    printf("|%s", brand2.c_str());
    for (int i = 0; i < 13 - brand2.size(); i++)
        printf(" ");
    printf("|%d", count2);
    for (int i = 0; i < 19; i++)
        printf(" ");
    printf("|%u", sale2);
    for (int i = 0; i < 14; i++)
        printf(" ");
    printf("|%.2f", part2);
    for (int i = 0; i < 13; i++)
        printf(" ");
    printf("|\n");
    for (int i = 0; i < wigth; i++)
        printf("-");
    printf("\n");

    printf("|%s", brand3.c_str());
    for (int i = 0; i < 13 - brand3.size(); i++)
        printf(" ");
    printf("|%d", count3);
    for (int i = 0; i < 19; i++)
        printf(" ");
    printf("|%u", sale3);
    for (int i = 0; i < 14; i++)
        printf(" ");
    printf("|%.2f", part3);
    for (int i = 0; i < 13; i++)
        printf(" ");
    printf("|\n");
    for (int i = 0; i < wigth; i++)
        printf("-");
    printf("\n");



    return 0;
}