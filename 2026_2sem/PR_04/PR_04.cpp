#include <iostream>
#include <windows.h>
#include <string>
#include <stdio.h>
#include <fstream>
#include "initial_data.h"
#include "StudentsList.h"




struct Student* genDataStud() {
	// Генерация данных студента - стандартные значения
	struct Student* st = new Student();
	st->number = "0086"; // номер студ. билета
	st->first_name = "Русаков Алексей";	// фамилия студента
	st->birth_day = "27/12/1984";	// дата рождения студента
	st->group = "БИСО-01-25"; // номер группы
	struct Grade* gr = new Grade();
	//struct Grade gr;
	gr->date = "14/04/2026";
	gr->mark = 5;
	gr->subject = "Языки программирования 2";
	st->results.push_back(*gr);
	gr->date = "15/04/2026";
	gr->mark = 5;
	gr->subject = "Иностранный язык 2";
	st->results.push_back(*gr);
	gr->date = "16/04/2026";
	gr->mark = 5;
	gr->subject = "Физика 2";
	st->results.push_back(*gr);
	gr->date = "17/04/2026";
	gr->mark = 3;
	gr->subject = "История";
	st->results.push_back(*gr);
	gr->date = "19/04/2026";
	gr->mark = 5;
	gr->subject = "Навыки игры в MineCraft";
	st->results.push_back(*gr);
	delete gr;
	//cout << st->results[0].subject << endl;
	//cout << st->results[1].subject << endl;
	//cout << st->results[2].subject << endl;
	//cout << st->results[3].subject << endl;
	//cout << st->results[4].subject << endl;
	return st;
}

void genDefaultDataFile(StudentsList* sl) {
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
}

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout << "Практическая работа 4" << endl;
    auto author = []()
        {
            cout << "Русаков Алексей БИСО-01-25" << endl;
        };
    author();

    StudentsList* sl = new StudentsList();
    //genDefaultDataFile(sl);
    //sl->printMyList();
    //sl->saveData();
    sl->loadData();
    sl->Dislay();
    sl->calcAvgMark();

	sl->loadData();
	//sl->Dislay();
	//sl->calcAvgMark();


	//Вариант 8
	//Операции со списком :
	// добавление узла в конец списка;
	struct Student* st = genDataStud();
	st->number = "0001";
	st->first_name = "Русаков конец";
	sl->addItemBack(st);
	sl->Dislay();
	//// удаление N узлов, начиная с указанного индекса.
	sl->deleteItemAfterInd(6); //6 4 
	cout << endl << "удаление N узлов, начиная с указанного индекса." << endl;
	sl->Dislay();

	sl->calcVar8();


	//Вариант 26
	//	Операции со списком :
	// добавление узла в конец списка;

	st = genDataStud();
	st->number = "0777";
	st->first_name = "Русаков конец списка";
	sl->addItemBack(st);
	sl->Dislay();
	// удаление N узлов с начала списка.
	sl->deleteItemBeforeInd(2);
	cout << endl << "удаление N узлов, начиная с указанного индекса." << endl;
	sl->Dislay();
	sl->calcVar26();


}
