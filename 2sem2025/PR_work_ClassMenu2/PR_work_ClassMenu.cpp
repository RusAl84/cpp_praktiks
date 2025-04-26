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
    ClassEdit* ed = new ClassEdit();
	int resultSelectedItem = 1;
	const int exitItem = 5;
	int capacity=0;
	mainMenu->addTitleItem("Добавление/изменение данных о студенте: ");
	mainMenu->addTitleItem("фамилия студента: " + st.first_name);
	mainMenu->addTitleItem("дата рождения студента: " + st.birth_day);
	mainMenu->addTitleItem("номер группы: " + st.group);
	mainMenu->addTitleItem("номер студ.билета: " + st.number);
	mainMenu->addTitleItem("Студент выпил матем.: " + to_string(capacity) + " г.");
	mainMenu->addItem("фамилия студента");
	mainMenu->addItem("дата рождения студента");
	mainMenu->addItem("номер группы");
	mainMenu->addItem("номер студ. билета");
	mainMenu->addItem("напоить сутдента математикой");
	mainMenu->addItem("выход");
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
			capacity = ed->setDataInt(100, 500, 250);
			cout << "Вы выбрали: " + to_string(capacity) + " г.";
			_getch();
			break;
		case 5:
			resultSelectedItem = exitItem;
			break;
		default:
			break;
		}
		mainMenu->eraseTitle();
		mainMenu->addTitleItem("Добавление/изменение данных о студенте: ");
		mainMenu->addTitleItem("фамилия студента: " + st.first_name);
		mainMenu->addTitleItem("дата рождения студента: " + st.birth_day);
		mainMenu->addTitleItem("номер группы: " + st.group);
		mainMenu->addTitleItem("номер студ.билета: " + st.number);
		mainMenu->addTitleItem("Студент выпил матем.: " + to_string(capacity) + " г.");
	}
}