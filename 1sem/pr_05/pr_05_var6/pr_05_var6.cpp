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
    // SSS0D0F0BBBBBBBB
    unsigned short S; // 0b111 0..3 
    unsigned short D; // 0..1
    unsigned short F; // 0..1
    unsigned short B; // 0b11111111 0..255
    unsigned short UnitStateWord = 0;
    // Ввод данных
    S = 3;
    D = 1;
    F = 1;
    B = 222;
    printf("\nS = %d\n", S);
    printf("D = %d\n", D);
    printf("F = %d\n", F);
    printf("B = %d\n", B);
    // Запаковка
    UnitStateWord = (S & 0b111) << 13;
    UnitStateWord |= (D & 1) << 11;
    UnitStateWord |= (F & 1) << 9;
    UnitStateWord |= B & 0b11111111;
    printf("\nСлово состояния устройства (16-ричное число от 0 до 0xFFFF): %04x\n", UnitStateWord);
    printf("\nСлово состояния устройства (DEC): %d\n", UnitStateWord);
    // https://stackoverflow.com/questions/111928/is-there-a-printf-converter-to-print-in-binary-format
    printf("\nДвоичный код: %c%c%c%c%c%c%c%c:%c%c%c%c%c%c%c%c \n", \
        BYTE_TO_BINARY(UnitStateWord >> 8), BYTE_TO_BINARY(UnitStateWord));
    // Распаковка
    S = (UnitStateWord >> 13) & 0b111;
    D = (UnitStateWord >> 11) & 1;
    F = (UnitStateWord >> 9) & 1;
    B = UnitStateWord & 0b11111111;
    printf("\nS = %d\n", S);
    printf("D = %d\n", D);
    printf("F = %d\n", F);
    printf("B = %d\n", B);
    return 0;
}