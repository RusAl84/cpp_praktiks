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
    test_class* dMas1 = new test_class(7);
    //dMas1->setElement(0, 24);
    //dMas1->display();
    dMas1->display();
    write2file(dMas1);
    // проверка конструктора копирования
    test_class* dMas2 = new test_class(7);
    dMas2 = dMas1;
    dMas2->display();

    // операции - функции в соответствии с вариативной частью задания.
    //    5. Основная программа(функция main) должна подтверждать 
    // работоспособность класса, содержать определение объектов 
    // класса и операторы, демонстрирующие вызов для этих объектов 
    // всех разработанных компонентных функций и перегруженных 
    // операций в соответствии с вариантами задания.

    // Вариант 31
    // Способ определения   Количество    Символ    Функциональность 
    // операциифункции      операндов     операции  операции
    // 
    // компонентная          2             <        Сравнение по сумме максимального 
    //                                              и минимального элементов компо-нентных массивов
    test_class* dMas3 = new test_class(7);
    cout << endl;
    dMas2->display();
    dMas3->display();
    cout <<endl << " < " << (dMas2 < dMas3);

    // Способ определения   Количество    Символ        Функциональность 
    // операциифункции      операндов     операции      операции
    // 
    // дружественная          1        ––(постфикс)       Декремент элементов компонентного массива
    //
    //https://metanit.com/cpp/tutorial/5.5.php?ysclid=m7erjs305i305639213
    //Декремент в C++ — это оператор, который уменьшает значение переменной на единицу. 
    //    https://learn.microsoft.com/ru-ru/cpp/cpp/increment-and-decrement-operator-overloading-cpp?view=msvc-170
}

