#pragma once
using namespace std;
class test_class
{
public:
	test_class(int size);
	~test_class();
	void setElement(int ind, int x);
	int getElement(int ind);
	void display();
private:
	//1. ������ ������������ ������ ������ ������ 
	//  ���������� �����������
	//	�������� ������� ������������� �������
	int size; // ������ ������������� �������
	int *numbers; // ��������� �� ������������ ������
	

};

