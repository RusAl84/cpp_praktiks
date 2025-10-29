#include "test_class.h"
#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <ctime>
using namespace std;
int gen_num() {
	// создание случайных чисел https://codelessons.dev/ru/rand-in-cplusplus/
	int start = 0;
	int end = 100;
	int num = rand() % (end - start + 1) + start;  // 0..100
	start = 0;
	end = 1;
	int x = rand() % (end - start + 1) + start; // знак для -100..100
	if (x == 0)
		num *= -1;   // -1 или +1
	return num;
};
test_class::test_class(int _size) {
	size = _size;
	// динамическая память malloc
	// Можете использовать вектор
	// Михалыч захотел олдскулл маллок;)
	//https://metanit.com/c/tutorial/5.8.php?ysclid=m74p5x44gj873066344
	// о динамических массивах
	//https://metanit.com/cpp/tutorial/4.12.php?ysclid=m74m9xetn726609234
	// !!!!!!!!!!!Для объектов нужно пользоваться New
	numbers = (int*)malloc(sizeof(int) * size);
	//3. В конструкторе выполнить заполнение компонентного массива псевдо - случайными
	// значениями в диапазоне от –100 до 100.
	for (int i = 0; i < size; i++) {
		numbers[i] = gen_num();
	}
}

// конструктор копирования
// https://metanit.com/cpp/tutorial/5.17.php?ysclid=m75yug6sg0141565775
test_class::test_class(const test_class& _other)
{
	size = _other.size;
	for (int i = 0; i < size; i++)
		numbers[i] = _other.numbers[i];
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
	//компонентную функцию для вывода на экран содержимого объекта;
	cout << endl;
	for (int i = 0; i < size; i++) {
		cout << " " << numbers[i];
	}
}

void test_class::author()
{
	//компонентную функцию для вывода на экран сообщения об авторе программы;
	cout << endl << "Автор Русаков Алексей" ;
}


bool test_class::operator==(const test_class& _other) const
{
	if (_other.size == size) {
		for (int i = 0; i < size; i++) {
			if (numbers[i]!=_other.numbers[i])
				return false;
		}
		return true;
	}
	else
		return false;
}

int getMax(int* numbers, int size) {
	int res = -101;
	for (int i = 0; i < size; i++) {
		if (numbers[i] >= res) {
			res = numbers[i];
		}
	}
	return res;
}

int getMin(int* numbers, int size) {
	int res = 101;
	for (int i = 0; i < size; i++) {
		if (numbers[i] <= res) {
			res = numbers[i];
		}
	}
	return res;
}

bool test_class::operator < (const test_class& _other)
{
	//Сравнение по сумме максимального и минимального 
	// элементов компонентных массивов
	int currentMas = getMax(numbers, size) + getMin(numbers, size);
	int otherMas = getMax(_other.numbers, size) + getMin(_other.numbers, size);
	cout << endl << "currentMas = " << currentMas << " otherMas = " << otherMas;
	return currentMas < otherMas;
}



