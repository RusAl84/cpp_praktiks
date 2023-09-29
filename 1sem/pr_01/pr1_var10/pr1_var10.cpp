#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <windows.h>
#include <stdio.h>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int width = 80;

    //Тодайдзи Т 220 368.8
    //Якусидзи С 50 54.7
    //Дайандзи Д 10 12.2

    //объявление переменных

    string mon1, mon2, mon3;
    char school1 = 's', school2 = 's', school3 = 's';
    int monk1 = 0, monk2 = 0, monk3 = 0;
    double area1 = 0, area2 = 0, area3 = 0;

    string descr1 = "Буддийские монастыри Японии периода Нара";
    string descr2 = "Примечание: Т - Тендай; С - Сенгон; Д - Дзедзитсу";

    //ввод данных таблицы
    printf("Введите: монастырь 1   Школа 1   Количество монахов 1   Площадь земли(га) 1\n");
    char name[32];
    //https://learn.microsoft.com/ru-ru/cpp/c-runtime-library/reference/scanf-scanf-l-wscanf-wscanf-l?view=msvc-170&devlangs=cpp&f1url=%3FappId%3DDev16IDEF1%26l%3DRU-RU%26k%3Dk(STDIO%252Fscanf)%3Bk(scanf)%3Bk(DevLang-C%252B%252B)%3Bk(TargetOS-Windows)%26rd%3Dtrue
    scanf("%31s %c %d %lf", name, &school1, &monk1, &area1);
    //scanf_s("%s %c %d %f", name, sizeof(name), &school1, &monk1, &area1);
    mon1 = name;

    printf("Введите: монастырь 2   Школа 2   Количество монахов 2   Площадь земли(га) 2\n");
    scanf("%31s %c %d %lf", name, &school2, &monk2, &area2);
    //scanf_s("%s %c %d %f", name, sizeof(name), &school2, &monk2, &area2);
    mon2 = name;

    printf("Введите: монастырь 3   Школа 3   Количество монахов 3   Площадь земли(га) 3\n");
    scanf("%31s %c %d %lf", name, &school3, &monk3, &area3);
    //scanf_s("%s %c %d %f", name, sizeof(name), &school3, &monk3, &area3);
    mon3 = name;

    //верхняя граница таблицы
    for (int i = 0; i < width; i++) {
        printf("-");
    }
    printf("\n");

    //первая строка
    printf("| %-77s|\n", descr1.c_str());

    for (int i = 0; i < width; i++) {
        printf("-");
    }
    printf("\n");

    //вторая строка 18 11 24 22
    printf("| Название         | Школа     | Количество монахов     | Площадь земли        |\n");
    for (int i = 0; i < width; i++) {
        printf("-");
    }
    printf("\n");

    //вывод данных о первом монастыре
    printf("| %-17s| %-10c| %-23d| %-21f|\n", mon1.c_str(), school1, monk1, area1);

    for (int i = 0; i < width; i++) {
        printf("-");
    }
    printf("\n");

    //вывод данных о втором монастыре
    printf("| %-17s| %-10c| %-23d| %-21f|\n", mon2.c_str(), school2, monk2, area2);

    for (int i = 0; i < width; i++) {
        printf("-");
    }
    printf("\n");

    //вывод данных о третьем монастыре
    printf("| %-17s| %-10c| %-23d| %-21f|\n", mon3.c_str(), school3, monk3, area3);

    for (int i = 0; i < width; i++) {
        printf("-");
    }
    printf("\n");

    //последняя строка с примечанием
    printf("| %-77s|\n", descr2.c_str());
    for (int i = 0; i < width; i++) {
        printf("-");
    }

    return 0;
}