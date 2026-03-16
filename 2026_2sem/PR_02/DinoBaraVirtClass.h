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
};

//class A:DinoBaraVirtClass
//{
//public:
//	  override   run() {};
//};
//
//class B :DinoBaraVirtClass
//{
//};
//
//class C :DinoBaraVirtClass
//{
//};