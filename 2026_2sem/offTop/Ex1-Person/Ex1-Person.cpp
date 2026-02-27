#include <iostream>
#include "PersonClass.h"
#include <windows.h>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout << "Hello World!\n";
    PersonClass sasha;
    sasha.name = "Санчес";
    cout << "АВВПВАВА";
    //sasha.age = 17;
    sasha.setAge(17);
    sasha.display();
    PersonClass* lina = new PersonClass;
    lina->name = "Лина";
    lina->setAge(18);
    PersonClass* spider = lina;
    lina = &sasha;
    lina->display();
}
