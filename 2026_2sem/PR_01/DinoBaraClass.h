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
private:
    // Компонентные данные класса 
    // должны быть размещены в закрытой части класса.
    node* head; // указатель на первый элемент
    int count;  // счетчик - количество элементов
public:
    // Класс должен содержать конструктор по умолчанию, 
    DinoBaraClass() {
        head=nullptr;
        count=0;
    };
    // конструктор с параметром (параметр конструктора 
    // – количество элементов компонентного массива), 
    DinoBaraClass(int _size) {
        head = nullptr;
        count = 0;
        for (int i = 0; i < _size; i++)
            addElementFront(genNum());
     };
    // конструктор копирования. 
    DinoBaraClass(DinoBaraClass &_other)
    {
        head = nullptr;
        count = 0;
        for (int i = 0; i < _other.count; i++)
            addElementRear(_other.getElement(i));
            //addElementFront(genNum());
    }
    // Кроме того в состав компонентных функций 
    // класса должен входить деструктор.
    ~DinoBaraClass() {
        node* current = head;
        node* prev = nullptr;
        while (current) {
            prev = current;
            current = current->next;
            delete prev;
        }
    };
    /// <summary>
    /// Информация об авторе
    /// </summary>
    void author() {
        cout << endl << "Русаков А.М.";
    }
    /// <summary>
    /// Генерация целых чисел
    /// </summary>
    /// <returns>Целое число -100..100</returns>
    int genNum() {
        // генерация целых чисел 
        // https://learn.microsoft.com/ru-ru/cpp/c-runtime-library/reference/rand
        // fail числа одинаковые ;(
        //srand(time(NULL)); // !!! не помогло
        int rangeMin = -101;
        int rangeMax = 101;
        //int num = rand() % (end - start + 1) + start;  // формула  0..100
        int num = ((double)rand() / RAND_MAX) * (rangeMax - rangeMin) + rangeMin;
        return num;  // -100..100
    };
    /// <summary>
    /// Функция добавления элемента (в начало списка)
    /// </summary>
    /// <param name="data">значение (целое числое)</param>
    void addElementFront(int data)
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
    void addElementRear(int _data) {
        if (count == 0) {
            head = new node;
            head->data = _data;
            head->next = nullptr;
        }
        else {
        node* current = head;
        node* prev = nullptr;
        while (current) {
            prev = current;
            current = current->next;
        }
        node* tmpNode = new node; // создаю временный узел
        tmpNode->next = nullptr;
        tmpNode->data = _data;
        prev->next = tmpNode;
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
                    addElementFront(data);
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
                    count++;
                }
                if (pos == count) {
                    addElementRear(data);
                }
                
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
    int getElement(int _pos)                        
    {
        int element = -1;                        
        if (count>0)                        
            if ((_pos >= 0) and (_pos < count))                        
            {                        
                node* current = head;
                //cout << endl << "__Element:  ";
                int ind = 0;
                while (current) {
                    if (ind==_pos)
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
    void delElement(int _pos) {
        if (count > 0)
            if ((_pos >= 0) and (_pos < count))
            {
                int ind = 0;
                node* current = head;
                node* prev = nullptr;
                if (count>1)
                    while (current) {
                        if (ind == _pos) {
                            node* tmpPoint = current;
                            prev->next = current->next;
                            delete tmpPoint;
                            break;
                        }
                        prev  = current;
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
    bool operator=(const DinoBaraClass& _other) 
    {
        // очистка текущего массива ( this->)
        node* current = this->head;
        node* prev = nullptr;
        while (current) {
            prev = current;
            current = current->next;
            delete prev;
        }
        this->count = 0;
        // копирование элементов
        current = _other.head;
        while (current) {
            this->addElementRear(current->data);
            current = current->next;
        }
        return true; //return head == other.head && count == other.count;
    }
    DinoBaraClass operator^(int _stepen) {
        cout << endl<< endl<<"NIKA i NINA i LENA (belosnezhka tozhe) ne s'eli KAPI";
        node* current = this->head;
        int index = 0;
        while (current) {
            if (index % 2 == 1)
            {
                int tmp = current->data;
                current->data = pow(tmp, _stepen);
            }
            current = current->next;
            index++;
        }
        return *this;
    }
    

};