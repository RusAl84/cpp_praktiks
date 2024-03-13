#include <iostream>

int main()
{
    //int* p1{ new int{12} };
    //int* p2{ p1 };   // p1 и  p2 указывают на один и тот же объект

    //std::cout << *p1 << std::endl;  // 12
    //std::cout << *p2 << std::endl;  // 12
    //delete p1;      // адреса в p1 и p2 недопустимы
    //p1 = nullptr;
    //p2 = nullptr;



    //p1 = new int{ 11 };   // p1 указывает на новый объект
    //std::cout << *p1 << std::endl;  // 11
    //delete p1;

    int* p1 = new int{ 1 };
    int* p2 = new int{ 2 };
    p1 = p2;
    std::cout << *p1 << std::endl;
    std::cout << *p2 << std::endl;

}