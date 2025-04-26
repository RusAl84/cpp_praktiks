#include <iostream>
#include <windows.h>
#include <stdio.h>
#include "ClassEdit.h"
#include "ClassMenu.h"

using namespace std;

struct Student // структура "студент"
{
	string number;      // номер студ. билета
	string first_name;    // фамилия студента
	string birth_day;    // дата рождения студента
	string group;      // номер группы
	//vector<Grade> results;  // результаты успеваемости
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
	st.birth_day = "27/12/1984";
	st.first_name = "Лев Русаков";
	st.group = "ББСО-02-24";
	st.number = "2498";

    ClassMenu* mainMenu = new ClassMenu();
	int resultSelectedItem = 1;
	const int exitItem = 4;
	mainMenu->addTitleItem("Добавление/изменение данных о студенте: ");
	mainMenu->addTitleItem("фамилия студента: " + st.first_name);
	mainMenu->addTitleItem("дата рождения студента: " + st.birth_day);
	mainMenu->addTitleItem("номер группы: " + st.group);
	mainMenu->addTitleItem("номер студ.билета: " + st.number);
	mainMenu->addItem("номер студ. билета");
	mainMenu->addItem("фамилия студента");
	mainMenu->addItem("дата рождения студента");
	mainMenu->addItem("номер группы");
	mainMenu->addItem("выход");
	while (resultSelectedItem != exitItem) {
		mainMenu->run();
		resultSelectedItem = mainMenu->getSelectedItem();
		switch (resultSelectedItem) {
		case 0:
			system("cls");
			cout << "клубничное";
			_getch();
			break;		
		case 1:
			system("cls");
			cout << "вынильное";
			_getch();
			break;
		case 2:
			system("cls");
			cout << "шоколадное";
			_getch();
			break;
		case 3:
			system("cls");
			cout << "фисташковое";
			_getch();
			break;
		case 4:
			resultSelectedItem = exitItem;
			break;
		default:
			break;
		}
	}
}