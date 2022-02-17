// KillComp.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <windows.h>


using namespace std;

int main()
{
    cout << "Kill Comp!\n";
    for (int i = 0; i < 40; i++) {
        Beep(1000+i*100, 700-10*i);
    }
    Beep(3000, 10000);

}


