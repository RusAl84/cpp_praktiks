#include <iostream>
#include <windows.h>
#include <stdio.h>
#include "myClassList.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout << "myClassList\n";
    myClassList* mList = new myClassList();
    mList->addItemFront(1);
    mList->addItemFront(1);
    mList->addItemFront(1);
    mList->addItemBack(2);
    mList->addItemBack(2);
    mList->addItemBack(2);
    mList->printMyList();
    cout << endl << "Count item: " << mList->getCountItem() << endl;
    mList->editItem(0, 777);
    mList->printMyList();
    mList->deleteItem(3);
    mList->printMyList();
    mList->insertItem(4, 888);
    mList->printMyList();
    cout << endl << "Count item: " << mList->getCountItem() << endl;
    mList->editItem(5, 555);
    mList->printMyList();

}
