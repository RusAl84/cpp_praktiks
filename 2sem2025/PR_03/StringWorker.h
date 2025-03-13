#pragma once
#include <stdio.h>
#include <string>

using namespace std;

class StringWorker
{
private:
	string str;
public:
	//Класс должен содержать конструктор по умолчанию, 
	StringWorker() = default;
	// конструктор с параметром, 
	StringWorker(const string& str)
		: str(str)
	{
	}
	// конструктор копирования, 
	// https://metanit.com/cpp/tutorial/5.17.php?ysclid=m75yug6sg0141565775
	StringWorker(const StringWorker& _other)
	{
		str = _other.str;
	}
	// перегруженную операцию присваивания, 
	bool operator==(const StringWorker& _other) const
	{
		return str == _other.str;
	}
	// перегруженную операцию вывода содержимого объекта в поток.
};

