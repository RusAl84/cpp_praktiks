#include <iostream>
#include <cstdio>

using namespace std;
#pragma warning(disable : 4996)
#define MAXLINE 255 //максимальная длина строки
int main()
{
    //копирование файла in в файл out
    FILE* in, //исходный файл
        * out; //принимающий файл
    char buf[MAXLINE];
    //строка, с помощью которой выполняется копирование
    in = fopen("f1.txt", "r");
    //открыть исходный файл для чтения
    out = fopen("f2.txt", "w");
    //открыть принимающий файл для записи
    while (fgets(buf, MAXLINE, in) != 0)
        //прочитать байты из файла in в строку buf
        fputs(buf, out);
        fputs(buf, out);
    //записать байты из строки buf в файл out
    fclose(in); //закрыть исходный файл
    fclose(out);//закрыть принимающий файл
    system("pause");
    return 0;


    std::cout << "Hello World!\n";
}

