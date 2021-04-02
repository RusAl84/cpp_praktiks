// pr_08.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>

using namespace  std;

void display(vector <int> ve) {
    for (auto item : ve) 
        cout << item << ", ";
}

/// <summary>
/// func var7
/// </summary>
/// <param name="x"> hz chto takoe </param>
/// <returns></returns>
int func7(int x) {
    //Вычислить вектор “обратных” накопленных сумм : 
    //(пусть n = размер вектора a – 1) 
    //    b0 = a0 + a1 + … + an, 
    //    b1 = a1 + a2 + … + an, …, 
    //    bi = ai + ai + 1 + … + an, …, 
    //    bn = an.

    vector<int> a{ 1, 2, 3, 4, 5 };
    vector<int> b(5);
    for (int i = 0; i < b.size(); i++) {
        int bi = b[i];
        for (int j = i; j < b.size(); j++) 
            bi += a[j];
        b[i] = bi;
    }
    cout << "Вариант № 7 " << endl;;;;
    cout <<"a = ";
    display(a);
    cout << endl;
    cout << "b = ";
    display(b);
    cout << endl;
    return 8;
}

int main()
{
    setlocale(LC_ALL, "");
    func7(9987);
}
