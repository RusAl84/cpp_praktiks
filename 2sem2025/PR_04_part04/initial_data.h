#pragma once
#include <vector> 
#include <string> 
#include <iostream>
using namespace std;

struct Grade // ��������� "������������"
{
	string subject;		// ������� ����������
	string date;		// ������
	int mark;			// ���� ��������� ������ 
};
	
struct Student // ��������� "�������"
{
	string number;			// ����� ����. ������
	string first_name;		// ������� ��������
	string birth_day;		// ���� �������� ��������
	string group;			// ����� ������
	vector<Grade> results;	// ���������� ������������
	float avg_mark;         // ������� ���� �� �������
};

struct Node // ��������� "���� ������"
{
	Student item;	// ������ ���� 
	int index;		// ������ ����
	Node* next;		// ��������� �� ��������� ���� ������
};

struct indexStud // ��������� ������� ���������
{
	int numStud;
	int countGrade;
};

//
//class List	// ����� "�������� ����������� ������
//{
//	Node* first;	// ��������� �� ������ ���� ������
//	Node* last;	// ��������� �� ��������� ���� ������
//public:
//	List();	// �������� ������������
//	// ������ � �������, ����������� ����������� ����� �������
//};
//
//   