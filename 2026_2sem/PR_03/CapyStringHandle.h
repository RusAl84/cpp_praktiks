#pragma once
#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <ctype.h>

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
		cout << endl << "Количество слов в массиве: " << words.size();
	}
	void WriteToFile(const char* filename) {
		FILE* file;
		errno_t err;
		err	= fopen_s(&file,filename, "w");
		if (file != nullptr) {
			fprintf(file, "Ishodnaya stroka: %s\n", originalString.c_str());
			fprintf(file, "Massiv slov:\n");
			for (const auto& word : words) {
				fprintf(file, "%s\n", word.c_str());
			}
			fclose(file);
		}
		else {
			printf("\nERROR: Не удалось открыть файл %s для записи\n", filename);
		}
	}
	// Вариант 3: Выделить из исходной строки самое короткое и самое длинное слова
	void var3() {
		printf("\n=== Variant 3 ===\n");
		if (words.empty()) {
			printf("Masiv slov pust!\n");
			return;
		}
		string shortestWord = words[0];
		string longestWord = words[0];
		for (const auto& word : words) {
			if (word.length() < shortestWord.length()) {
				shortestWord = word;
			}
			if (word.length() > longestWord.length()) {
				longestWord = word;
			}
		}
		printf("Samoe korotkoe slovo: \"%s\" (dlina: %lu simvolov)\n",
			shortestWord.c_str(), shortestWord.length());
		printf("Samoe korotkoe slovo: \"%s\" (dlina: %lu simvolov)\n",
			longestWord.c_str(), longestWord.length());
	}
	// Вариант 18: Разработать метод, который выделяет слова, 
	// в которых встречается введенная с клавиатуры подстрока 
	// и подсчитывает их количество.
	void var18() {
		printf("\n=== Variant 18 ===\n");
		if (words.empty()) {
			printf("Masiv slov pust!\n");
			return;
		}
		printf("Ishodnaya stroka: %s\n", originalString.c_str());
		string subStr = "end";
		printf("subStr: %s\n", subStr.c_str());
		vector<string> filterWords;
		int count = 0;
		for (const auto& word : words) {
			//cout << word.find(subStr) << std::endl;
			if (word.find(subStr)<std::string::npos) {
				filterWords.push_back(word);
				count++;
			}
		}
		printf("Naydennie slova: ") ;
		for (const auto& word : filterWords) {
			printf("%s ", word.c_str());
		}
		printf("\n Kolichestvo: %d", count);
	}
	// Вариант 24: Разработать метод, 
	// выделяющий из исходной строки слова,
	// заканчивающиеся символом цифры.
	void var24() {
		printf("\n=== Variant 24 ===\n");
		if (words.empty()) {
			printf("Masiv slov pust!\n");
			return;
		}
		printf("Ishodnaya stroka: %s\n", originalString.c_str());
		string subStr = "end";
		printf("subStr: %s\n", subStr.c_str());
		vector<string> filterWords;
		int count = 0;
		for (const auto& word : words) {
			char ch = word[word.length() - 1];
			if (isdigit(ch)) {
				filterWords.push_back(word);
				count++;
			}
		}
		printf("Naydennie slova: ");
		for (const auto& word : filterWords) {
			printf("%s ", word.c_str());
		}
		printf("\n Kolichestvo: %d", count);
	}
};

