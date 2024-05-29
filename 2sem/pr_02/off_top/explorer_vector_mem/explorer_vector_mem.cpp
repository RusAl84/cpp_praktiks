#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector <int> vec1 = { 1,2,3,4,5 };

    for(int i=0;i<100;i++){
        vec1.push_back(777);
        vec1.push_back(777);
        vec1.push_back(777);
        vec1.push_back(777);
        cout << endl << "size = " << vec1.size();
        cout << endl << "capacity = " << vec1.capacity();
    }
}
