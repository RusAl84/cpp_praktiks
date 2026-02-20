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

    //DinoBaraClass* d0 = new DinoBaraClass();
    //d0->addElement(1);            
    //d0->addElement(9);
    //d0->addElement(8);
    //d0->addElement(4);
    //d0->display();
    //d0->delElement(3);
    //d0->display();
    //d0->delElement(2);
    //d0->display();
    //d0->delElement(1);
    //d0->display();
    //d0->delElement(0);
    //d0->display();
    //cout << endl << "Елемент 0 = " << d0->getElement(0);
    //d0->setElement(2, 777);
    //cout << endl << "Елемент 2 = " << d0->getElement(2);
    //d0->display();

    ////проверка записи в файл
    //DinoBaraClass* d1 = new DinoBaraClass(33);
    //write2file(d1);

    ////проверка конструктора копирования
    //DinoBaraClass* d2 = new DinoBaraClass(23);
    //DinoBaraClass d3 = *d2;
    //d3.display();

    DinoBaraClass* d4 = new DinoBaraClass(5);
    d4->display();
    d4->insertElement(0, 0);
    d4->insertElement(3, 333);
    d4->insertElement(5, 666);
    d4->display();
    cout << endl << "d4->getSize() =  " << d4->getSize();
    d4->insertElement(8, 777);
    d4->insertElement(9, 888);

    d4->display();


    //delete d2;
}

