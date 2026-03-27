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
		words.clear();
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
		cout << endl << "originalString: " << originalString.c_str();
	}
	// 
	void ReadFromFile(const char* filename) {
		ifstream inFile(filename);
		if (inFile.is_open()) {
			getline(inFile, originalString);
			inFile.close();
		}
		else {
			cout << endl << "ERROR: Не удалось открыть файл " << filename;
		}
	}

	void extractWords() {
		// istringstream — это класс входных потоков в языке программирования C++.
		// https://www.geeksforgeeks.org/cpp/vector-of-strings-in-cpp/
		istringstream iss(originalString);
		string word;
		words.clear();
		while (iss >> word) {
			words.push_back(word);
		}
	}
	void wordsCount() {
		cout<< endl<< "Количество слов в массиве: " << words.size();
	}

};

