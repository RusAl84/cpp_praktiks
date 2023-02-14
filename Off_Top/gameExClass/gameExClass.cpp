#include <iostream>
#include "Sounds.h"

using namespace std;


int main()
{
    struct book {
        char title[81];
        char author[30];
        int pageCount;
    };
    struct book cpp1 = { "Программирование на C++", "Русаков Алексей", 3 };

    cout << cpp1.author << endl << cpp1.title << endl << cpp1.title;
    //std::cout << "Hello World!\n";
}
