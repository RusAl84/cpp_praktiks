#pragma once
#include "EzhStandart.h"
#include <windows.h> 
class EzhBattle :
    public EzhStandart
{
private:
    string weapon;
    int damage;
    int health;
public:
    int atack(int d) {
        if (health>0){
           health -= d;
           cout << "Идёт атака на ёжика: " << this->getName() << " Осталось здоровья: " << health <<endl;
        }
        else
        {
            cout << "Ёжик: " << this->getName() << " GameOver" << endl;
            Beep(1000, 3000);
        }
        return health;

    }
    int getDamage() {
        return damage;
    }
    void display() {
        cout << "";
    }
    EzhBattle() {
        weapon = "Базука";
        damage = 15;
        health = 145;
    }
};

