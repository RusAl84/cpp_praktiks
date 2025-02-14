#include "test_class.h"
#include <iostream>
#include <windows.h>
#include <stdio.h>
using namespace std;

// как разделить на файлы h и  cpp 
//https://learn.microsoft.com/ru-ru/cpp/cpp/header-files-cpp?view=msvc-170


test_class::test_class(int _size) {
	
	size = _size;
	//https://metanit.com/c/tutorial/5.8.php?ysclid=m74p5x44gj873066344
	// динамическая память malloc
	numbers = (int*)malloc(sizeof(int) * size);
	// о динамических массивах
	//https://metanit.com/cpp/tutorial/4.12.php?ysclid=m74m9xetn726609234
	// используется для объектво New
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

void test_class::display() {
	cout << endl;
	for (int i = 0; i < size; i++) {
		cout << " " << numbers[i];
	}
}