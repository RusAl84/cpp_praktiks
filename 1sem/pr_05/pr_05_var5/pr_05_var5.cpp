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
    // 1101TTDNNNNNNNNN
    unsigned short T; // 0b11 0..3
    unsigned short D; // 0..1
    unsigned short N; // 0b0000000111111111 0..511
    unsigned short UnitStateWord = 0;
    // Ввод данных
    T = 2;
    D = 0;
    N = 500;
    printf("\nT = %d\n", T);
    printf("D = %d\n", D);
    printf("N = %d\n", N);
    // Запаковка
    UnitStateWord = (0b1101) << 12;
    UnitStateWord |= (T & 0b11) << 10;
    UnitStateWord |= (D & 1) << 9;
    UnitStateWord |= N & 0b0000000111111111 << 0;
    printf("\nСлово состояния устройства (16-ричное число от 0 до 0xFFFF): %04x\n", UnitStateWord);
    printf("\nСлово состояния устройства (DEC): %d\n", UnitStateWord);
    // https://stackoverflow.com/questions/111928/is-there-a-printf-converter-to-print-in-binary-format
    printf("\nДвоичный код: %c%c%c%c%c%c%c%c:%c%c%c%c%c%c%c%c \n", \
        BYTE_TO_BINARY(UnitStateWord >> 8), BYTE_TO_BINARY(UnitStateWord));
    // Распаковка
    T = (UnitStateWord >> 10) & 0b11;
    D = (UnitStateWord >> 9) & 1;
    N = UnitStateWord & 0b0000000111111111;
    printf("\nT = %d\n", T);
    printf("D = %d\n", D);
    printf("N = %d\n", N);
    return 0;
}