#define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c"
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
    unsigned short c; // 0..31
    unsigned short f; // 0..1
    unsigned short b; // 0..1
    unsigned short n; // 0..255
    unsigned short UnitStateWord = 0;
    // Ввод данных
    c = 31;
    f = 1;
    b = 0;
    n = 255;
    // Запаковка
    UnitStateWord = (c & 0x1F) << 11;
    UnitStateWord |= (f & 1) << 9;
    UnitStateWord |= (b & 1) << 8;
    UnitStateWord |= n & 0xFF;

    printf("\nСлово состояния устройства (16-ричное число от 0 до 0xFFFF): %04x\n", UnitStateWord);
    printf("\nСлово состояния устройства (DEC): %d\n", UnitStateWord);
    //printf("\nСлово состояния устройства в двоичном виде:  %hu\n", UnitStateWord);

    // https://stackoverflow.com/questions/111928/is-there-a-printf-converter-to-print-in-binary-format
    printf("Двоичный код: %c%c%c%c%c%c%c%c:%c%c%c%c%c%c%c%c", BYTE_TO_BINARY(UnitStateWord >> 8), BYTE_TO_BINARY(UnitStateWord));
    // распаковка
    c = (UnitStateWord >> 11) & 0x1F;
    f = (UnitStateWord >> 9) & 1;
    b = (UnitStateWord >> 8) & 1;
    n = UnitStateWord & 0xFF;
    printf("\nс = %d\n", c);
    printf("f = %d\n", f);
    printf("b = %d\n", b);
    printf("n = %d\n", n);
    return 0;
}