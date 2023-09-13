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
    int wigth = 60;
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
    char descr[100] = " оклад установлен по состоянию на 1 января 2000 года";

    printf("\n");
    for (int i=0;i<wigth;i++)
        printf("-");
    printf("\n");
    //        22                24              21          19
    printf("|Фамилия       |Инициалы       |Год рожд     |Оклад        |\n");
    printf("\n");
    for (int i = 0; i < wigth; i++)
        printf("-");
    printf("\n");

    //Строка 1
    printf("|%s", surName1.c_str());
    for(int i=0;i< 22-8-surName1.size();i++)
        printf(" ");
    printf("|%s", ident1.c_str());
    for (int i = 0; i < 24 -8 - ident1.size(); i++)
        printf(" ");
    printf("|%d", bYear1);



    printf("| %d ", sizeof(surName2));
    printf("\n");
    for (int i = 0; i < wigth; i++)
        printf("-");
    printf("\n");


}
