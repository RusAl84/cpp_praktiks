#pragma once
class test_class
{


public:
	test_class(int size) {
		int* numbers1{ new int[size] {} };
	};


private:
	//1. ������ ������������ ������ ������ ������ 
	//  ���������� �����������
	//	�������� ������� ������������� �������

	int size; // ������ ������������� �������
	int* numbers1{ new int[size] {} };
};

