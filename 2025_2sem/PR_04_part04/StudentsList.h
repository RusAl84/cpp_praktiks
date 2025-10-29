#pragma once
#include "initial_data.h"
#include <iostream>
#include <fstream>
#include <string>     // для std::getline


struct node {
    struct Student *data;
    struct node* next;
};

class StudentsList	// класс "линейный односвязный список
{
	Node* first;	// указатель на первый узел списка
	Node* last;	// указатель на последний узел списка
public:
	StudentsList();	// прототип конструктора
	// методы и функции, реализующие вариативную часть задания
    struct node* myHead;
    int countItem = 0;

    //Визуализация для добавления и удаления элементов в односвязном списке.
    //https://www.cs.usfca.edu/~galles/visualization/StackLL.html

    /// <summary>
    /// Добавляет элемент в начало списка
    /// </summary>
    /// <param name="data"> данные элемента</param>
    void addItem(struct Student *data)
    {
        struct node* newItem = new node();
        newItem->data = data;
        if (countItem == 0)
            newItem->next = NULL;
        else
            newItem->next = myHead;
        myHead = newItem;
        countItem++;
    }
    /// <summary>
    /// Добавляет элемент в конец списка
    /// </summary>
    /// <param name="data"> данные элемента</param>
        void addItemBack(struct Student* data)
        {
            struct node* newItem = new node();
            newItem->next = NULL;
            newItem->data = data;
            if (countItem == 0){
                myHead = newItem;
            }
            else
            {
                struct node* current = myHead;
                while (current->next) {
                    current = current->next;
                }
                current->next = newItem;
            }
            countItem++;
        }

    /// <summary>
    /// Вставка элемента в список
    /// </summary>
    /// <param name="index">индекс после которого вставить</param>
    /// <param name="data">значение которое необходимо вставить</param>
    void insertItem(int index, struct Student* data) {
        if (not (index >= 0 and index <= countItem and countItem >= 0))
            return;
        if (index == 0)
            addItem(data);
        else {
            struct node* current = myHead;
            for (int i = 0; i < index - 1; i++) {
                current = current->next;
            }
            struct node* newItem = new node();
            newItem->data = data;
            newItem->next = current->next;
            current->next = newItem;
            countItem++;
        }
    }
    /// <summary>
    /// Изменить элемент списка
    /// </summary>
    /// <param name="index">индекс изменяемого элемента</param>
    /// <param name="data">значение на которое нужно изменить</param>
    void editItem(int index, struct Student* data) {
        if (index >= 0 and index < countItem and countItem>0) {
            struct node* current = myHead;
            for (int i = 0; i < index; i++) {
                current = current->next;
                //cout << "+" << current->data;
            }
            current->data = data;
        }
        else {
            cout << endl << "Ошибка индекс не в диапазоне";
        }
    }
    /// <summary>
    /// Функция для удаления элемента из динамического списка
    /// </summary>
    /// <param name="index">индекс удаляемого элемента</param>
    void deleteItem(int index) {
        if (index >= 0 and index < countItem and countItem>0) {
            struct node* current = myHead;
            struct node* old;
            if (index == 0) {
                old = myHead;
                myHead = current->next;
                delete old;
                countItem--;
            }
            else {
                int i = 0;
                while (current) {
                    if (i == index - 1) {
                        old = current->next->next;
                        delete current->next;
                        current->next = old;
                        countItem--;
                        break;
                    }
                    i++;
                    current = current->next;
                }
            }
        }

    }
    /// <summary>
    /// Печать списка
    /// </summary>
    void printMyList() {
        struct node* current = myHead;
        cout << endl;
        while (current) {
            cout << current->data->first_name << endl;
            current = current->next;
        }
    }
    /// <summary>
    /// Сохранить в файл
    /// </summary>
    void saveData() {
        struct node* current = myHead;
        int numStud = 0;
        FILE* studTextFile;
        fopen_s(&studTextFile, "studTextFile.txt", "w+");
        FILE* indexStudTextFile;
        fopen_s(&indexStudTextFile, "indexStudTextFile.txt", "w+");
        FILE* gradesTextFile;
        fopen_s(&gradesTextFile, "gradesTextFile.txt", "w+");
        while (current) {
            //cout << current->data->first_name << endl;
            fprintf(studTextFile, "%s\n%s\n%s\n%s\n", \
                current->data->number.c_str(), \
                current->data->first_name.c_str(), \
                current->data->birth_day.c_str(), \
                current->data->group.c_str() \
               );
            numStud++;
            int countGrade= current->data->results.size();
            string sNumStud=to_string(numStud); //https://www.geeksforgeeks.org/converting-number-to-string-in-cpp/
            string sCountGrade =to_string(countGrade);
            fprintf(indexStudTextFile, "%s\n%s\n", \
                sNumStud.c_str(), \
                sCountGrade.c_str() \
            ); 
            for (int i = 0; i < countGrade; i++) {
                string sMark = to_string(current->data->results[i].mark);
                fprintf(gradesTextFile, "%s\n%s\n%s\n", \
                    current->data->results[i].subject.c_str(), \
                    current->data->results[i].date.c_str(), \
                    sMark.c_str() \
                );
            }
            current = current->next;
        }
        fclose(studTextFile);
        fclose(indexStudTextFile);
        fclose(gradesTextFile);
    }

