// SortInt.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.

#include <iostream>
using namespace std;
int mmax(int mas[7]) {
    int maxInt = 0;
    int ind = 0;
    for (int i = 0; i < 7; i++) {
        if (mas[i] >= maxInt) {
            maxInt = mas[i];
            //cout << endl << mas[i] << endl;
            ind = i;
        }
    }
    return ind;
}

int mmin(int *mas[7]) {
    int minInt = 0;
    int ind = 0;
    for (int i = 0; i < 7; i++) {
        //cout << "\n" << inString[i]->c_str();
        if (*mas[i] <= minInt) {
            minInt = *mas[i];
            ind = i;
        }
    }
    return ind;
}

void display(int mas[7]) {
    //вывести массив
    for (int i = 0; i < 7; i++) {
        cout << "\n" << mas[i];
    }
}



int main()
{
    int mas[7];
    mas[0] = 534;
    mas[1] = 124;
    mas[2] = 435;
    mas[3] = 361;
    mas[4] = 863;
    mas[5] = 123;
    mas[6] = 943;

    display(mas);
    int m = mmax(mas);
    cout << "\n\n Минимальный элемент: " << mas[m]<<"\n";
    int maxInt = mas[mmax(mas)];
    int sortedMas[7];
    for (int i = 0; i < 7; i++) {
        sortedMas[i] = mas[mmin(&mas)];
        cout << "\n" << mas[mmin(&mas)]<<"\n";
        mas[mmin(&mas)] = maxInt;
    }
    display(sortedMas);



}
