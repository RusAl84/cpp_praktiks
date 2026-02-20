#pragma once
#include <iostream>
#include <windows.h>
#include <stdio.h>

using namespace std;

//Структура для организации линейного списка
struct node {
public:
    int data; // данные (целое число)
    node* next; // указатель на следующее значение
};

//Формат компонентных данных класса должен обеспечить возможность 
//создания объекта произвольного размера 
// (т.е. моделировать динамический массив). 

// класс динамического массива
class DinoBaraClass
{
public:
    // Класс должен содержать конструктор по умолчанию, 
    DinoBaraClass() {
        head=nullptr;
        count=0;
    };
    // конструктор с параметром (параметр конструктора 
    // – количество элементов компонентного массива), 
    DinoBaraClass(int size) {
        head = nullptr;
        count = 0;
        for (int i = 0; i < size; i++)
            addElement(genNum());
     };
    // конструктор копирования. 
    DinoBaraClass( DinoBaraClass &_other)
    {
        head = nullptr;
        count = 0;
        for (int i = 0; i < _other.count; i++)
            addElement(_other.getElement(i));
    }
    // Кроме того в состав компонентных функций 
    // класса должен входить деструктор.
    ~DinoBaraClass() {
        node* current = head;
        while (current) {
            node* prevCurrent = current;
            current = current->next;
            delete prevCurrent;
        }
    };
    void author() {
        cout << endl << "Русаков А.М.";
    }
    int genNum() {
        // генерация целых чисел 
        // https://learn.microsoft.com/ru-ru/cpp/c-runtime-library/reference/rand
        // fail числа одинаковые ;(
        //srand(time(NULL)); // !!! не помогло
        int range_min = -101;
        int range_max = 101;
        //int num = rand() % (end - start + 1) + start;  // формула  0..100
        int num = ((double)rand() / RAND_MAX) * (range_max - range_min) + range_min;
        return num;  // -100..100
    };
    /// <summary>
    /// Функция добавления элемента (в начало списка)
    /// </summary>
    /// <param name="data">значение (целое числое)</param>
    void addElement(int data)
    {
        if (count == 0) {
            head = new node;
            head->data = data;
            head->next = nullptr;
        }
        else {
            node* tmpPoint = head;
            head = new node;
            head->next = tmpPoint;
            head->data = data;
        }
        count++;
    }
    /// <summary>
    /// Вставить элемент в дин. массив
    /// </summary>
    /// <param name="pos">позиция</param>
    /// <param name="data">значение</param>
    void insertElement(int pos, int data) {
        if (count > 0)
            if ((pos >= 0) and (pos <= count))
            {
                if (pos == 0) {
                    node* tmpPoint = head;
                    head = new node;
                    head->next = tmpPoint;
                    head->data = data;
                }
                if ((pos > 0) and (pos < count)) {
                    int ind = 0;
                    node* current = head;
                    node* prev = nullptr;
                    while(current) {
                        if (ind == pos) {
                            node* tmpPoint = new node;
                            tmpPoint->next = current;
                            tmpPoint->data = data;
                            prev->next = tmpPoint;
                            break;
                        }
                        prev = current;
                        current = current->next;
                        ind++;
                    }
                }
                if (pos == count) {
                    node* current = head;
                    node* prev = nullptr;
                    while (current) {
                        prev = current;
                        current = current->next;
                    }
                    node* tmpPoint = new node;
                    tmpPoint->next = nullptr;
                    tmpPoint->data = data;
                    prev->next = tmpPoint;
                }
                count++;
            }

    }
    void setElement(int pos, int data) {
        if (count > 0)
            if ((pos >= 0) and (pos < count))
            {
                node* current = head;
                //cout << endl << "__Element:  ";
                int ind = 0;
                while (current) {
                    if (ind == pos)
                        current->data = data;
                    current = current->next;
                    ind++;
                }
            }
    }
    int getElement(int pos)                        
    {
        int element = 0;                        
        if (count>0)                        
            if ((pos >= 0) and (pos < count))                        
            {                        
                node* current = head;
                //cout << endl << "__Element:  ";
                int ind = 0;
                while (current) {
                    if (ind==pos)
                    {
                        element = current->data;
                        //cout << element;
                        break;
                    }
                    current = current->next;
                    ind++;
                }
            }
        return element;
    }
    void delElement(int pos) {
        if (count > 0)
            if ((pos >= 0) and (pos < count))
            {
                int ind = 0;
                node* current = head;
                node* prev_current = nullptr;
                if (count>1)
                    while (current) {
                        if (ind == pos) {
                            node* tmpPoint = current;
                            prev_current->next = current->next;
                            delete tmpPoint;
                            break;
                        }
                        prev_current = current;
                        current = current->next;
                        ind++;
                    }
                else {
                    delete head;
                    head = nullptr;
                }
                count--;
            }
    }
    // компонентную функцию для вывода на экран содержимого объекта;
    void display() {
        node* current = head;
        cout << endl << "__Display";
        while (current) {
            cout << endl << current->data;
            current = current->next;
        }
    }
    int getSize() {
        return count;
    }
private:
    // Компонентные данные класса 
    // должны быть размещены в закрытой части класса.
    node* head;
    int count;  // количество элементов
};