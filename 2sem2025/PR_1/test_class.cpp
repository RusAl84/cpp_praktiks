#include "test_class.h"
#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <ctime>
using namespace std;

// ������� ���������� ������ ��������� � ���� ��������� ������ :
// ����������� ������ � � ������������ �����(���������� "h"), 
// ������� ����������� ������������ ������� � ������������� 
// ������� � � ����� � ����������� �����(���������� "cpp").
// ��� ��������� �� ����� h �  cpp 
//https://learn.microsoft.com/ru-ru/cpp/cpp/header-files-cpp?view=msvc-170




int gen_num() {
	// �������� ��������� ����� https://codelessons.dev/ru/rand-in-cplusplus/
	int start = 0;
	int end = 100;
	int num = rand() % (end - start + 1) + start;
	start = 0;
	end = 1;
	int x = rand() % (end - start + 1) + start;
	if (x == 0)
		num *= -1;
	return num;
};

test_class::test_class(int _size) {
	size = _size;
	// ������������ ������ malloc
	//https://metanit.com/c/tutorial/5.8.php?ysclid=m74p5x44gj873066344
	// � ������������ ��������
	//https://metanit.com/cpp/tutorial/4.12.php?ysclid=m74m9xetn726609234
	// !!!!!!!!!!!��� �������� ����� ������������ New
	numbers = (int*)malloc(sizeof(int) * size);
	//3. � ������������ ��������� ���������� ������������� ������� ������ - ����������
	// ���������� � ��������� �� �100 �� 100.
	for (int i = 0; i < size; i++) {
		numbers[i] = gen_num();
	}
}

test_class::~test_class()
{
	free(numbers);
};

void test_class:: setElement(int ind, int x) {
	numbers[ind] = x;
}

int test_class:: getElement(int ind) {
	return numbers[ind];
}

int test_class::getSize()
{
	return size;
}

void test_class::display() {
	//������������ ������� ��� ������ �� ����� ����������� �������;
	cout << endl;
	for (int i = 0; i < size; i++) {
		cout << " " << numbers[i];
	}
}

void test_class::author()
{
	//������������ ������� ��� ������ �� ����� ��������� �� ������ ���������;
	cout << "\n ����� ������� �������" ;
}
