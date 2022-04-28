
#include <iostream>
#include "Maxtrix3Class.h"

using namespace std;

int main()
{
    Maxtrix3Class *m1 = new Maxtrix3Class();
    Maxtrix3Class *m2 = new Maxtrix3Class();
    int inc = 0;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
        {
            m1->matrix[i][j]=inc;
            m2->matrix[i][j]=3;
            inc++;
        }

    m1->Print();
    m2->Print();
}

