#include <vector> 
#include <string> 
#include <iostream>
using namespace std;

struct Grade // структура "успеваемость"
{
	string subject;		// учебная дисциплина
	string date;		// оценка
	int mark;			// дата получения оценки 
};
	
struct Student // структура "студент"
{
	string number;			// номер студ. билета
	string first_name;		// фамилия студента
	string birth_day;		// дата рождения студента
	string group;			// номер группы
	vector<Grade> results;	// результаты успеваемости
};

struct Node // структура "узел списка"
{
	Student item;	// данные узла 
	int index;		// индекс узла
	Node* next;		// указатель на следующий узел списка
};


class List	// класс "линейный односвязный список
{
	Node* first;	// указатель на первый узел списка
	Node* last;	// указатель на последний узел списка
public:
	List();	// прототип конструктора
	// методы и функции, реализующие вариативную часть задания
};

   