    void Dislay() {
        struct node* current = myHead;
        while (current) {
            cout << endl << current->data->number.c_str() << "  ";
            cout << current->data->first_name.c_str() << "  ";
            cout << current->data->birth_day.c_str() << "  ";
            cout << current->data->group.c_str() << endl;
            int countgrade = current->data->results.size();
            for (int i = 0; i < countgrade; i++) {
                cout  << current->data->results[i].subject.c_str() << "  ";
                    cout << current->data->results[i].date.c_str() << "  ";
                    cout << current->data->results[i].mark << endl;
            }
            current = current->next;
        }
    }

    /// <summary>
    /// Загрузить из файла
    /// </summary>
    void loadData() {
        int numStud = 0;
        string line;
        ifstream studTextFile("studTextFile.txt"); // https://metanit.com/cpp/tutorial/8.3.php?ysclid=mapbi2t0z3124686952
        ifstream indexStudTextFile("indexStudTextFile.txt");
        ifstream gradesTextFile("gradesTextFile.txt");
        struct Student* tmpSt = new Student();
        struct Grade* gr = new Grade();
        while (getline(studTextFile, line)) {
            tmpSt = new Student();
            tmpSt->number = line;
            getline(studTextFile, line);
            tmpSt->first_name = line;
            getline(studTextFile, line);
            tmpSt->birth_day = line;
            getline(studTextFile, line);
            tmpSt->group = line;
            numStud++;
            getline(indexStudTextFile, line);
            getline(indexStudTextFile, line);
            int countGrade = atoi(line.c_str());
            for (int i = 0; i < countGrade; i++) {
                getline(gradesTextFile, line);
                gr->subject = line;
                getline(gradesTextFile, line);
                gr->date = line;
                getline(gradesTextFile, line);
                gr->mark = atoi(line.c_str());
                tmpSt->results.push_back(*gr);
            }
            addItem(tmpSt);
        }
       studTextFile.close();
       indexStudTextFile.close();
       gradesTextFile.close();
    }

    /// <summary>
    /// Печать списка - пример задания
    /// </summary>
    void calcAvgMark() {
        struct node* current = myHead;
        while (current) {
            cout <<endl << current->data->first_name ;
            float avg_mark = 0;
            for (int i = 0; i < current->data->results.size(); i++)
                avg_mark += current->data->results[i].mark;
            avg_mark /= current->data->results.size();
            current->data->avg_mark = avg_mark;
            cout << " средний балл: " << avg_mark;
            current = current->next;
        }
    }

