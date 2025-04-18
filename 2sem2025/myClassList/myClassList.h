#pragma once
#include <iostream>

using namespace std;

/// <summary>
/// Структура узла динамического списка
/// </summary>
struct node {
    int data;
    struct node* next;
};

//Визуализация для добавления и удаления элементов в односвязном списке.
//https://www.cs.usfca.edu/~galles/visualization/StackLL.html

class myClassList
{
private:
    struct node* myHead;
    int countItem = 0;
public:
    /// <summary>
    /// Добавляет элемент в начало.
    /// </summary>
    /// <param name="data"> данные элемента</param>
    void addItemFront(int data)
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
    void addItemBack(int data)
    {
        struct node* newItem = new node();
        newItem->data = data;
        newItem->next = NULL;
        if (countItem == 0)
        {
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
        newItem->next = myHead;

        countItem++;
    }
    /// <summary>
    /// Печать списка
    /// </summary>
    void printMyList() {
        struct node* current = myHead;
        cout << endl;
        while (current) {
            cout << " " << current->data;
            current = current->next;
        }
    }
};

