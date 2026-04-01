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
		cout << endl << "Kolichestvo slov v massive: " << words.size();
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
	// Вариант 2: Разработать метод, выделяющий из исходной
	// строки слова, являющиеся правильными идентификаторами языка C++.
	void var2() {
		printf("\n=== Variant 2 ===\n");
		if (words.empty()) {
			printf("Masiv slov pust!\n");
			return;
		}
		//https://learn.microsoft.com/ru-ru/cpp/cpp/identifiers-cpp?view=msvc-170
		string validChar = "_abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";	
		vector<string> validWords;
		int count = 0;
		for (const auto& word : words) {
			if (not isdigit(word[0])) {
				bool isID = true;
				for (int i=0; i< word.length();i++){
					if (validChar.find(word[i]) == std::string::npos) {
						isID = false;
						break;
					}
				}
				if (isID){
					validWords.push_back(word);
					count++;
				}
			}
		}
		printf("Naydennie slova: ");
		for (const auto& word : validWords) {
			printf("%s ", word.c_str());
		}
		printf("\n Kolichestvo: %d", count);
	}
	// Вариант 3: Выделить из исходной строки самое короткое 
	// и самое длинное слова
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
	// Вариант 4: Выделить из исходной строки слова, являющиеся целыми десятичными константами C++
	void var4() {
		vector<string> decimalConstants;

		for (const auto& word : words) {
			bool isDecimalConstant = true;
			// Проверяем, является ли слово целой десятичной константой C++
			if (word.empty()) {
				isDecimalConstant = false;
			}
			else {
				size_t start = 0;
				// Проверяем знак
				if (word[0] == '+' || word[0] == '-') {
					start = 1;
					if (word.length() == 1) {
						isDecimalConstant = false;
					}
				}
				// Проверяем каждый символ
				for (size_t i = start; i < word.length() && isDecimalConstant; i++) {
					if (!isdigit(word[i])) {
						isDecimalConstant = false;
					}
				}
				// Проверяем суффиксы типов C++ (U, u, L, l, LL, ll)
				if (isDecimalConstant && word.length() > start) {
					string numPart = word.substr(start);
					size_t numLen = numPart.length();
					// Удаляем суффиксы для проверки
					if (numLen >= 2 && (numPart.substr(numLen - 2) == "LL" || numPart.substr(numLen - 2) == "ll")) {
						numPart = numPart.substr(0, numLen - 2);
					}
					else if (numLen >= 1 && (numPart.back() == 'U' || numPart.back() == 'u' ||
						numPart.back() == 'L' || numPart.back() == 'l')) {
						numPart = numPart.substr(0, numLen - 1);
					}
					// Проверяем, что остались только цифры
					if (numPart.empty()) {
						isDecimalConstant = false;
					}
					else {
						for (char c : numPart) {
							if (!isdigit(c)) {
								isDecimalConstant = false;
								break;
							}
						}
					}
				}
			}
			if (isDecimalConstant) {
				decimalConstants.push_back(word);
			}
		}
		printf("\n=== Вариант 4 ===\n");
		if (decimalConstants.empty()) {
			printf("Целые десятичные константы C++ не найдены.\n");
		}
		else {
			printf("Найдено целых десятичных констант C++: %lu\n", decimalConstants.size());
			printf("Список констант:\n");
			for (const auto& constant : decimalConstants) {
				printf("  %s\n", constant.c_str());
			}
		}
	}

	// Вариант 5: Выделить из исходной строки слова, начинающиеся и оканчивающиеся одним и тем же символом
	void var5() {
		vector<string> matchingWords;

		for (const auto& word : words) {
			if (word.length() >= 1) {
				char firstChar = word[0];
				char lastChar = word[word.length() - 1];

				// Сравниваем символы без учета регистра
				if (tolower(firstChar) == tolower(lastChar)) {
					matchingWords.push_back(word);
				}
			}
		}

		printf("\n=== Вариант 5 ===\n");
		if (matchingWords.empty()) {
			printf("Слова, начинающиеся и оканчивающиеся одним и тем же символом, не найдены.\n");
		}
		else {
			printf("Найдено слов, начинающихся и оканчивающихся одним и тем же символом: %lu\n", matchingWords.size());
			printf("Список слов:\n");
			for (const auto& word : matchingWords) {
				printf("  %s (первый символ: '%c', последний символ: '%c')\n",
					word.c_str(), word[0], word[word.length() - 1]);
			}
		}
	}
	// 10 Разработать метод, определяющий в исходной строке 
	// самое длинное слово и выполняющий его реверс 
	// (первая буква меняется местами с последней, 
	// вторая – с предпоследней и т.д.). 
	// Результат – найденное слово с учетом реверса.
	void var10() {
		printf("\n=== Variant 10 ===\n");
		if (words.empty()) {
			printf("Masiv slov pust!\n");
			return;
		}
		string longestWord = words[0];
		for (const auto& word : words) {
			if (word.length() > longestWord.length()) {
				longestWord = word;
			}
		}
		printf("Samoe dlinnoe slovo: \"%s\" (dlina: %lu simvolov)\n",
			longestWord.c_str(), longestWord.length());
		string reversedStr;
		for (int i = longestWord.length() - 1; i >= 0; --i) {
			reversedStr += longestWord[i];
		}
		printf("reversedStr: \"%s\" ",
			reversedStr.c_str());
	}

	// Вариант 12: Разработать метод, выделяющий из исходной строки слова,
	// являющиеся положительными шестнадцатеричными константами С++.
	void var12() {
		printf("\n=== Variant 12 ===\n");
		if (words.empty()) {
			printf("Masiv slov pust!\n");
			return;
		}
		string validChar = "abcdefABCDEF1234567890";
		vector<string> validWords;
		int count = 0;
		for (const auto& word : words) {
			int startPos = 0;
			if (word[0] == '+') {
				startPos = 1;
			}
			bool isID = true;
			for (int i = startPos; i < word.length(); i++) {
				if (validChar.find(word[i]) == std::string::npos) {
					isID = false;
					break;
				}
			}
			if (isID) {
				validWords.push_back(word);
				count++;
			}
		}
		printf("Naydennie slova: ");
		for (const auto& word : validWords) {
			printf("%s ", word.c_str());
		}
		printf("\n Kolichestvo: %d", count);
	}
	// 17 Разработать метод, проверяющий имеются ли в исходной строке 
	// отдельные слова, заключенные в скобки ( ), [ ], { }. 
	// Результатом являются слова, заклю-ченные в скобки с 
	// ненарушенным балансом парности. Вложенность скобок 
	// отсутствует.
	int checkBrackets(string word, char ld, char rd) {
		
		if ((word.find(ld) < std::string::npos) or
			(word.find(rd) < std::string::npos)) {
			int numBrackets = 0;
			for (int i = 0; i < word.length(); i++) {
				if (word[i] == ld)
					numBrackets++;
				if (word[i] == rd)
					numBrackets--;
			}
			//printf("\n ---- %i \n", numBrackets);
			if (numBrackets == 0)
				return 1;  // скобки есть и сбалансированны
			else
				return -1; // скобки есть и не сбалансированны
		}
		else
			return 0; // скобок нет
	}
	void var17() {
		printf("\n=== Variant 17 ===\n");
		if (words.empty()) {
			printf("Masiv slov pust!\n");
			return;
		}
		vector<string> filteredWords;
		for (const auto& word : words) {
			int l1 = checkBrackets(word, '(', ')');
			int l2 = checkBrackets(word, '[', ']');
			int l3 = checkBrackets(word, '{', '}');
			if (((l1 >= 0) and (l2 >= 0) and (l3 >= 0)) and 
				not ((l1 == 0) and (l2 == 0) and (l3 == 0)))
				filteredWords.push_back(word);
		}
		printf("filteredWords: ");
		for (const auto& word : filteredWords) {
			printf("%s ", word.c_str());
		}
		//	shortestWord.c_str(), shortestWord.length());
		//printf("Samoe korotkoe slovo: \"%s\" (dlina: %lu simvolov)\n",
		//	longestWord.c_str(), longestWord.length());
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

	friend ostream& operator<<(ostream& out, const CapyStringHandle& sp);
};

ostream& operator<<(ostream& out, const CapyStringHandle& sp) {
	out << "Ishodnaya stroka: " << sp.originalString;
	return out;
}