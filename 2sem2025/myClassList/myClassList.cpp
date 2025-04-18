#include <iostream>
#include "myClassList.h"

using namespace std;

int main()
{
    cout << "myClassList\n";
    myClassList* mList = new myClassList();
    mList->addItemFront(1);
    mList->addItemFront(1);
    mList->addItemFront(1);
    mList->addItemBack(2);
    mList->addItemBack(2);
    mList->addItemBack(2);
    mList->printMyList();
}
