#include "test_class.h"
#include <iostream>
#include <windows.h>
#include <stdio.h>
using namespace std;

// «адание –еализацию класса выполнить в двух отдельных файлах :
// определение класса Ц в заголовочном файле(расширение "h"), 
// внешнее определение компонентных функций и дружественные 
// функции Ц в файле с исполн€емым кодом(расширение "cpp").
// как разделить на файлы h и  cpp 
//https://learn.microsoft.com/ru-ru/cpp/cpp/header-files-cpp?view=msvc-170


test_class::test_class(int _size) {
	size = _size;
	// динамическа€ пам€ть malloc
	//https://metanit.com/c/tutorial/5.8.php?ysclid=m74p5x44gj873066344
	// о динамических массивах
	//https://metanit.com/cpp/tutorial/4.12.php?ysclid=m74m9xetn726609234
	// ƒл€ объектов нужно пользоватьс€ New
	numbers = (int*)malloc(sizeof(int) * size);


	//3. ¬ конструкторе выполнить заполнение компонентного массива псевдо - случайными значени€ми в диапазоне от Ц100 до 100.
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