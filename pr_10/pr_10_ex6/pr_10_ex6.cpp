#include "iostream"


class Human {
public:

    virtual void saySomething() {
        std::cout << "I'm Human";
    }


};

class Children : Human {
public:
    virtual void saySomething() override {
        std::cout << "I'm Children";

    }

};


int main() {

    Human().saySomething();
    std::cout << std::endl;
    Children().saySomething();

    return 0;
}

