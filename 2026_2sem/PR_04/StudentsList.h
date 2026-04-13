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



    // методы и функции, реализующие вариативную часть задания
};

