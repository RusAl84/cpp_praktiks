// KillComp.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <windows.h>


using namespace std;

int main()
{
    cout << "Kill Comp!\n";
    for (int i = 0; i < 16; i++) {
        Beep(1000+i*100, 400-10*i);
    }
    Beep(2600, 5000);

}


