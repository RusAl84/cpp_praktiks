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
        cout << "������� ���������� ��� ������: " << endl;
        bool isContinue = true;
        while (isContinue){
            cin >> x;
            cin >> y;
            isContinue = false;
            if ((x >= this->lx) or (x < 0)) {
                cout << "���������� x = "<<x<<" ������� �� �����: " << endl;
                cout << "��������� ����" << endl;
                isContinue = true;
            }
            if ((y >= this->ly) or (y < 0)) {
                cout << "���������� y = " << y << " ������� �� �����: " << endl;
                cout << "��������� ����"<< endl;
                isContinue = true;
            }
        }

    }
};

