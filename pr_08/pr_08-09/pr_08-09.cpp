#include <iostream>
#include "clDate.h"

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
    double studentship; //Стипендия;
public:
    clStudent(string _surName,
        string _name,
        string _middleName,
        clDate _bDate,
        enum class sex  _sex,
        clDate _startDate,
        double _studentship) 
    {
        surName = _surName;
        name = _name;
        middleName = _middleName;
        bDate = _bDate;
        this->sex = _sex;
        startDate = _startDate;
        studentship = _studentship;
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
    void addStudent(string _surName,
        string _name,
        string _middleName,
        clDate _bDate,
        enum class sex _sex,
        clDate _startDate,
        double _studentship) {
        if (countStud==0) {
            listOfStudents =  new clStudent(_surName, _name, _middleName, _bDate, _sex, _startDate , _studentship);
            countStud++;
        }
    };
    void printAll() {
        cout<< "Фамилия"
    }
};

int main()
{
    clGroup BBBO01;
    BBBO01.addStudent("Филатов", "Никита", "Михайлович", { 12, 5, 1974 }, sex::Men, { 1, 8, 1996 }, 1000);
    std::cout << "Hello World!\n";
}
