// sema_test.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");

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
    student* ivan = new student();
    ivan->name = "Иван молодец";
    ivan->drinkType = "Балтика 7";
    ivan->loadCapacity = 1000;
    vector <student> tripNaDachuMihalicha;
    tripNaDachuMihalicha.push_back(*sema);
    tripNaDachuMihalicha.push_back(*dima);
    tripNaDachuMihalicha.push_back(*ivan);

    for (auto item : tripNaDachuMihalicha) {
        cout << "Имя: " << item.name << " Что пил: " << item.drinkType << " Сколько выпил: " << item.loadCapacity << " мл." << endl;
    }



    std::cout << "Hello World!\n";
}
