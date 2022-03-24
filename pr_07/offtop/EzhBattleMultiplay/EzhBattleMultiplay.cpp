// EzhBattleMultiplay.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "EzhStandart.h"
#include "EzhBattle.h"
int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "EzhBattleMultiplay!\n";
    //EzhStandart* ezh1 = new EzhStandart();
    //cout << ezh1->getName();
    EzhBattle* rusakov = new EzhBattle();
    EzhBattle* mersov = new EzhBattle();
    for (int i = 0; i < 12; i++) {
        mersov->atack(rusakov->getDamage());
        Sleep(500);
        Beep(4000, 100);
    }

    
}

