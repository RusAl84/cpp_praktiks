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
    DinoBaraClass* d0 = new DinoBaraClass();
    d0->addElement(1);            
    d0->addElement(9);
    d0->addElement(8);
    d0->addElement(4);
    d0->display();
    d0->delElement(3);
    d0->display();
    d0->delElement(2);
    d0->display();
    d0->delElement(1);
    d0->display();
    d0->delElement(0);
    d0->display();
    cout << endl << "Елемент 0 = " << d0->getElement(0);
    d0->setElement(2, 777);
    cout << endl << "Елемент 2 = " << d0->getElement(2);
    d0->display();

    //проверка записи в файл
    DinoBaraClass* d1 = new DinoBaraClass(33);
    write2file(d1);

    //проверка конструктора копирования
    DinoBaraClass* d2 = new DinoBaraClass(23);
    DinoBaraClass d3 = *d2;
    d3.display();


    
    delete d2;
}

