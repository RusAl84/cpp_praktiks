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

     };
    // конструктор копирования. 

 
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
        // генерация целых чисел https://codelessons.dev/ru/rand-in-cplusplus/
        int start = 0;
        int end = 100;
        int num = rand() % (end - start + 1) + start;  // формула  0..100
        start = 0;
        end = 1;
        int x = rand() % (end - start + 1) + start; //смена знака -100..100
        if (x == 0)
            num *= -1;   // -1 или +1
        return num;
    };
    /// <summary>
    /// Функция добавления элемента (в начало списка)
    /// </summary>
    /// <param name="element">значение (целое числое)</param>
    void addElement(int element) 
    {
        if (count == 0) {
            head = new node;
            head->data = element;
            head->next = nullptr;
        }
        else {
            node* tmpPoint = head;
            head = new node;
            head->next = tmpPoint;
            head->data = element;
        }
        count++;
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

