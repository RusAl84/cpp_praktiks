// pr_10_ex2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "Human.h"

int main()
{
    // создание объекта
    Human human_obj = Human("Lavrov  ministr$)");
   for(int i=0;i<10;i++)
   {
        human_obj.saySomething();
        std::cout << std::endl;
   }
   

    Human* human_dyn_obj = new Human();
    human_dyn_obj->known_phrase = "Ya devochka";
    std::cout << std::endl;
    human_dyn_obj->saySomething();
    //delete human_dyn_obj;

    return 0;
}

