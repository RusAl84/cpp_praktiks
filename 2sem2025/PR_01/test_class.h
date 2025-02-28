#pragma once
using namespace std;

// «адание –еализацию класса выполнить в двух отдельных файлах :
// определение класса Ц в заголовочном файле(расширение "h"), 
// внешнее определение компонентных функций и дружественные 
// функции Ц в файле с исполн€емым кодом(расширение "cpp").
// как разделить на файлы h и  cpp 
//https://learn.microsoft.com/ru-ru/cpp/cpp/header-files-cpp?view=msvc-170


class test_class
{
public:
	//2.  ласс должен содержать конструктор по умолчанию, конструктор с па - 
	// раметром(параметр конструктора Ц количество элементов компонентного массива), 
	// конструктор копировани€. роме того в состав компонентных функций класса должен 
	// входить деструктор.
	test_class() = default; //конструктор по умолчанию
	test_class(int size);   
	// конструктор копировани€  
	// https://metanit.com/cpp/tutorial/5.17.php?ysclid=m75yug6sg0141565775
	test_class(const test_class& t);  
	~test_class();  


	void setElement(int ind, int x);
	int getElement(int ind);
	int getSize();
	void display();
	void author();
	// https://metanit.com/cpp/tutorial/5.14.php?ysclid=m761vuw5f9931647360
	bool operator==(const test_class& _other) const;
	bool operator < (const test_class& _other);
	friend bool operator-- ();
private:
	//1. ‘ормат компонентных данных класса должен обеспечить 
	// возможность создани€ объекта произвольного размера
	// (т.е.моделировать динамиче - ский массив).
	//  омпонентные данные класса должны быть размещены в 
	// закрытой части класса.
	int size; // размер динамического массива
	int *numbers; // указатель на динамический массив
	
};

