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


    // методы и функции, реализующие вариативную часть задания
};

