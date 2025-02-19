#pragma once
using namespace std;
class test_class
{
public:
	//2. Класс должен содержать конструктор по умолчанию, конструктор с па - 
	// раметром(параметр конструктора – количество элементов компонентного массива), 
	// конструктор копирования.Кроме того в состав компонентных функций класса должен 
	// входить деструктор.
	test_class(int size);
	test_class(const test_class& t);
	~test_class();
	// конструктор копирования
	// https://metanit.com/cpp/tutorial/5.17.php?ysclid=m75yug6sg0141565775

	void setElement(int ind, int x);
	int getElement(int ind);
	int getSize();
	void display();
	void author();
	// https://metanit.com/cpp/tutorial/5.14.php?ysclid=m761vuw5f9931647360
	bool operator==(const test_class& other) const;
	int operator < (const test_class& other) const;

private:
	//1. Формат компонентных данных класса должен обеспечить 
	// возможность создания объекта произвольного размера
	// (т.е.моделировать динамиче - ский массив).
	// Компонентные данные класса должны быть размещены в 
	// закрытой части класса.
	int size; // размер динамического массива
	int *numbers; // указатель на динамический массив
	
};

