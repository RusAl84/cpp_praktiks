#include <iostream>
#include <windows.h>
#include <stdio.h>
#include "DinoBaraClass.h"

using namespace std;

//глобальную функцию для записи компонентного массива в файл;
void write2file(DinoBaraClass* dMas) {
    // stdio.h
    FILE* textFile;
    fopen_s(&textFile, "tetFile.txt", "w+");
    if (textFile) {
        int size = dMas->getSize();
        for (int i = 0; i < size; i++)
            fprintf(textFile, "%d %\n", dMas->getElement(i));
        fclose(textFile);
    }
}



int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout << "Практическая работа 1\n";
    //Разработать класс, моделирующий 
    //динамический массив целых чисел и его обработку
    DinoBaraClass* d1 = new DinoBaraClass();
    d1->addElement(1);            
    d1->addElement(9);
    d1->addElement(8);
    d1->addElement(4);
    d1->display();
    d1->delElement(3);
    d1->display();
    d1->delElement(2);
    d1->display();
    d1->delElement(1);
    d1->display();
    d1->delElement(0);
    d1->display();
    //cout << endl << "Елемент 0 = " << d1->getElement(0);
    //d1->Edit(2, 777);
    //cout << endl << "Елемент 2 = " << d1->getElement(2);
    //d1->display();


    delete d1;
}

