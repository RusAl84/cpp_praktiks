#include <iostream>
#include <windows.h>
#include <stdio.h>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251); // Ввод с консоли в кодировке 1251
    SetConsoleOutputCP(1251);

    //Процессор Частота (Mgz) RAM (Mb) Тип

    string cpu1 = "Pentium-III";
    string cpu2 = "AMD-К6";
    string cpu3 = "PowerPC";
    int freq1 = 233;
    int freq2 = 166;
    int freq3 = 620;
    int ram1 = 128;
    int ram2 = 128;
    int ram3 = 128;
    char type1 = 'C';
    char type2 = 'C';
    char type3 = 'R';


    char tmp[32];
    //Pentium-III 233 128 C
    //Celeron-III 777 777 X
    printf("Введите процессор1    частота(Mgz)1       RAM(Mb)1       Тип1      \n");
    scanf_s("%s %d %d %d", tmp, sizeof(tmp), &freq1, &ram1, &type1);
    cpu1 = tmp;
    printf("Введите процессор2    частота(Mgz)2       RAM(Mb)2       Тип2      \n");
    scanf_s("%s %d %d %d", tmp, sizeof(tmp), &freq2, &ram2, &type2);
    cpu2 = tmp;
    printf("Введите процессор3    частота(Mgz)3       RAM(Mb)3       Тип3      \n");
    scanf_s("%s %d %d %d", tmp, sizeof(tmp), &freq3, &ram3, &type3);
    cpu3 = tmp;

    int wigth = 80;
    printf("\n");
    for (int i = 0; i < wigth; i++)
        printf("-");
    printf("\n");
    printf("|Характеристики ПЭВМ                                                           |");    
    printf("\n");
    for (int i = 0; i < wigth; i++)
        printf("-");
    printf("\n");
    printf("|Процессор             | Частота(Mgz)          |  RAM(Mb)       |     Тип      |");
    printf("\n");
    for (int i = 0; i < wigth; i++)
        printf("-");
    printf("\n");
    
    //строка 1
    printf("|%s", cpu1.c_str());
    for (int i = 0; i < 22 - cpu1.size(); i++)
        printf(" ");
    printf("|%d", freq1);
    for (int i = 0; i < 20; i++)
        printf(" ");
    printf("|%d", ram1);
    for (int i = 0; i < 13 ; i++)
        printf(" ");
    printf("|%c", type1);
    for (int i = 0; i < 13; i++)
        printf(" ");
    printf("|\n");
    for (int i = 0; i < wigth; i++)
        printf("-");
    printf("\n");


    //строка 2
    printf("|%s", cpu2.c_str());
    for (int i = 0; i < 22 - cpu2.size(); i++)
        printf(" ");
    printf("|%d", freq2);
    for (int i = 0; i < 20; i++)
        printf(" ");
    printf("|%d", ram2);
    for (int i = 0; i < 13; i++)
        printf(" ");
    printf("|%c", type2);
    for (int i = 0; i < 13; i++)
        printf(" ");
    printf("|\n");
    for (int i = 0; i < wigth; i++)
        printf("-");
    printf("\n");

    //строка 3
    printf("|%s", cpu3.c_str());
    for (int i = 0; i < 22 - cpu3.size(); i++)
        printf(" ");
    printf("|%d", freq3);
    for (int i = 0; i < 20; i++)
        printf(" ");
    printf("|%d", ram3);
    for (int i = 0; i < 13; i++)
        printf(" ");
    printf("|%c", type3);
    for (int i = 0; i < 13; i++)
        printf(" ");
    printf("|\n");
    for (int i = 0; i < wigth; i++)
        printf("-");
    printf("\n");

    printf("|Тип: C - CISC-процессор, R - RISC-процессор                                   |");
    printf("\n");
    for (int i = 0; i < wigth; i++)
        printf("-");
    printf("\n");

    return 0;
}