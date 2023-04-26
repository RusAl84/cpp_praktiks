// pr_06_var7.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "ClassVar7.h"
#include "ClassVar2.h"

using namespace std;

int main()
{

    std::cout << "Hello World!\n";

    //ClassVar7 *var7 = new ClassVar7(65);
    ////var7->Age = 36;
    ////var7->SetAge(0);
    ////var7->Setpmas();
    //var7->Display(0);
    ClassVar2* var2 = new ClassVar2();
    var2->lia();

}

