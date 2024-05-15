#include <iostream>
#include "clDate.h"
using namespace std;
int main()
{
 
    clDate date1;
    //date1.setDate(15, 05, 2024);
    date1.setDate(30, 02, 2023);
    cout << "Work Date!\n";
    date1.printDate();
}
