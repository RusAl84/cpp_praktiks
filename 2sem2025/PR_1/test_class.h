#pragma once
class test_class
{


public:
	test_class(int size) {
		int* numbers1{ new int[size] {} };
	};


private:
	//1. Формат компонентных данных класса должен 
	//  обеспечить возможность
	//	создания объекта произвольного размера

	int size; // размер динамического массива
	int* numbers1{ new int[size] {} };
};

