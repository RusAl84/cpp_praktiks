#include <iostream>
#include "PersonClass.h"

using namespace std;

int main()
{
    cout << "Hello World!\n";
    PersonClass sasha;
    sasha.name = "Санчес";
    //sasha.age = 17;
    sasha.setAge(17);
    sasha.display();
}
