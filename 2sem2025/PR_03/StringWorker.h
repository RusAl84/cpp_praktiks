#pragma once
#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

class StringWorker
{
//private:
	
public:
	string str;
	// ласс должен содержать конструктор по умолчанию, 
	StringWorker();
	// конструктор с параметром, 
	StringWorker(const string&);
	// конструктор копировани€, 
	// https://metanit.com/cpp/tutorial/5.17.php?ysclid=m75yug6sg0141565775
	StringWorker(const StringWorker& _other);
	// перегруженную операцию присваивани€, 
	bool operator==(const StringWorker&) const;
	string getStr();
	// перегруженную операцию вывода содержимого объекта в поток.
	friend ostream& operator<<(ostream&, const StringWorker&);
	// чтение исходной строки из текстового файла, им€ которого передаетс€
	// из командной строки.ƒл€ создани€ файла нужно воспользоватьс€ 
	// стандартными средствами операционной системы(например, программой Notepad);
	void loadFile(const string&);
	// –азработать метод, который позвол€ет упор€дочить слова исходной строки
	// по возрастанию их длины. ¬ывести на экран и в результирующий файл 
	// строку, состо€щую из слов в упор€доченном виде.
	vector<string> sortedWords_var8();
	vector<string> hex_var12();
	void writeResultsToFile(const string&, vector<string>); // запись результатов в файл
};

