
#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
    for (int i = 30; i > 10; i--) {
        Beep(5000 - 100*i, 100+i*10);
        std::cout << i;
    }
    Beep(3000 , 20  * 1000);
    
    std::cout << "Hello World!\n";
}

