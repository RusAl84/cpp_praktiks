
#include <iostream>
#include "ClassVar3.h"
#include <cassert>

using namespace std;

int main()
{
    ClassVar3* stud = new ClassVar3("MERSOV", 18);
    //stud->FIO = "MERSOV";
    //stud->SetAge(18);

    assert(stud->Display()==true);
    //stud->Display();
    return 0;


    //ClassVar3* stud1 = new ClassVar3();
    //stud1->FIO = "Filatov";
    //stud1->Age = 46;
    //stud1->Display();
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
//