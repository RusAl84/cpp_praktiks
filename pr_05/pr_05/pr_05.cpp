#include <iostream>
#include <cstdio>
#include <string>

using namespace std;
#pragma warning(disable : 4996)
#define MAXLINE 255 //максимальная длина строки
int main()
{
    //var1
        //копирование файла in в файл out
    //FILE* in, //исходный файл
    //    * out; //принимающий файл
    //char buf[MAXLINE];
    ////строка, с помощью которой выполняется копирование
    //in = fopen("f1.txt", "r");
    ////открыть исходный файл для чтения
    //out = fopen("f2.txt", "w");
    ////открыть принимающий файл для записи
    //while (fgets(buf, MAXLINE, in) != 0)
    //    //прочитать байты из файла in в строку buf
    //    fputs(buf, out);
    //fputs(buf, out);
    ////записать байты из строки buf в файл out
    //fclose(in); //закрыть исходный файл
    //fclose(out);//закрыть принимающий файл
    //system("pause");
    //return 0;

    //копирование файла in в файл out
    setlocale(LC_ALL, "rus");
    FILE* in, //исходный файл
        * out; //принимающий файл
    char buf[MAXLINE];
    char write_buf[MAXLINE];
    //строка, с помощью которой выполняется копирование
    in = fopen("f1.txt", "w");
    char write_text[] = "Данила и Ярослав обьелся груш;)12345 и Никита тоже;)\nПОйдут служить в Нагорный Карабах;)\0";
    fputs(write_text, in);
    //открыть исходный файл для чтения
    out = fopen("f2.txt", "w");
    //открыть принимающий файл для записи
    int row = 0;
    int kol_cifr = 0;
    int kol_ne_cifr = 0;
    while (fgets(buf, MAXLINE, in) != 0)
        //прочитать байты из файла in в строку buf
        

    kol_ne_cifr = strlen(buf) - kol_cifr;
    cout <<endl<<"Количество цифр: "<< kol_cifr<<endl;
    cout << endl << "Количество не цифр: " << kol_ne_cifr<<endl;



        //fputs(write_buf, out);
    //записать байты из строки buf в файл out
    fclose(in); //закрыть исходный файл
    fclose(out);//закрыть принимающий файл
    system("pause");
    return 0;


    std::cout << "Hello World!\n";
}

