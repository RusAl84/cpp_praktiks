
#include <iostream>
#include <fstream>
#include "calc_class.h"

using namespace std;


int main()
{
    setlocale(LC_ALL, "Russian");
    std::cout << "Hello World!\n";
    calc_class *calc = new calc_class(7);
    calc->set(); // Задает данные для обработки
    calc->run(); // Обрабатывает данные
    calc->dislay(); // Выводит результат

}

