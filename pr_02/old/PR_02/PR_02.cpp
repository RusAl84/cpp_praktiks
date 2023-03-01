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
    cout << "Введите количество студентов: ";
    int n;
    cin >> n;
    Student MasOfStudents[2000];
    for (int i = 0; i < n; i++) {
        cout << "Введите ФИО студента: ";
        cin >> MasOfStudents[i].FIO;
        for (int j = 0; j < LengthOfLessons; j++) {
			cout << "Введите оценку по " << Lessons[j] << ":";
            cin >> MasOfStudents[i].Marks[j];
        }
    }

    cout << "Введите Ваш номер варианта: ";
    int v = 0;
    cin >> v;
    if (v==1){
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
    if (v == 6) {
        //Проверка сколько студентов имеют средний балл от 4 до 5.
        int KolStud = 0;
        for (int i = 0; i < n; i++) {
            double SrBall = 0;
            for (int j = 0; j < LengthOfLessons; j++) {
                SrBall += MasOfStudents[i].Marks[j];
            }
            SrBall /= LengthOfLessons;
            cout << SrBall << endl;
            if (SrBall > 4)
                KolStud++;
        }
        cout << "Cколько студентов имеют средний балл от 4 до 5 " << KolStud;
    }
    if (v == 7) {
        //Какое количество неудовлетворительных оценок получено по всем предметам
        int KolNeudOc = 0;
        for (int i = 0; i < n; i++) {
            double SrBall = 0;
            for (int j = 0; j < LengthOfLessons; j++) {
                if (MasOfStudents[i].Marks[j] < 3)
					KolNeudOc++;
            }
        }
        cout << "Какое количество неудовлетворительных оценок получено по всем предметам: " << KolNeudOc;
    }


}