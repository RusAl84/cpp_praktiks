#include <iostream>
#include "myClassList.h"

using namespace std;

int main()
{
    myClassList* mList = new myClassList();
    cout << "myClassList\n";
    mList->printMyList();
}
