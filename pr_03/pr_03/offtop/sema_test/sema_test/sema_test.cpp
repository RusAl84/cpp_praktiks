// sema_test.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
using namespace std;
int main()
{
    struct student {
        string name;
        int loadCapacity;
        string drinkType;
    };
    student *sema = new student();
    sema->name = "Семён шалун";
    sema->drinkType = "Водка absolut";
    sema->loadCapacity = 800;
    student* dima = new student();
    dima->name = "Дима засланец";
    dima->drinkType = "Henessy XO";
    dima->loadCapacity = 600;

    vector <student> tripNaDachuMihalicha;
    tripNaDachuMihalicha.push_back(*sema);
    for (auto item : tripNaDachuMihalicha) {
        cout << item.name << item.drinkType << item.loadCapacity << endl;
    }



    std::cout << "Hello World!\n";
}
