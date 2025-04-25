#include <iostream>
#include <windows.h>
#include <stdio.h>
#include "ClassEdit.h"
#include "ClassMenu.h"
using namespace std;

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

    ClassMenu* mainMenu = new ClassMenu();
	int resultSelectedItem = 1;
	const int exitItem = 4;
	mainMenu->addTitleItem("Выберите себе мороженое: ");
	mainMenu->addItem("клубничное");
	mainMenu->addItem("вынильное");
	mainMenu->addItem("шоколадное");
	mainMenu->addItem("фисташковое");
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