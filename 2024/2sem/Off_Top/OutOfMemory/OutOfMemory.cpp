#include <iostream>
int main()
{
    int size = 1e+20;
    int csize = 1e+40;
    for (int i = 0; i < 1e+10; i++){
        std::cout << i << std::endl;
        /*calloc(size, csize);*/
       int * p =  new int(csize);
    }
}