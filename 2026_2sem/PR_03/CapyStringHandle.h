#pragma once
#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

class CapyStringHandle
{
private:
	string originalString;
	vector<string> words;
public:
	// Класс должен содержать конструктор по умолчанию, 
	// создающий объект с пустой строкой
	CapyStringHandle() {
		originalString = "";
	};
	// конструктор копирования
	CapyStringHandle(const CapyStringHandle& other) {
		originalString = other.originalString;
		words = other.words;
	}
	// перегруженную операцию присваивания
	CapyStringHandle& operator=(const CapyStringHandle& other) {
		if (this != &other) {
			originalString = other.originalString;
			words = other.words;
		}
		return *this;
	}
	// перегруженную операцию вывода содержимого объекта в поток
	void display() {
		cout << endl << "Исходная строка : " << originalString.c_str();
	}
	// 
	void ReadFromFile(const char* filename) {
		ifstream inFIle(filename);
		if (inFIle.is_open()) {
			getline(inFIle, originalString);
			inFIle.close();
		}
		else {
			cout << endl << "ERROR: Не удалось открыть файл " << filename;
		}
	}

};