    /// <summary>
    /// var8
    /// </summary>
    void calcVar8() {
        // 8 вариант 
        // Поисковая операция :
        // поиск узлов по дате проведения занятия.
        struct node* current = myHead;
        class StudentsList dateSL;//поиск узлов по дате проведения занятия.
        string foundDate = "16/05/2025";
        cout << endl << "Поиск узлов по дате проведения занятия: " + foundDate;
        while (current) {
            cout << endl << current->data->first_name << endl;
            bool existDate = false;
            for (int i = 0; i < current->data->results.size(); i++)
                if (foundDate == current->data->results[i].date) {
                    cout << current->data->results[i].subject.c_str() << "  ";
                    cout << current->data->results[i].date.c_str() << "  ";
                    cout << current->data->results[i].mark << endl;
                    existDate = true;
                }
            if (existDate)
                dateSL.addItem(current->data);
            current = current->next;
        }
        cout << endl << "Поиск узлов по дате проведения занятия: " + foundDate;
        dateSL.Dislay();
        //dateSL.saveData();
        //    Расчетная операция :
        // расчет количества студентов, обучающихся в определенной группе.
        current = myHead;
        class StudentsList countSL;//поиск узлов по дате проведения занятия.
        string foundGroup = "ББСО-02-24";
        cout << endl << "Расчет количества студентов, обучающихся в определенной группе: " + foundGroup << endl;
        int countStud = 0;
        while (current) {
                if (foundGroup == current->data->group) {
                    cout << current->data->first_name ;
                    cout << " группа: " << current->data->group << endl;
                    countSL.addItem(current->data);
                    countStud++;
                }
            current = current->next;
        }
        cout << "Количество студентов, обучающихся в определенной группе: " + foundGroup;
        cout << " равно: " << countStud << endl;
    }

    void deleteItemAfterInd(int index) {
        int countDeleteItem = countItem - index;
        for(int i=0; i< countDeleteItem;i++)
            deleteItem(countItem-1);
    }


    void deleteItemBeforeInd(int index) {
        for (int i = 0; i < index; i++)
            deleteItem(0);
    }

    void calcVar26() {
        // 26 вариант 
        //Поисковая операция :
        // поиск узлов по дате рождения.
        struct node* current = myHead;
        class StudentsList dateSL2;//поиск узлов по дате рождения.
        string foundBirthDay = "27/12/1984";
        cout << endl << "Поиск узлов по дате рождения: " + foundBirthDay;
        while (current) {
            
            if (foundBirthDay == current->data->birth_day ) {
                    cout << endl << current->data->first_name;
                    cout << " дата рождения: " << current->data->birth_day << "  ";
                    dateSL2.addItem(current->data);
                }
            current = current->next;
        }
        cout << endl << endl << "Поиск узлов по дате рождения: " + foundBirthDay;
        dateSL2.Dislay();
        //Расчетная операция :
        // расчет количества студентов, имеющих определенную оценку по некоторой дисциплине.
         current = myHead;
        class StudentsList dateSL3;//поиск узлов по дате проведения занятия.
        string foundSubject = "СВТ";
        int foundMark = 5;
        cout << endl << "Расчет количества студентов, имеющих определенную оценку по некоторой дисциплине: " ;
        cout << endl << " оценку " << foundMark << " по  дисциплине: " << foundSubject;
        int count = 0;
        while (current) {
            for (int i = 0; i < current->data->results.size(); i++)
                if ((foundSubject == current->data->results[i].subject) and (foundMark == current->data->results[i].mark)) {
                    cout << endl << current->data->first_name << endl;
                    cout << current->data->results[i].subject.c_str() << "  ";
                    cout << current->data->results[i].date.c_str() << "  ";
                    cout << current->data->results[i].mark << endl;
                    dateSL3.addItem(current->data);
                    count++;
                }     
            current = current->next;
        }
        cout << endl << "Количество студентов, имеющих определенную оценку по некоторой дисциплине: " << count;
        dateSL3.Dislay();

    }
};

