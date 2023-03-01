#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;
string Lessons[5];

struct Student {
    char FIO[40];
    int Marks[5];
};

int main() {
    setlocale(LC_ALL, "Russian");
    Lessons[0] = "математика";
    Lessons[1] = "физика";
    Lessons[2] = "черчение";
    Lessons[3] = "химия";
    Lessons[4] = "сопромат";
    int LengthOfLessons = 5;
    cout << "ВВедите количество студентов";
    int n;
    cin >> n;
    Student MasOfStudents[2000];
    for (int i = 0; i < n; i++) {
        cout << "ВВедите ФИО студента";
        cin >> MasOfStudents[i].FIO;
        for (int j = 0; j < LengthOfLessons; j++) {
            cout << "Введите оценку по " << Lessons[j] << ":";
            cin >> MasOfStudents[i].Marks[j];
        }
    }

    //Проверка сколько студентов имеют неудовлетворительную оценку
    int KolStudNaHorIOtl = 0;
    for (int i = 0; i < n; i++) {
        bool flag = false;
        for (int j = 0; j < LengthOfLessons; j++) {
            if (MasOfStudents[i].Marks[j] < 3) {
                flag = true;
                break;
            }
        }
        if (flag)
            KolStudNaHorIOtl++;
    }
    cout << "Cколько студентов имеют неудовлетворительную оценку: " << KolStudNaHorIOtl;



}