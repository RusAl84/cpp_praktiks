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
    // CCCCEIP000KKK000
    unsigned short C; // 0b1111 0..15
    unsigned short E; // 0..1
    unsigned short I; // 0..1
    unsigned short P; // 0..1
    unsigned short K; // 0b111 0..3
    unsigned short UnitStateWord = 0;
    // Ввод данных
    C = 7;
    E = 1;
    I = 0;
    P = 1;
    K = 3;
    printf("\nC = %d\n", C);
    printf("E = %d\n", E);
    printf("I = %d\n", I);
    printf("P = %d\n", P);
    printf("K = %d\n", K);
    // Запаковка
    UnitStateWord = (C & 0b1111) << 12;
    UnitStateWord |= (E & 1) << 11;
    UnitStateWord |= (I & 1) << 10;
    UnitStateWord |= (P & 1) << 9;
    UnitStateWord |= (K & 0b111) << 3;
    printf("\nСлово состояния устройства (16-ричное число от 0 до 0xFFFF): %04x\n", UnitStateWord);
    printf("\nСлово состояния устройства (DEC): %d\n", UnitStateWord);
    // https://stackoverflow.com/questions/111928/is-there-a-printf-converter-to-print-in-binary-format
    printf("\nДвоичный код: %c%c%c%c%c%c%c%c:%c%c%c%c%c%c%c%c \n", \
        BYTE_TO_BINARY(UnitStateWord >> 8), BYTE_TO_BINARY(UnitStateWord));
    // Распаковка
    C = (UnitStateWord >> 12) & 0b1111;
    E = (UnitStateWord >> 11) & 1;
    I = (UnitStateWord >> 10) & 1;
    P = (UnitStateWord >> 9) & 1;
    K = (UnitStateWord >> 3) & 0b111;
    printf("\nC = %d\n", C);
    printf("E = %d\n", E);
    printf("I = %d\n", I);
    printf("P = %d\n", P);
    printf("K = %d\n", K);
    return 0;
}