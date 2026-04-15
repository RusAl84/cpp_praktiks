#pragma once
#include "initial_data.h"
#include <iostream>
#include <fstream>
#include <string>     // для std::getline

//Визуализация для добавления и удаления элементов в односвязном списке.
//https://www.cs.usfca.edu/~galles/visualization/StackLL.html
class StudentsList	// класс "линейный односвязный список
{
    struct Node* first;	// указатель на первый узел списка
    struct Node* last;	// указатель на последний узел списка
    int countItem = 0; // количество элементов
public:
    StudentsList() {
        first = nullptr;
        last = nullptr;
        countItem = 0;
    }	// конструктор по умолчанию

    void addItem(struct Student* _data)
    {
        struct Node* newItem = new Node();
        newItem->item = _data;
        if (countItem == 0)
            newItem->next = NULL;
        else
            newItem->next = first;
        first = newItem;
        countItem++;
    }
    void printMyList() {
        struct Node* current = first;
        cout << endl;
        while (current) {
            cout << current->item->first_name << endl;
            current = current->next;
        }
    }
    void saveData() {
        struct Node* current = first;
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
                current->item->number.c_str(), \
                current->item->first_name.c_str(), \
                current->item->birth_day.c_str(), \
                current->item->group.c_str() \
            );
            numStud++;
            int countGrade = current->item->results.size();
            string sNumStud = to_string(numStud); //https://www.geeksforgeeks.org/converting-number-to-string-in-cpp/
            string sCountGrade = to_string(countGrade);
            fprintf(indexStudTextFile, "%s\n%s\n", \
                sNumStud.c_str(), \
                sCountGrade.c_str() \
            );
            for (int i = 0; i < countGrade; i++) {
                string sMark = to_string(current->item->results[i].mark);
                fprintf(gradesTextFile, "%s\n%s\n%s\n", \
                    current->item->results[i].subject.c_str(), \
                    current->item->results[i].date.c_str(), \
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
        struct Node* current = first;
        while (current) {
            cout << endl << current->item->number.c_str() << "  ";
            cout << current->item->first_name.c_str() << "  ";
            cout << current->item->birth_day.c_str() << "  ";
            cout << current->item->group.c_str() << endl;
            int countgrade = current->item->results.size();
            for (int i = 0; i < countgrade; i++) {
                cout << current->item->results[i].subject.c_str() << "  ";
                cout << current->item->results[i].date.c_str() << "  ";
                cout << current->item->results[i].mark << endl;
            }
            current = current->next;
        }
    }

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

    // методы и функции, реализующие вариативную часть задания
    void calcAvgMark() {
        struct Node* current = first;
        while (current) {
            cout << endl << current->item->first_name;
            float avg_mark = 0;
            for (int i = 0; i < current->item->results.size(); i++)
                avg_mark += current->item->results[i].mark;
            avg_mark /= current->item->results.size();
            current->item->avg_mark = avg_mark;
            cout << " sredniy ball: " << avg_mark;
            current = current->next;
        }
    }

    /// var8
    void calcVar8() {
        // 8 вариант 
        // Поисковая операция :
        // поиск узлов по дате проведения занятия.
        struct Node* current = first;
        class StudentsList dateSL;//поиск узлов по дате проведения занятия.
        string foundDate = "16/05/2026";
        cout << endl << "Poisk uzlov po date provedeya zanyatiya: " + foundDate;
        while (current) {
            cout << endl << current->item->first_name << endl;
            bool existDate = false;
            for (int i = 0; i < current->item->results.size(); i++)
                if (foundDate == current->item->results[i].date) {
                    cout << current->item->results[i].subject.c_str() << "  ";
                    cout << current->item->results[i].date.c_str() << "  ";
                    cout << current->item->results[i].mark << endl;
                    existDate = true;
                }
            if (existDate)
                dateSL.addItem(current->item);
            current = current->next;
        }
        cout << endl << "Poisk uzlov po date provedeniya zanyatiya: " + foundDate;
        dateSL.Dislay();
        //dateSL.saveData();
        //    Расчетная операция :
        // расчет количества студентов, обучающихся в определенной группе.
        current = first;
        class StudentsList countSL;//поиск узлов по дате проведения занятия.
        string foundGroup = "ББСО-02-24";
        cout << endl << "Rasschet kolichestva studentov, obuchaushihsya v opredelennoy gruppe: " + foundGroup << endl;
        int countStud = 0;
        while (current) {
            if (foundGroup == current->item->group) {
                cout << current->item->first_name;
                cout << " gruppa: " << current->item->group << endl;
                countSL.addItem(current->item);
                countStud++;
            }
            current = current->next;
        }
        cout << "kolichestva studentov, obuchaushihsya v opredelennoy gruppe: " + foundGroup;
        cout << " ravno: " << countStud << endl;
    }
    void deleteItem(int index) {
        if (index >= 0 and index < countItem and countItem>0) {
            struct Node* current = first;
            struct Node* old;
            if (index == 0) {
                old = first;
                first = current->next;
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
    void deleteItemAfterInd(int index) {
        int countDeleteItem = countItem - index;
        for (int i = 0; i < countDeleteItem; i++)
            deleteItem(countItem - 1);
    }


    void deleteItemBeforeInd(int index) {
        for (int i = 0; i < index; i++)
            deleteItem(0);
    }

    void addItemBack(struct Student* data)
    {
        struct Node* newItem = new Node();
        newItem->next = NULL;
        newItem->item = data;
        if (countItem == 0) {
            first = newItem;
        }
        else
        {
            struct Node* current = first;
            while (current->next) {
                current = current->next;
            }
            current->next = newItem;
        }
        countItem++;
    }

    void insertItem(int index, struct Student* data) {
        if (not (index >= 0 and index <= countItem and countItem >= 0))
            return;
        if (index == 0)
            addItem(data);
        else {
            struct Node* current = first;
            for (int i = 0; i < index - 1; i++) {
                current = current->next;
            }
            struct Node* newItem = new Node();
            newItem->item = data;
            newItem->next = current->next;
            current->next = newItem;
            countItem++;
        }
    }
 
    void editItem(int index, struct Student* data) {
        if (index >= 0 and index < countItem and countItem>0) {
            struct Node* current = first;
            for (int i = 0; i < index; i++) {
                current = current->next;
                //cout << "+" << current->data;
            }
            current->item = data;
        }
        else {
            cout << endl << "Index ne v diapozone";
        }
    }


    void calcVar26() {
        // 26 вариант 
        //Поисковая операция :
        // поиск узлов по дате рождения.
        struct Node* current = first;
        class StudentsList dateSL2;//поиск узлов по дате рождения.
        string foundBirthDay = "27/12/1984";
        cout << endl << "Poisk studentov po date rozhdeniya: " + foundBirthDay;
        while (current) {

            if (foundBirthDay == current->item->birth_day) {
                cout << endl << current->item->first_name;
                cout << " data rozhdeniya: " << current->item->birth_day << "  ";
                dateSL2.addItem(current->item);
            }
            current = current->next;
        }
        cout << endl << endl << "Poisk studentov po date rozhdeniya: " + foundBirthDay;
        dateSL2.Dislay();
        //Расчетная операция :
        // расчет количества студентов, имеющих определенную оценку по некоторой дисциплине.
        current = first;
        class StudentsList dateSL3;//поиск узлов по дате проведения занятия.
        string foundSubject = "SVT";
        int foundMark = 5;
        cout << endl << "Raschet kolichestva studentov, imeyushchih opredelennuyu ocenku po nekotoroj discipline: ";
        cout << endl << " ocenku " << foundMark << " po discipline: " << foundSubject ;
        int count = 0;
        while (current) {
            for (int i = 0; i < current->item->results.size(); i++)
                if ((foundSubject == current->item->results[i].subject) and (foundMark == current->item->results[i].mark)) {
                    cout << endl << current->item->first_name << endl;
                    cout << current->item->results[i].subject.c_str() << "  ";
                    cout << current->item->results[i].date.c_str() << "  ";
                    cout << current->item->results[i].mark << endl;
                    dateSL3.addItem(current->item);
                    count++;
                }
            current = current->next;
        }
        cout << endl << "Kolichestvo studentov, imeyushchih opredelennuyu ocenku po nekotoroj discipline: " << count;
        dateSL3.Dislay();

    }

};

