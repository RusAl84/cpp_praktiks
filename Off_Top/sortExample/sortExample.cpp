// sortExample.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
using namespace std;
int min(string inString[7][30]) {
    string minString = "";
    minString = inString[0]->c_str();
    int ind = 0;
    for (int i = 0; i < 7; i++) {
        //cout << "\n" << inString[i]->c_str();
        if (strcmp(inString[i]->c_str(), minString.c_str()) <=0) {
            minString = inString[i]->c_str();
            ind = i;
        }
    }
    return ind;
}
int max(string inString[7][30]) {
    string maxString = "";
    maxString = inString[0]->c_str();
    int ind = 0;
    for (int i = 0; i < 7; i++) {
        //cout << "\n" << inString[i]->c_str();
        if (strcmp(inString[i]->c_str(), maxString.c_str()) >= 0) {
            maxString = inString[i]->c_str();
            ind = i;
        }
    }
    return ind;
}


void display(string inString[7][30]) {
    //вывести массив
    for (int i = 0; i < 7; i++) {
        cout << "\n" << inString[i]->c_str();
    }
}


int main()
{
    setlocale(LC_ALL, "Russian");
    string mas[7][30];
    mas[0]->assign("Савушкин");
    mas[1]->assign("Овчиников");
    mas[2]->assign("Ватутин");
    mas[3]->assign("Лавров");
    mas[4]->assign("Паникёрович");
    mas[5]->assign("Сияющий");
    mas[6]->assign("Ушаков");
     //вывести массив
    display(mas);

    cout << "\n\n Минимальный элемент:  " << mas[min(mas)]->c_str() << "\n";
    
    //Сортировка
    string sortedMas[7][30];
    int ind = 0;
    string maxString = "";
    maxString = mas[max(mas)]->c_str();
    for (int i = 0; i < 7; i++) {
        int minInt = min(mas);
        sortedMas[i]->assign(mas[minInt]->c_str());
        mas[minInt]->assign(maxString);
    }
    display(sortedMas);



}

