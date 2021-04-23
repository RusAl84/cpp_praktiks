#include <iostream>

class E {
public:
    E() {
        std::cout << "class E" << std::endl;
    }
};

class B {
public:
    B() {
        std::cout << "class B" << std::endl;
    }
};

class C : public E {
public:
    C() {
        std::cout << "class C" << std::endl;
    }
};


class A: public B, public C {
public:
    A() {
        std::cout << "class A" << std::endl;
    }
};




class D: public C, public E {
public:
    D() {
        std::cout << "class D" << std::endl;
    }
};



class F: public A, public C, public E{
public:
    F() {
        std::cout << "class F"<< std::endl;
    }
};

int main()
{
    setlocale(LC_ALL,"ru");
    std::cout << "Ярослав" << std::endl;

    std::cout << "A\n";
    A * cA = new A();
    std::cout << "B\n";
    B * cB = new B();
    std::cout << "C\n";
    C * cC = new C();
    std::cout << "D\n";
    D * cD = new D(); 
    std::cout << "E\n";
    E * cE = new E();
    std::cout << "F\n";
    F * cF = new F();

}

