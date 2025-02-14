#pragma once
#include "windows.h"
#include <iostream>
#include <string>
#include <conio.h>
#include <stdio.h>

using namespace std;
class ClassEdit
{
private:
	string data;
	string label;
public:

	ClassEdit() {};

	static void drawLineUP(int size) {
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		string tmpString = " ";
		for (int i = 0; i < size; i++)
			tmpString += "_";
		SetConsoleTextAttribute(hConsole, 15);
		cout << tmpString << endl;
	}

	static void drawLineDown(int size) {
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		string tmpString = "|";
		for (int i = 0; i < size - 1; i++)
			tmpString += "_";
		SetConsoleTextAttribute(hConsole, 15);
		tmpString += "|";
		cout << tmpString << endl;
	}

	void setLabel(string inString) {
		label = inString;
	}
	void draw() {
		system("cls");
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		int maxLength = label.length();
		drawLineUP(maxLength + 6);
		SetConsoleTextAttribute(hConsole, 15);
		string tmpString = "";
		tmpString = "|   ";
		tmpString = tmpString + label.c_str();
		while (tmpString.length() < maxLength + 7)
			tmpString += " ";
		tmpString += "|";
		cout << tmpString << endl;
		drawLineDown(maxLength + 7);
	}

	string setDataString(string dataString) {

		label = label + " Предыдущее значение: " + dataString;
		draw();
		data = dataString;
		cout << data;
		char ch = 0;
		while (ch != 13) { //13 - код enter чтобы ввести значения
			ch = _getch();
			if (ch == 8) {  // Backspace удалить символ
				string tmpString = "";
				tmpString = data;
				data = "";
				if (tmpString.length() > 0) {
					for (int i = 0; i < tmpString.length() - 1; i++)
						data = data + tmpString[i];
					draw();
					cout << data;
				}
				continue;
			}
			if (isDigit(ch) or isAlpha(ch) or isSpace(ch) or isSpec(ch)) {
				cout << ch;
				data = data + ch;
			}
		}
		//data = inString;
		return data;
	}
	bool isDigit(char ch) {
		if (ch >= 48 and ch <= 57)
			return true;
		else
			return false;

	}
	bool isAlpha(int ch) {
		if (ch >= 65 and ch <= 90)
			return true;
		if (ch >= 97 and ch <= 122)
			return true;
		if (ch >= -200 and ch <= -1)
			return true;
		return false;
	}
	bool isSpace(char ch) {
		if (ch == 32)
			return true;
		else
			return false;
	}
	bool isSpec(char ch) {
		if (ch >= 33 and ch <= 47)
			return true;
		else
			return false;
	}



	int setDataInt(int startRange, int endRange, int dataInt) {
		label = label + " Предыдущее значение: " + to_string(dataInt);
		draw();
		string inString = "";
		while (inString.length() == 0) {
			cin >> inString;
			if (not isDigit(inString)) {
				inString = "";
				cout << "Ошибка: Ожидалось число.";
				_getch();
				continue;
			}
			int tmpInt = atoi(inString.c_str());
			if ((tmpInt < startRange) or (tmpInt > endRange)) {
				inString = "";
				cout << "Ошибка: выход из заданного диапозона";
				_getch();
				continue;
			}
		}
		data = inString;
		return atoi(data.c_str());
	}

	bool isDigit(string inString) {
		bool flag = true;
		for (int i = 0; i < inString.length(); i++)
		{
			if (not isdigit(inString[i]))
				flag = false;
		}
		return flag;
	}

};

