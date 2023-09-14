#include <iostream>
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
    //string surName1 = "Иванов";
    //string surName2 = "Петренко";
    //string surName3 ="Панковский";
    //string ident1="И.И.";
    //string ident2="П.П.";
    //string ident3="М.С.";
    //int bYear1= 1975;
    //int bYear2= 1956;
    //int bYear3= 1967;
    //float salary1= 517.50;
    //float salary2= 219.10;
    //float salary3= 300.00;
    string descr = "оклад установлен по состоянию на 1 января 2000 года";

    string surName1;
    string surName2;
    string surName3;
    string ident1;
    string ident2;
    string ident3;
    int bYear1= 2000;
    int bYear2= 2000;
    int bYear3= 2000;
    float salary1 = 100;
    float salary2 = 100;
    float salary3 = 100;

    char tmpC1[64];
    char tmpC2[64];
    //Иванов И.И. 1975 517.50
    printf("Введите фамилию 1    инициалы1       год рожд 1      оклад1\n");
    scanf_s("%s %s", tmpC1, tmpC2, &bYear1, 64, 64);
    surName1 = tmpC1;
    ident1 = tmpC2;


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
