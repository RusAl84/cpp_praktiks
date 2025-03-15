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
	//����� ������ ��������� ����������� �� ���������, 
	StringWorker();
	// ����������� � ����������, 
	StringWorker(const string&);
	// ����������� �����������, 
	// https://metanit.com/cpp/tutorial/5.17.php?ysclid=m75yug6sg0141565775
	StringWorker(const StringWorker& _other);
	// ������������� �������� ������������, 
	bool operator==(const StringWorker&) const;
	string getStr();
	// ������������� �������� ������ ����������� ������� � �����.
	friend ostream& operator<<(ostream&, const StringWorker&);
	// ������ �������� ������ �� ���������� �����, ��� �������� ����������
	// �� ��������� ������.��� �������� ����� ����� ��������������� 
	// ������������ ���������� ������������ �������(��������, ���������� Notepad);
	void loadFile(const string&);
	// ����������� �����, ������� ��������� ����������� ����� �������� ������
	// �� ����������� �� �����. ������� �� ����� � � �������������� ���� 
	// ������, ��������� �� ���� � ������������� ����.
	vector<string> sortedWords_var8();
	vector<string> sortedWords_var16();
	vector<string> hex_var12();
	vector<string> dec_var4();
	vector<string> ReverseWords_var21();
	vector<string> ExtractWords_var26();
	void writeResultsToFile(const string&, vector<string>); // ������ ����������� � ����
};

