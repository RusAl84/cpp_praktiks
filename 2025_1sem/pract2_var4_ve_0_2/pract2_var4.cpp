#include <iostream>
#include <windows.h>
using namespace std;
void display_byte(char  data) {
    char mas[9] = "00000000";
    if ((data) & 128)  mas[0] = '1';
    if ((data) & 64)  mas[1] = '1';
    if ((data) & 32)  mas[2] = '1';
    if ((data) & 16)  mas[3] = '1';
    if ((data) & 8)  mas[4] = '1';
    if ((data) & 4)  mas[5] = '1';
    if ((data) & 2)  mas[6] = '1';
    if ((data) & 1)  mas[7] = '1';
    printf("%s", mas);
}
int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251); // Ввод с консоли в кодировке 1251
    SetConsoleOutputCP(1251);
    // вывод на экран сообщения об авторе программы в формате: фамилия, 
    // инициалы, номер группы, номер варианта;
    printf("\nРусаков А.М., БИСО-0x-25, 4 вариант");
    long data = 1234567890; // ввод исходных данных // тип short занимает в памяти 4 байта (32 бит) 
    printf("\nВвод исходных данных:\n");
    //scanf_s("%d", &data); // нужно раскоментить перед сдачей
    printf("%d\n", data);   // нужно закоментить перед сдачей
    // Получить две динамические переменные типа short: 
    // первая составлена из младшего и старшего байтов введенного числа, 
    // вторая – из оставшихся.
    short* var1 = new short;     // тип short занимает в памяти 2 байта (16 бит)
    short* var2 = new short;
    unsigned char b1, b2, b3, b4;
    b1 = *(char*)&data;
    b2 = *((char*)&data+1);
    b3 = *((char*)&data+2);
    b4 = *((char*)&data+3);
    *var1 = b1;
    *((char*)var1+1) = b4;
    short N = 3;  
    // Если N-й бит первого числа равен 1, то поменять 
    // во втором числе местами старший и младший байты.
    short n_bit = *var1 >> N & 1;
    printf("%d-й бит первого числа равен %d\n", N, n_bit);
    if (n_bit == 1) {
        *var2 = b2;
        *((char*)var2 + 1) = b3;
    }
    else {
        *var2 = b3;
        *((char*)var2 + 1) = b2;
    }
    // Вывести полученные числа на экран.
    printf("Двоичный код исходного числа: ");
    display_byte(b1); printf(":");
    display_byte(b2); printf(":");
    display_byte(b3); printf(":");
    display_byte(b4); printf("\n");
    printf("Двоичный код числа 1: ");
    b1 = *(char*)var1;
    b2 = *((char*)var1 + 1);
    display_byte(b1); printf(":");
    display_byte(b2); printf("\n");
    printf("Двоичный код числа 2: ");
    b1 = *(char*)var2;
    b2 = *((char*)var2 + 1);
    display_byte(b1); printf(":");
    display_byte(b2); printf("\n");
    printf("Шестнадцатиричный код исходного числа: %04x\n", data);
    printf("Шестнадцатиричный код числа 1: %04x\n", var1);
    printf("Шестнадцатиричный код числа 2: %04x\n", var2);
    printf("Десятичный код исходного числа: %d\n", data);
    printf("Десятичный код числа 1: %d\n", var1);
    printf("Десятичный код числа 2: %d\n", var2);
    delete var1;
    delete var2;
}