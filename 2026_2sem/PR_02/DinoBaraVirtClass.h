#pragma once
#include <iostream>
#include <windows.h>
#include <stdio.h>

using namespace std;

class DinoBaraVirtClass
{
protected:
	int* data;
	int size;
public:
	//virtual void calculate() {};

	DinoBaraVirtClass() {
		size = 17;
		data = new int[size+1];
		srand(time(nullptr));
		for (int i = 0; i <= size; i++) {
			data[i] = rand() % 201 - 100;
		}
	};
	DinoBaraVirtClass(int _size) {
		if (_size>0) {
			data = new int[_size+1];
			srand(time(nullptr));
			for (int i = 0; i <= _size; i++) {
				data[i] = rand() % 201 - 100;
			}
			size = _size;
		}
		//else {
		//	printf("ERROR\n");
		//}
	};
	~DinoBaraVirtClass() {
		delete[] data;
	};
	void display() {
		cout << endl << "Display: ";
		for (int i = 0; i < size; i++) {
			cout<< " " << data[i];
		}
		cout << endl;
	}
	void Author() {
		cout << "\nРусаков Алексей Михайлович, БИСО-01-25, Вариант 8\n" ;
	}
	DinoBaraVirtClass(const DinoBaraVirtClass& other) {
		cout << "DinoBaraVirtClass(const DinoBaraVirtClass & other) "<< endl;
		size = other.size;
		data = new int[size+1];
		for (int i = 0; i <= size; i++) {
			data[i] = other.data[i];
		}
		printf("\n");
	}
	DinoBaraVirtClass& operator=(const DinoBaraVirtClass& other) {
		cout << "operator= " << endl;
		if (this != &other) {
			delete[] data;
			size = other.size;
			data = new int[size+1];
			for (int i = 0; i <= size; i++) {
				data[i] = other.data[i];
			}
		}
		return *this;
	}
	virtual void calculate() {  };
};

class A: public DinoBaraVirtClass
{
public:
	//Вариант 18
	void calculate() override {
		cout << endl << "  Variant 18";
		// номер и значение минимального по модулю элемента массива;
		int min = abs(data[0]);
		int index = 0;
		for (int i = 0; i <= size; i++)
			if (abs(data[i]) < min){
				min = abs(data[i]);
				index = i;
			}
		cout << endl << "Index = " << index;
		cout << endl << "Znachenie = " << min;
	};
};

class B : public DinoBaraVirtClass
{
public:
	//Вариант 23
	void calculate() override {
		cout << endl << "  Variant 23";
		// сумму положительных элементов массива, расположенных до минимального элемента;
		int min = data[0];
		int index = 0;
		for (int i = 0; i <= size; i++)
			if (data[i] < min) {
				min = abs(data[i]);
				index = i;
			}
		cout << endl << "Index = " << index;
		cout << endl << "Znachenie = " << min;
		int positeveSum = 0;
		for (int i = 0; i < index; i++)
			if (data[i] << min > 0)
				positeveSum += data[i];
		cout << endl << "positeveSum = " << positeveSum;
	};
};

class C : public DinoBaraVirtClass
{
public:
	//Вариант 24
	void calculate() override {
		cout << endl << "  Variant 24";
		// преобразовать массив таким образом, чтобы сначала располагались 
		// все нулевые элементы, потом все положительные, 
		// а потом – все отрицательные.
		int countZero=0;
		int *positiveData = new int[size + 1];
		int positiveIndex = 0;
		int *negativeData = new int[size + 1];
		int negativeIndex = 0;
		for (int i = 0; i <= size; i++) {
			if (data[i] == 0)
				countZero++;
			if (data[i] > 0) {
				positiveData[positiveIndex] = data[i];
				positiveIndex++;
			}
			if (data[i] < 0) {
				negativeData[negativeIndex] = data[i];
				negativeIndex++;
			}
		}
		for (int i = 0; i < countZero; i++)
			data[i] = 0;
		for (int i = 0; i < positiveIndex; i++)
			data[countZero+ i] = positiveData[i];
		for (int i = 0; i < negativeIndex; i++)
			data[countZero + positiveIndex +i] = negativeData[i];
	};
};
