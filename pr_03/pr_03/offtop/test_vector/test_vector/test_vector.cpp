#include <iostream>
#include <vector>
#include <string>

using namespace std;
int main()
{
    struct student {
        string name;
        float drink;
    };
    vector <student> bandaMihalicha;
    student *kostya = new student();
    kostya->name = "Костя с шарфиком";
    kostya->drink = 0.6;

    student* dima = new student();
    dima->name = "Дима SAI";
    dima->drink = 0.8;

    bandaMihalicha.push_back(*kostya);
    bandaMihalicha.push_back(*dima);


    cout << bandaMihalicha.size();
}

