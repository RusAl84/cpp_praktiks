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
    unsigned short N; // 1111 0..15 
    unsigned short E; // 0..1
    unsigned short C; // 111111111 0..511
    unsigned short P; // 0..1
    unsigned short UnitStateWord = 0;
    // Ввод данных
    N = 15;
    E = 1;
    C = 511;
    P = 1;
    printf("\nN = %d\n", N);
    printf("E = %d\n", E);
    printf("C = %d\n", C);
    printf("P = %d\n", P);
    // Запаковка
    // NNNNECCC:CCCCCC0P
    UnitStateWord = (N & 0x0F) << 12;
    UnitStateWord |= (E & 1) << 11;
    UnitStateWord |= (C & 0x1FF) << 2;
    UnitStateWord |= P & 1;
    printf("\nСлово состояния устройства (16-ричное число от 0 до 0xFFFF): %04x\n", UnitStateWord);
    printf("\nСлово состояния устройства (DEC): %d\n", UnitStateWord);
    // https://stackoverflow.com/questions/111928/is-there-a-printf-converter-to-print-in-binary-format
    printf("\nДвоичный код: %c%c%c%c%c%c%c%c:%c%c%c%c%c%c%c%c \n", BYTE_TO_BINARY(UnitStateWord >> 8), BYTE_TO_BINARY(UnitStateWord));
    // распаковка
    N = (UnitStateWord >> 12) & 0x0F;
    E = (UnitStateWord >> 11) & 1;
    C = (UnitStateWord >> 2) & 0x1FF;
    P = UnitStateWord & 1;
    printf("\nN = %d\n", N);
    printf("E = %d\n", E);
    printf("C = %d\n", C);
    printf("P = %d\n", P);
    return 0;
}