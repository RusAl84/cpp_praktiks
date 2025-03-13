#pragma once
#include <stdio.h>
#include <string>

using namespace std;

class StringWorker
{
private:
	string str;
public:
	//����� ������ ��������� ����������� �� ���������, 
	StringWorker() = default;
	// ����������� � ����������, 
	StringWorker(const string& str)
		: str(str)
	{
	}
	// ����������� �����������, 
	// https://metanit.com/cpp/tutorial/5.17.php?ysclid=m75yug6sg0141565775
	StringWorker(const StringWorker& _other)
	{
		str = _other.str;
	}
	// ������������� �������� ������������, 
	bool operator==(const StringWorker& _other) const
	{
		return str == _other.str;
	}
	// ������������� �������� ������ ����������� ������� � �����.
};

