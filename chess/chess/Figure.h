#pragma once
#include "ChessBoard.h"
#include <iostream>
using namespace std;

class Figure :
    public ChessBoard
{
public:
    int x, y;
    Figure() {
        cout << "Введите координаты для фигуры: " << endl;
        bool isContinue = true;
        while (isContinue){
            cin >> x;
            cin >> y;
            isContinue = false;
            if ((x >= this->lx) or (x < 0)) {
                cout << "Координата x = "<<x<<" введена не верно: " << endl;
                cout << "Повторите ввод" << endl;
                isContinue = true;
            }
            if ((y >= this->ly) or (y < 0)) {
                cout << "Координата y = " << y << " введена не верно: " << endl;
                cout << "Повторите ввод"<< endl;
                isContinue = true;
            }
        }

    }
};

