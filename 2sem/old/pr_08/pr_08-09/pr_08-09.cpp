﻿#include <iostream>
#include "clDate.h"
#include "windows.h"

using namespace std;

enum class sex : char { Women, Men, Any };  

class clStudent {
protected:
    string surName;     //Фамилия(string);
    string name;        //Имя(string);
    string middleName;  //Отчество(string);
    clDate bDate;       //Дата рождения(clDate);
    enum class sex sex;     //Пол;
    clDate startDate;   //Дата зачисления(clDate)
    double studentShip; //Стипендия;
public:
    clStudent(){
        surName = "Филатов";
        name = "Андрей";
        middleName = "Александрович";
        bDate = { 12, 5, 1974 };
        this->sex = sex::Men;
        startDate = { 1, 9, 2022 };
        studentShip = 1000;
    }
    clStudent(string _surName, string _name, string _middleName, clDate _bDate,
        enum class sex  _sex, clDate _startDate, double _studentShip)
    {
        surName = _surName;
        name = _name;
        middleName = _middleName;
        bDate = _bDate;
        this->sex = _sex;
        startDate = _startDate;
        studentShip = _studentShip;
    };
    void print() {
        cout << " Фамилия: " << surName << " Имя: " << name << " Отчество: " << middleName;
        cout << " Дата рождения: "; bDate.printDate(); cout << endl;
        cout << " Пол: ";
        switch (sex)
        {
        case sex::Women:
            cout << "женский ";
            break;
        case sex::Men:
            cout << "мужской ";
            break;
        case sex::Any:
            cout << "не бинарный ";
            break;
        default:
            break;
        };
        cout << " Дата зачисления: "; startDate.printDate(); cout << " Стипендия: " << studentShip << endl;
    };
};

class clGroup {
protected:
    string name; // – Название (шифр) группы (строка, string);
    string institute; // – Институт(строка, string);
    string department; // – Выпускающая кафедра(строка, string);
    string tutorName; // – Фамилия ИО куратора(строка, string);
    int countStud; // –	Численность(целое);
    clStudent *listOfStudents; // – список студентов, представляющий собой динамический массив объектов «Студент» (clStudent), 
public:
    clGroup() { 
        countStud = 0;
        listOfStudents == NULL; };
    clGroup(string _name, string _institute, string _department, string _tutorName) :clGroup() {
        this->name = _name;
        this->institute = _institute;
        this->department = _department;
        this->tutorName = _tutorName;
    };

    void addStudent(string _surName, string _name, string _middleName, clDate _bDate,   enum class sex _sex,
        clDate _startDate, double _studentship) {
        // https://metanit.com/cpp/tutorial/4.11.php
        if (countStud==0) {
            listOfStudents = { new clStudent[1] {clStudent(_surName, _name, _middleName, _bDate, _sex, _startDate , _studentship)} };
            //listOfStudents = new clStudent(_surName, _name, _middleName, _bDate, _sex, _startDate, _studentship);
            countStud++;
        }
        else {
            countStud++;
            clStudent* ols = listOfStudents;
            listOfStudents = { new clStudent[countStud]{} };
            for (int i = 0; i < countStud - 1; i++) {
                listOfStudents[i] = ols[i];
            }
            clStudent* ls = { new clStudent[1] {clStudent(_surName, _name, _middleName, _bDate, _sex, _startDate , _studentship)} };
            listOfStudents[countStud - 1] = ls[0];
        }
    };
    void printAll() {
        cout << " Название (шифр) группы: " << name << " Институт " << institute << endl;
        cout << " Выпускающая кафедра: " << department << " Фамилия ИО куратора " << tutorName;
        cout << " Численность: " << countStud << endl;
        for (int i = 0; i < countStud; i++) {
            cout << " ____________________________ " << endl;
            listOfStudents[i].print();
            cout << " ____________________________ " << endl;
        }
    }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    clGroup * BBSO01 = new clGroup( "ББСО-01-22", "ИКБ", "КБ-4 Информационная безопасность", "Пиджаков Д.А.");
    BBSO01->addStudent("Филатов", "Никита", "Михайлович", { 12, 5, 1974 }, sex::Men, { 1, 8, 1996 }, 1000);
    BBSO01->addStudent("Русаков", "Никита", "Михайлович", { 12, 5, 1974 }, sex::Men, { 1, 8, 1996 }, 1000);
    BBSO01->addStudent("Игнатович", "Александра", "Алексеевна", { 12, 5, 2000 }, sex::Women, { 9, 8, 2000 }, 28000);
    BBSO01->addStudent("Гладкова", "Кира", "Алексеевна", { 12, 5, 2000 }, sex::Women, { 9, 8, 2000 }, 28000);
    BBSO01->printAll();
}
