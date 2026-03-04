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
            //DinoBaraClass* dino0 = new DinoBaraClass();
            //DinoBaraClass dino1;
            //DinoBaraClass dino2(5);
            //dino2.setElement(0, 888);
            //dino2.display();
            //DinoBaraClass dino8 = dino2;
            //dino8.display();

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

    //DinoBaraClass* d4 = new DinoBaraClass(5);
    //d4->display();
    //d4->insertElement(0, 0);
    //d4->insertElement(3, 333);
    //d4->insertElement(5, 666);
    //d4->display();
    //cout << endl << "d4->getSize() =  " << d4->getSize();
    //d4->insertElement(8, 777);
    //d4->insertElement(9, 888);

    //d4->display();

    // проверка 
    // перегруженную операцию присваивания operator=();
    //DinoBaraClass d71(3);
    //DinoBaraClass d72(4);
    //cout << "d1";
    //d71.display();
    //cout << endl << "d2";
    //d72.display();
    //d71 = d72;
    //cout << endl << "--------- d71 = d72" << endl << "d1";
    //d71.display();
    //cout << endl << "d2";
    //d72.display();
    
    // проверка 
    // перегруженную операцию  Вариант 25
    // 2 ^  Возведение в степень нечетных элементов 
    // компонентного массива. Показатель степени – правый операнд
    //DinoBaraClass d88(15);
    //d88.display();
    //d88 ^ 3;
    //d88.display();
   
    // 24 
    //DinoBaraClass d91(3);
    //d91.display();
    //DinoBaraClass d92(3);
    //d92.display();
    ////DinoBaraClass *d93 = new DinoBaraClass(4);
    ////d93->display();
    //cout << "Mega Ira ne s'ela Ezhika = ";
    //bool b1 = d91 < d92;
    //cout << b1;

    // 18
    //DinoBaraClass d991(3);
    //d991.display();
    //DinoBaraClass d992(3);
    //d992.display();
    //DinoBaraClass d993 = d991 / d992;
    //d993.display();

    // 23
    //DinoBaraClass d995(7);
    //d995.display();
    //d995.sortDesc();
    //d995.display();

    // 3
    //DinoBaraClass d996(7);
    //d996.display();
    //DinoBaraClass d997(7);
    //d997.display();
    //DinoBaraClass d998 = d996 * d997;
    //d998.display();

    //16
    //DinoBaraClass d999(7);
    //d999.display();
    //DinoBaraClass d900=!d999;
    //d900.display();
    //2
    //DinoBaraClass d9990(7);
    //d9990.display();
    //float _multiplication = *d9990;
    //cout <<endl<< "Произведение " << _multiplication;
    //5
    //DinoBaraClass d2002(7);
    //d2002.display();
    //*d2002;
    //d2002.display();
    //16 friend
    //DinoBaraClass d2003(7);
    //d2003.display();
    //d2003 / 8;
    //d2003.display();
    //2 fiend
    //DinoBaraClass d2004(7);
    //d2004.display();
    //~d2004;
    //d2004.display();

    // Настя проверка конструктора копирования
    //DinoBaraClass d10(5);
    //DinoBaraClass d11=d10;
    //d10.display();
    //d11.display();
    
    // Настя 10 вариант
    DinoBaraClass d1000(10);
    d1000.display();
    d1000=d1000 - 200;
    d1000.display();
}

