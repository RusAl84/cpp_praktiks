// test_vector2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    struct student {
        string name;
        float weight;
        string drink;
    };

    student *stepa = new student();
    student *nikita = new student();
    student *lenochka = new student();
    
    stepa->name = "Спепка заводной";
    stepa->drink = "Абсент";
    stepa->weight = 0.33;
    nikita->name = "Никита глаза на затылке";
    nikita->drink = "Henessy XO";
    nikita->weight = 0.7;
    lenochka->name = "Леночка - наше солнышко;)";
    lenochka->drink = "Martini Biyanco";
    lenochka->weight = 0.3 ;

    vector <student> tripDachaMihalicha;

    tripDachaMihalicha.push_back(*stepa);
    tripDachaMihalicha.push_back(*nikita);
    tripDachaMihalicha.push_back(*lenochka);

    cout << tripDachaMihalicha.size();

    for (auto i : tripDachaMihalicha){
        cout << endl << i.weight;
        //cout << endl << i;
    }



    float all_weight = 0;
    for (int i = 0; i < tripDachaMihalicha.size(); i++) {
        all_weight += tripDachaMihalicha[i].weight;
    }
    cout << endl <<all_weight;
}
