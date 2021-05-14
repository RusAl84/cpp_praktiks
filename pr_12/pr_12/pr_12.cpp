// pr_12.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "windows.h"
#include <iostream>
#include <string.h>
#include <conio.h>
#include <stdio.h>
using namespace std;

class menuClass {
public:
    string items[30][40];
    int selectedItem;
    int count;

    menuClass() {
        selectedItem = 0;
    }
    void setDown() {
        selectedItem++;
        if (selectedItem > count - 1)
            selectedItem = 0;
    }
    void setUp() {
        selectedItem--;
        if (selectedItem < 0)
            selectedItem = count - 1;
    }

    //где <A> и <B> — шестнадцатеричные цифры — первая задает цвет фона, а вторая — цвет переднего плана(цвет шрифта).
    //    Значения цифр
    //    0 — черный
    //    1 — синий
    //    2 — зеленый
    //    3 — голубой
    //    4 — красный
    //    5 — лиловый
    //    6 — желтый
    //    7 — белый
    //    8 — серый
    //    9 — свело - синий
    //    A — светло - зеленый
    //    B — светло - голубой
    //    С — светло - красный
    //    E — светло - желтый
    //    F — ярко - белый
    //system("Color 15");
    void draw() {
        system("cls");
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        for (int i = 0;i<5;i++){
            
            if (i == selectedItem) {
                SetConsoleTextAttribute(hConsole, 13);
                cout << " * "<<items[i]->c_str() << endl;
            }
            else{
                SetConsoleTextAttribute(hConsole, 15);
                cout << "   " << items[i]->c_str() << endl;
            }
            
        }
    }

    void run() {
        char ch = ' ';
        while (ch != 13) {
            draw();
            Sleep(100);
            ch = _getch();
            //cout << endl << ch <<endl;
            if (ch == 80)  // вниз
                setDown();
            if (ch == 72)
                setUp();
        }

    }

};
int main()
{
    menuClass menu1 = menuClass();
    menu1.count = 5;
    menu1.items[0]->assign("Выбрать файл для загрузки БД студентов");
    menu1.items[1]->assign("Сохранить БД студентов в файл");
    menu1.items[2]->assign("Вывести список студентов");
    menu1.items[3]->assign("Добавить студента");
    menu1.items[4]->assign("Выход");
    menu1.run();
    cout << endl << menu1.selectedItem << endl;
    _getch();
    //for (int i = 0; i < 10; i++) {
    //    std::cout << "Pasha Lavrov Muzhik!\a\n";
    //    Sleep(1000);
    //    Beep(1000, 1000);
    //    system("cls");
    //}
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
