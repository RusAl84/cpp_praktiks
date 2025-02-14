#include <iostream>
#include <windows.h>
#include <stdio.h>
#include "test_class.h"

using namespace std;

//глобальную функцию для записи компонентного массива в файл;
void write2file(test_class* dMas) {
	// stdio.h
    FILE* textFile;
    fopen_s(&textFile, "textFile.txt", "w+");
    if (textFile){
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
    test_class* dMas = new test_class(7);
    //dMas->setElement(0, 24);
    //dMas->display();
    dMas->display();
    write2file(dMas);

    // перегруженную операцию присваивания operator=();
    // операции - функции в соответствии с вариативной частью задания.
    //    5. Основная программа(функция main) должна подтверждать 
    // работоспо - собность класса, содержать определение объектов 
    // класса и операторы, демонстрирующие вызов для этих объектов 
    // всех разработанных компонентных функций и перегруженных 
    // операций в соответствии с вариантами задания.

}

