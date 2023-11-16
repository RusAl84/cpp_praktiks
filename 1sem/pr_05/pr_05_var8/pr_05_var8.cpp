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
    // OOOOOCDNNNNNNNNN
    unsigned short O; // 0b00011111 0..31 
    unsigned short C; // 0..1
    unsigned short D; // 0..1
    unsigned short N; // 0b0000000111111111 0..511
    unsigned short UnitStateWord = 0;
    // Ввод данных
    O = 31;
    C = 1;
    D = 1;
    N = 511;
    printf("\nO = %d\n", O);
    printf("C = %d\n", C);
    printf("D = %d\n", D);
    printf("N = %d\n", N);
    // Запаковка
    UnitStateWord = (N & 0b00011111) << 11;
    UnitStateWord |= (C & 1) << 10;
    UnitStateWord |= (D & 1) << 9;
    UnitStateWord |= N & 0b0000000111111111;
    printf("\nСлово состояния устройства (16-ричное число от 0 до 0xFFFF): %04x\n", UnitStateWord);
    printf("\nСлово состояния устройства (DEC): %d\n", UnitStateWord);
    // https://stackoverflow.com/questions/111928/is-there-a-printf-converter-to-print-in-binary-format
    printf("\nДвоичный код: %c%c%c%c%c%c%c%c:%c%c%c%c%c%c%c%c \n", \
        BYTE_TO_BINARY(UnitStateWord >> 8), BYTE_TO_BINARY(UnitStateWord));
    // Распаковка
    O = (UnitStateWord >> 11) & 0b00011111;
    C = (UnitStateWord >> 10) & 1;
    D = (UnitStateWord >> 9) & 1;
    N = UnitStateWord & 0b0000000111111111;
    printf("\nO = %d\n", O);
    printf("C = %d\n", C);
    printf("D = %d\n", D);
    printf("N = %d\n", N);
    return 0;
}