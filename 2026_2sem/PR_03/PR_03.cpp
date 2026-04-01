#include <iostream>
#include <windows.h>
#include <stdio.h>
#include "CapyStringHandle.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout << "Практическая работа 3" << endl;
    CapyStringHandle sh1;
    sh1.ReadFromFile("data.txt");
    sh1.display();
    sh1.extractWords();
    sh1.wordsCount();
    //string s1 = "АндромедА";
    //if (s1.starts_with(s1[s1.size()-1]))
    //    cout << "ок";
    sh1.WriteToFile("decision.txt");
    //sh1.var2();
    //sh1.var3();
    //sh1.var4();
    //sh1.var5();
    sh1.var7();
    //sh1.var10();
    //sh1.var12();
    //sh1.var17();
    //sh1.var18();
    //sh1.var24();
    //CapyStringHandle << sh1;
}
