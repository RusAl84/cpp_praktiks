﻿#include <iostream>
#include <windows.h>
#include <stdio.h>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251); // Ввод с консоли в кодировке 1251
    SetConsoleOutputCP(1251);
    //cout << "Русский язык выводится корректно\n";
    int wigth = 80;
    string surName1 = "Иванов";
    string surName2 = "Петренко";
    string surName3 ="Панковский";
    string ident1="И.И.";
    string ident2="П.П.";
    string ident3="М.С.";
    int bYear1= 1975;
    int bYear2= 1956;
    int bYear3= 1967;
    float salary1= 517.50;
    float salary2= 219.10;
    float salary3= 300.00;
    string descr = "оклад установлен по состоянию на 1 января 2000 года";

    char tmpC1[32];
    char tmpC2[32];
    //Иванов И.И. 1975 517,50
    printf("Введите фамилию 1    инициалы1       год рожд 1      оклад1\n");
    scanf_s("%s %s %d %f", tmpC1, sizeof(tmpC1), tmpC2, sizeof(tmpC2), &bYear1, &salary1);
    surName1 = tmpC1;
    ident1 = tmpC2;
    //Петренко П.П. 1956 219,10
    printf("Введите фамилию 2    инициалы2       год рожд 2      оклад2\n");
    scanf_s("%s %s %d %f", tmpC1, sizeof(tmpC1), tmpC2, sizeof(tmpC2), &bYear2, &salary2);
    surName2 = tmpC1;
    ident2 = tmpC2;
    //Панковский М.С. 1967 300,00
    printf("Введите фамилию 3    инициалы3       год рожд 3      оклад3\n");
    scanf_s("%s %s %d %f", tmpC1, sizeof(tmpC1), tmpC2, sizeof(tmpC2), &bYear3, &salary3);
    surName3 = tmpC1;
    ident3 = tmpC2;


    printf("\n");
    for (int i=0;i<wigth;i++)
        printf("-");
    printf("\n");
    printf("|Отдел кадров                                                                  |\n");
    for (int i = 0; i < wigth; i++)
        printf("-");
    printf("\n");
    //                   28                     19              16          16
    printf("|Фамилия                    |Инициалы          |Год рожд       |Оклад          |");
    printf("\n");
    for (int i = 0; i < wigth; i++)
        printf("-");
    printf("\n");

    //Строка 1
    printf("|%s", surName1.c_str());
    for(int i=0;i< 27-surName1.size();i++)
        printf(" ");
    printf("|%s", ident1.c_str());
    for (int i = 0; i < 18-ident1.size(); i++)
        printf(" ");
    printf("|%d", bYear1);
    for (int i = 0; i < 15 - 4; i++)
        printf(" ");
    printf("|%.2f", salary1);
    for (int i = 0; i < 15 - 6; i++)
        printf(" ");
    printf("|\n");
    for (int i = 0; i < wigth; i++)
        printf("-");
    printf("\n");

    //Строка 2
    printf("|%s", surName2.c_str());
    for (int i = 0; i < 27 - surName2.size(); i++)
        printf(" ");
    printf("|%s", ident2.c_str());
    for (int i = 0; i < 18 - ident2.size(); i++)
        printf(" ");
    printf("|%d", bYear2);
    for (int i = 0; i < 15 - 4; i++)
        printf(" ");
    printf("|%.2f", salary2);
    for (int i = 0; i < 15 - 6; i++)
        printf(" ");
    printf("|\n");
    for (int i = 0; i < wigth; i++)
        printf("-");
    printf("\n");

    //Строка 3
    printf("|%s", surName3.c_str());
    for (int i = 0; i < 27 - surName3.size(); i++)
        printf(" ");
    printf("|%s", ident3.c_str());
    for (int i = 0; i < 18 - ident3.size(); i++)
        printf(" ");
    printf("|%d", bYear3);
    for (int i = 0; i < 15 - 4; i++)
        printf(" ");
    printf("|%.2f", salary3);
    for (int i = 0; i < 15 - 6; i++)
        printf(" ");
    printf("|\n");
    for (int i = 0; i < wigth; i++)
        printf("-");
    printf("\n");

    //descr     12
    printf("|Примечание: %s", descr.c_str());
    for (int i = 0; i < wigth - 14 - descr.size(); i++)
        printf(" ");
    printf("|\n");
    for (int i = 0; i < wigth; i++)
        printf("-");
    printf("\n");
}
