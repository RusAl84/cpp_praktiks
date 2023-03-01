#include <iostream>
#include <vector>
using namespace std;


int main()
{
    struct bigStruct {
        char name1[10000];
        char name2[10000];
        char name3[10000];
        char name4[10000];
        char name5[10000];
        char name6[10000];
        char name7[10000];
        char name8[10000];

    };
    struct bigStruct s2;
    vector<bigStruct> s1;
    vector<bigStruct> s3;
    vector<bigStruct> s4;
    for (int i=0;i++;i<10000){
         s1.insert(s1.begin(), s2);
         s3.insert(s1.begin(), s2);
         s4.insert(s1.begin(), s2);
    }
}