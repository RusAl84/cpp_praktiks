#define BYTE_TO_BINARY(byte)  \
  ((byte) & 0x80 ? '1' : '0'), \
  ((byte) & 0x40 ? '1' : '0'), \
  ((byte) & 0x20 ? '1' : '0'), \
  ((byte) & 0x10 ? '1' : '0'), \
  ((byte) & 0x08 ? '1' : '0'), \
  ((byte) & 0x04 ? '1' : '0'), \
  ((byte) & 0x02 ? '1' : '0'), \
  ((byte) & 0x01 ? '1' : '0') 

#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251); // Ввод с консоли в кодировке 1251
    SetConsoleOutputCP(1251);
    // HHTTTTTTTTTSSSSS
    unsigned short H; // 0..3 0b11
    unsigned short T; // 0..511 0b0000000111111111
    unsigned short S; // 0..31 0b11111
    unsigned short UnitStateWord = 0;
    // Ввод данных
    H = 3;
    T = 511;
    S = 31;
    printf("\nH = %d\n", H);
    printf("T = %d\n", T);
    printf("S = %d\n", S);
    // Запаковка
    UnitStateWord = (H & 0b11) << 14;
    UnitStateWord |= (T & 0b0000000111111111) << 5;
    UnitStateWord |= S & 0b11111;
    printf("\nСлово состояния устройства (16-ричное число от 0 до 0xFFFF): %04x\n", UnitStateWord);
    printf("\nСлово состояния устройства (DEC): %d\n", UnitStateWord);
    // https://stackoverflow.com/questions/111928/is-there-a-printf-converter-to-print-in-binary-format
    printf("\nДвоичный код: %c%c%c%c%c%c%c%c:%c%c%c%c%c%c%c%c \n", \
        BYTE_TO_BINARY(UnitStateWord >> 8), BYTE_TO_BINARY(UnitStateWord));
    // Распаковка
    H = (UnitStateWord >> 14) & 0b11;
    T = (UnitStateWord >> 5) & 0b0000000111111111;
    S = UnitStateWord & 0b0000000111111111;
    printf("\nH = %d\n", H);
    printf("T = %d\n", T);
    printf("S = %d\n", S);
    return 0;
}