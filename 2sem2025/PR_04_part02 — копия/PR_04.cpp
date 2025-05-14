
#include <iostream>
#include <windows.h>
#include <string>
#include <stdio.h>
#include <fstream>
#include "initial_data.h"
#include "StudentsList.h"



struct Student* genDataStud() {
	// Генерация данных студента
	struct Student* st = new Student();
	st->number = "0086";			// номер студ. билета
	st->first_name = "Русаков Алексей";		// фамилия студента
	st->birth_day = "27/12/1984";		// дата рождения студента
	st->group = "БИСО-01-24";			// номер группы
	struct Grade* gr = new Grade();
	//struct Grade gr;
	gr->date = "14/05/2025";
	gr->mark = 5;
	gr->subject = "Языки программирования 2";
	st->results.push_back(*gr);
	gr->date = "15/05/2025";
	gr->mark = 5;
	gr->subject = "Иностранный язык 2";
	st->results.push_back(*gr);
	gr->date = "16/05/2025";
	gr->mark = 5;
	gr->subject = "Физику 2";
	st->results.push_back(*gr);
	gr->date = "17/05/2025";
	gr->mark = 3;
	gr->subject = "История";
	st->results.push_back(*gr);
	//cout << st->results[0].subject << endl;
	//cout << st->results[1].subject << endl;
	//cout << st->results[2].subject << endl;
	//cout << st->results[3].subject << endl;
	return st;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "Практическая работа 4\n";
	auto author = []()
		{
			cout << "Русаков Алексей БИСО-02-24" << endl;
		};
	author();

	StudentsList* sl = new StudentsList();
	struct Student* st = genDataStud();
	st->number = "0001";
	st->first_name = "Русаков Алексей 1";
	sl->addItem(st);
	st = genDataStud();
	st->number = "0002";
	st->first_name = "Русаков Алексей 2";
	sl->addItem(st);
	st = genDataStud();
	st->number = "0003";
	st->first_name = "Русаков Алексей 3";
	sl->addItem(st);
	st = genDataStud();
	st->number = "0004";
	st->first_name = "Русаков Алексей 4";
	sl->addItem(st);
	st = genDataStud();
	st->number = "0005";
	st->first_name = "Русаков Алексей 5";
	sl->addItem(st);
	sl->printMyList();
    //cout << "Hello World!\n";
<<<<<<< Updated upstream


=======
	sl->saveData();
>>>>>>> Stashed changes
}

