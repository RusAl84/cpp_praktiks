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

    printf("\n");
    for (int i=0;i<wigth;i++)
        printf("-");
    printf("\n");
    printf("|Отдел кадров                                                                  |\n");
    for (int i = 0; i < wigth; i++)
        printf("-");
    printf("\n");
    //        15                16              14          14
    printf("|Фамилия                    |Инициалы          |Год рожд       |Оклад          |");
    printf("\n");
    for (int i = 0; i < wigth; i++)
        printf("-");
    printf("\n");

    //Строка 1
    printf("|%s", surName1.c_str());
    for(int i=0;i< 14-surName1.size();i++)
        printf(" ");
    printf("|%s", ident1.c_str());
    for (int i = 0; i < 15-ident1.size(); i++)
        printf(" ");
    printf("|%d", bYear1);
    for (int i = 0; i < 13 - 4; i++)
        printf(" ");
    printf("|%.2f", salary1);
    for (int i = 0; i < 13 - 6; i++)
        printf(" ");
    printf("|\n");
    for (int i = 0; i < wigth; i++)
        printf("-");
    printf("\n");

    //Строка 2
    printf("|%s", surName2.c_str());
    for (int i = 0; i < 14 - surName2.size(); i++)
        printf(" ");
    printf("|%s", ident2.c_str());
    for (int i = 0; i < 15 - ident2.size(); i++)
        printf(" ");
    printf("|%d", bYear2);
    for (int i = 0; i < 13 - 4; i++)
        printf(" ");
    printf("|%.2f", salary2);
    for (int i = 0; i < 13 - 6; i++)
        printf(" ");
    printf("|\n");
    for (int i = 0; i < wigth; i++)
        printf("-");
    printf("\n");

    //Строка 3
    printf("|%s", surName3.c_str());
    for (int i = 0; i < 14 - surName3.size(); i++)
        printf(" ");
    printf("|%s", ident3.c_str());
    for (int i = 0; i < 15 - ident3.size(); i++)
        printf(" ");
    printf("|%d", bYear3);
    for (int i = 0; i < 13 - 4; i++)
        printf(" ");
    printf("|%.2f", salary3);
    for (int i = 0; i < 13 - 6; i++)
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
