#include <iostream>
#include "clDate.h"
using namespace std;
int main()
{
 
    struct myDate stDate1;
    stDate1.day = -7;
    stDate1.month = 05;
    stDate1.year = 2024;
    
    class clDate date1(15,05,2024);
    //class clDate date1(&stDate1);
    //date1.setDate(15, 05, 2024);
    date1.setDate(29, 02, 2023);
    cout << "Work Date!\n";
    date1.printDate();
    cout << endl << clDate::convertDate(stDate1, '.');
}
