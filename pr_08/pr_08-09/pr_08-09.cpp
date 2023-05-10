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
    enum class sex;     //Пол;
    clDate startDate;   //Дата зачисления(clDate)
    double studentship; //Стипендия;
public:
    clStudent() {};
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
    clGroup() { listOfStudents == NULL; };
    void addStudent(clStudent* st) {
    
    };
};

int main()
{
    std::cout << "Hello World!\n";
}
