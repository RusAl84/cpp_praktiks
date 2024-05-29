#pragma once
#include "windows.h"
#include <iostream>
#include <string.h>
#include <conio.h>
#include <stdio.h>
#include "ClassEdit.h"

using namespace std;

class ClassMenu
{
private:
    int itemsCount;
    int titleItemCount;
    int selectedItem;
    string items[300][50]; 
    string TitelStrings[50][60];

    void draw() {
        Sleep(10);
        system("cls");
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        int maxLength = getMaxLength();
        ClassEdit::drawLineUP(maxLength + 6);
        for (int i = 0; i < titleItemCount; i++) {
            SetConsoleTextAttribute(hConsole, 15);
            string tmpString = "";
            tmpString = "|   ";
            tmpString = tmpString + TitelStrings[i]->c_str();
            while (tmpString.length() < maxLength + 7)
                tmpString += " ";
            tmpString += "|";
            cout << tmpString << endl;
        }
        ClassEdit::drawLineDown(maxLength + 7);
        for (int i = 0; i < itemsCount; i++) {
            if (i == selectedItem) {

                SetConsoleTextAttribute(hConsole, 15);
                cout << "|";
                SetConsoleTextAttribute(hConsole, 13);
                cout << " * " << items[i]->c_str();
                SetConsoleTextAttribute(hConsole, 15);
                string tmpString = "";
                while (tmpString.length() < maxLength - items[i]->length() + 3)
                    tmpString += " ";
                tmpString += "|";
                cout << tmpString << endl;
            }
            else {
                SetConsoleTextAttribute(hConsole, 15);
                string tmpString = "";
                tmpString = "|   ";
                tmpString = tmpString + items[i]->c_str();
                while (tmpString.length() < maxLength + 7)
                    tmpString += " ";
                tmpString += "|";
                cout << tmpString << endl;
            }
        }
        ClassEdit::drawLineDown(maxLength + 7);
        //cout << getMaxLength() <<  endl;
    }

    int getMaxLength() {
        int maxLength = 0;
        for (int i = 0; i < 300; i++)
            if (items[i]->length() > maxLength)
                maxLength = items[i]->length();
        for (int i = 0; i < 50; i++)
            if (TitelStrings[i]->length() > maxLength)
                maxLength = TitelStrings[i]->length();
        return maxLength;
    }


public:
    ClassMenu() {
        selectedItem = 0;
        itemsCount = 0;
        titleItemCount = 0;
    }
    int getItemsCount() {
        return itemsCount;
    }
    void eraseTitle() {
        titleItemCount = 0;
    }
    void eraseItem() {
        itemsCount = 0;
    }
    void eraseAll() {
        eraseTitle();
        eraseItem();
    }
    int getSelectedItem() {
        return selectedItem;
    }
    void addItem(string inString) {
        items[itemsCount]->assign(inString.c_str());
        itemsCount++;
    }
    void addTitleItem(string inString) {
        TitelStrings[titleItemCount]->assign(inString.c_str());
        titleItemCount++;
    }
    void setDown() {
        selectedItem++;
        if (selectedItem > itemsCount - 1)
            selectedItem = 0;
    }
    void setUp() {
        selectedItem--;
        if (selectedItem < 0)
            selectedItem = itemsCount - 1;
    }
    //где <A> и <B> Ч шестнадцатеричные цифры Ч перва€ задает цвет фона, а втора€ Ч цвет переднего плана(цвет шрифта).
    //    «начени€ цифр
    //    0 Ч черный
    //    1 Ч синий
    //    2 Ч зеленый
    //    3 Ч голубой
    //    4 Ч красный
    //    5 Ч лиловый
    //    6 Ч желтый
    //    7 Ч белый
    //    8 Ч серый
    //    9 Ч свело - синий
    //    A Ч светло - зеленый
    //    B Ч светло - голубой
    //    — Ч светло - красный
    //    E Ч светло - желтый
    //    F Ч €рко - белый
    //system("Color 15");

    void run() {
        char ch = ' ';
        draw();
        while (ch != 13) {
            Sleep(10);
            ch = _getch();
            //cout << endl << ch <<endl;
            if (ch == 80) {// вниз
                setDown();
                draw();
            }
            if (ch == 72) {
                setUp();
                draw();
            }
        }
    }
};