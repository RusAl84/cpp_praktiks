#pragma once
#include "EzhStandart.h"
class EzhBattle :
    public EzhStandart
{
private:
    string weapon;
    int damage;
    int health;
public:
    int atack(int d) {
        health -= d;
        cout << "Идёт атака на ёжика: " << this->getName() << "Осталось здоровья: " << health;
        return health;

    }
    void display() {
        cout << "";
    }
    EzhBattle() {
        weapon = "Иголки";
        damage = 1;
        health = 10;
    }
};

