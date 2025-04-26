#include <iostream>
#include <windows.h>
#include <stdio.h>
#include "ClassEdit.h"
#include "ClassMenu.h"
#include "vector"

using namespace std;

struct Grade // структура "успеваемость"
{
	string subject;    // учебная дисциплина
	string date;    // оценка
	int mark;      // дата получения оценки 
};

struct Student // структура "студент"
{
	string number;      // номер студ. билета
	string first_name;    // фамилия студента
	string birth_day;    // дата рождения студента
	string group;      // номер группы
	vector<Grade> results;  // результаты успеваемости
};

void editSes(vector<Grade> results) {
	ClassMenu* sesMenu = new ClassMenu();
	int resultSelectedItem = 1;
	const int exitItem = 2;
	int capacity = 0;
	sesMenu->addTitleItem("Добавление/изменение данных о студенте: ");
	sesMenu->addItem(" Добавить новый элемент");
	sesMenu->addItem(" Назад ");
	for (auto i : results)
		sesMenu->addItem(" Предмет:" + i.subject + " дата: " + i.date + " оценка: " + to_string(i.mark));
	while (resultSelectedItem != exitItem) {
		sesMenu->run();
		resultSelectedItem = sesMenu->getSelectedItem();
		switch (resultSelectedItem) {
		case 0:
			system("cls");
			_getch();
			break;
		case 1:
			resultSelectedItem = exitItem;
			break;
		default:
			break;
		}
	}
};


int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout << "Практическая работа 3\n";
    auto author = []()
        {
            cout << "Русаков Алексей БИСО-02-24" << endl;
        };
    author();

	struct Student st;
	struct Grade gra;
	gra.date = "15/06/2025";
	gra.subject = "СВТ";
	gra.mark = 2;
	st.results.push_back(gra);
	st.results.push_back(gra);
	st.results.push_back(gra);
	st.birth_day = "27/12/1984";
	st.first_name = "Лев Русаков";
	st.group = "ББСО-02-24";
	st.number = "2498";

    ClassMenu* mainMenu = new ClassMenu();
    ClassEdit* ed = new ClassEdit();
	int resultSelectedItem = 1;
	const int exitItem = 5;
	int capacity=0;
	mainMenu->addTitleItem("Добавление/изменение данных о студенте: ");
	mainMenu->addTitleItem(" Фамилия студента: " + st.first_name);
	mainMenu->addTitleItem(" Дата рождения студента: " + st.birth_day);
	mainMenu->addTitleItem(" Номер группы: " + st.group);
	mainMenu->addTitleItem(" Номер студ.билета: " + st.number);
	mainMenu->addItem("Фамилия студента");
	mainMenu->addItem("Дата рождения студента");
	mainMenu->addItem("Номер группы");
	mainMenu->addItem("Номер студ. билета");
	mainMenu->addItem("Проставить сессию");
	mainMenu->addItem("Применить изменения");
	while (resultSelectedItem != exitItem) {
		mainMenu->run();
		resultSelectedItem = mainMenu->getSelectedItem();
		switch (resultSelectedItem) {
		case 0:
			system("cls");
			st.first_name=ed->setDataString(st.first_name);
			break;		
		case 1:
			system("cls");
			st.birth_day = ed->setDataString(st.birth_day);
			break;
		case 2:
			system("cls");
			st.group = ed->setDataString(st.group);
			break;
		case 3:
			system("cls");
			st.number = ed->setDataString(st.number);
			break;
		case 4:
			system("cls");
			editSes(st.results);
			break;
		case 5:
			resultSelectedItem = exitItem;
			break;
		default:
			break;
		}
		mainMenu->eraseTitle();
		mainMenu->addTitleItem("Добавление/изменение данных о студенте: ");
		mainMenu->addTitleItem(" Фамилия студента: " + st.first_name);
		mainMenu->addTitleItem(" Дата рождения студента: " + st.birth_day);
		mainMenu->addTitleItem(" Номер группы: " + st.group);
		mainMenu->addTitleItem(" Номер студ.билета: " + st.number);
	}
}