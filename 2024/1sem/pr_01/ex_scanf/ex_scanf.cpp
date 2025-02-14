#include <iostream>
#include <stdio.h>
#include <windows.h>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251); // Ввод с консоли в кодировке 1251
	SetConsoleOutputCP(1251);

    // https://learn.microsoft.com/ru-ru/cpp/c-runtime-library/reference/scanf-s-scanf-s-l-wscanf-s-wscanf-s-l?view=msvc-170&devlangs=cpp&f1url=%3FappId%3DDev16IDEF1%26l%3DRU-RU%26k%3Dk(STDIO%252Fscanf_s)%3Bk(scanf_s)%3Bk(DevLang-C%252B%252B)%3Bk(TargetOS-Windows)%26rd%3Dtrue
    int      i,
        result;
    float    fp;
    char     c,
        s[80];
    wchar_t  wc,
        ws[80];

    //71 98.6 h z Byte characters

    result = scanf_s("%d %f %c %C %s %S", &i, &fp, &c, 1,
        &wc, 1, s, (unsigned)_countof(s), ws, (unsigned)_countof(ws));
    printf("The number of fields input is %d\n", result);
    printf("The contents are: %d %f %c %C %s %S\n", i, fp, c,
        wc, s, ws);

	return 0;
}
