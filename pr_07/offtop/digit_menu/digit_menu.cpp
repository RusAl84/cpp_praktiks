// digit_menu.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

using namespace std;

struct exam {
    string subject[100];
    int mark; // 0 - не зачтено
              // 1 - зачтено
              // 2 - 2; 3 - 3; 4 - 4; 5 - 5;
    bool isEmpty;
};
struct student {
    char name[30];
    char group[10];
    exam sessData[10][9];
};

void AddStudData() {
    student st;

    cout << "Введите Имя:";
    string bufer;
    cin >> bufer;
    strcpy(st.name, bufer.c_str());

    cout << "Введите группу:";
    cin >> bufer;
}


int main()
{   
    setlocale(LC_ALL, "Russian");
    int chouse = -1;
    while (chouse != 0) {
        cout << "Введите 0 для выхода" << endl;
        cout << "Введите 1 для добавления данных о студенте" << endl;
        cin >> chouse;
        switch (chouse) {
        case 0:
            break;
        case 1: 
            AddStudData();
            break;
        default:
            break;
        }
    }

    std::cout << "Конец програмыы\nВы все умрете...\n";
}
