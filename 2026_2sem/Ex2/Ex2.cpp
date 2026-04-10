#include <iostream>
using namespace std;
void capyFunc(string* data) {
    (*data) += "   +capyFunc";
    //(*data)[0]='P';
    //(*data).clear();
    //data->clear();
}
int main()
{
    string  data1 = "zAngelina i gigaSasha i awdNikita i i megaNina i superKira i sigmaLena i alphaNika i ultraVasilina ne s'eli Egorov";
    for (int i = 0; i < 3; i++)
        data1 += " capy plachet,";
    data1[data1.length() -1] = '!';
    cout << data1.c_str() << endl;
    capyFunc(&data1);
    cout << data1.c_str() << endl;
//    string  *data2  = new string("Capy love Nina!");
//    cout << data2->c_str() << endl;
//    capyFunc(data2);
//    cout << data2->c_str() << endl;
//    cout << (*data2).c_str() << endl;
//
}