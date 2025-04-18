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
        countItem++;
    }
    /// <summary>
/// Вставка элемента в список
/// </summary>
/// <param name="index">индекс после которого вставить</param>
/// <param name="data">значение которое необходимо вставить</param>
    void insertItem(int index, int data) {
        if (not (index >= 0 and index <= countItem and countItem >= 0))
            return;
        if (index == 0)
            addItemFront(data);
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
    void editItem(int index, int data) {
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
            cout << " " << current->data;
            current = current->next;
        }
    }
    /// <summary>
    /// Получить количество элементов
    /// </summary>
    /// <returns>количество элементов</returns>
    int getCountItem() {
        return countItem;
    }
};

