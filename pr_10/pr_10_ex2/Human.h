#pragma once
#include <string>
#include <iostream>
using namespace std;
class Human
{
public:
    // поле класса
    std::string known_phrase;

    // конструктор класса
    Human(std::string phrase) {
        known_phrase = phrase;
    }

    // конструктор поумолчанию
    Human() {
        known_phrase = "";
    }

    // метод класса
    void saySomething() {
        std::cout << known_phrase;
    }

    // деструктор класса
    ~Human() {
        std::cout << "Bye world";
    }
};

