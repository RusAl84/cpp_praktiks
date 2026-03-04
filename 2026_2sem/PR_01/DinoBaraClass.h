#pragma once
#include <iostream>
#include <windows.h>
#include <stdio.h>

using namespace std;

//Структура для организации линейного списка
struct node {
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
        double r = rand();
        //int num = rand() % (end - start + 1) + start;  // формула  0..100
        int num = ((double) r / RAND_MAX) * (rangeMax - rangeMin) + rangeMin;
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
        if (count > 0) // if (head)
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
    // 25  11
    DinoBaraClass operator^(int _stepen) {
        cout << endl<< endl<<"NIKA i NINA i LENA (belosnezhka tozhe) ne s'eli KAPI";
        cout << endl<< endl<<"MegaNatasha Rulez ALPHACH SIGmA";
        cout << endl<< endl<<"MegaMasha love SVT forever";

        node* current = this->head;
        int index = 0;
        while (current) {
            if (index % 2 == 1) // нечетный элемент
            {
                int tmp = current->data;
                current->data = pow(tmp, _stepen);
            }
            current = current->next;
            index++;
        }
        return *this;
    }
    // 24 вариант 
    bool operator<(const DinoBaraClass& _other)
    {
        node *curent  = this->head;
        int _count = 0;
        int sum = 0;
        //d91 = -61, 12, -100
        while (curent) {
            _count++;
            sum += curent->data;
            curent = curent->next;
        }
        float _average1 = sum / _count;

        curent = _other.head;
        _count = 0;
        sum = 0;
        //d91 = -61, 12, -100
        while (curent) {
            _count++;
            sum += curent->data;
            curent = curent->next;
        }
        float _average2 = sum / _count;
        if (_average1 < _average2)
            return true;
        else
            return false;
    }

    // 18 вариант
    // Поэлементное деление элементов 
    // компонентных массивов c четными номерами
    DinoBaraClass operator/( DinoBaraClass& _other) {
        cout << endl <<"MegaKate Alpha SIGAMA";
        node* current = this->head;
        int index = 0;
        while (current) {
            if (index % 2 == 0)  // четные
            {
                int tmp = _other.getElement(index);
                current->data = current->data / tmp;
            }
            current = current->next;
            index++;
        }
        return *this;
    }
    // 23
    // Сортировка элементов компонентного массива по убыванию
    void sortDesc() {
        int n = getSize();
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                //    v[j] = v[j + 1]
                //    v[j + 1] = tmp;
                if (getElement(j)< getElement(j+1)){  //if (v[j] > v[j + 1])
                    int tmp = getElement(j); //    int tmp = v[j];
                    setElement(j, getElement(j + 1));//    v[j] = v[j + 1]
                    setElement(j+1, tmp);//    v[j + 1] = tmp;
                    }
            }
        }
    }
    void sortAsc() {
        int n = getSize();
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                //    v[j] = v[j + 1]
                //    v[j + 1] = tmp;
                if (getElement(j) > getElement(j + 1)) {  //if (v[j] > v[j + 1])
                    int tmp = getElement(j); //    int tmp = v[j];
                    setElement(j, getElement(j + 1));//    v[j] = v[j + 1]
                    setElement(j + 1, tmp);//    v[j + 1] = tmp;
                }
            }
        }
    }
    // 3 
    // Поэлементное про-изведение элементов компонентных 
    // массивов с нечетными номерами
    //DinoBaraClass operator*(DinoBaraClass& _other) {
    //    node* current = this->head;
    //    int index = 0;
    //    while (current) {
    //        int tmp = _other.getElement(index);
    //        current->data = current->data * tmp;
    //        current = current->next;
    //        index++;
    //    }
    //    return *this;
    //}
    // 16
    // Изменение знака минимального элемента 
    // компонентного массива на противоположный
    //DinoBaraClass operator!() {
    //    if (count>1){
    //        cout << endl << "MegaAngelina Sigma!!!" << endl;
    //        int min = this->head->data;
    //        node* current = this->head;
    //        while (current) {
    //            if (current->data < min)
    //                min = current->data;
    //            current = current->next;
    //        }
    //        cout << "Minimalniy element = " << min;
    //        current = this->head;
    //        while (current) {
    //            if (current->data == min)
    //                current->data=(-1)* current->data;
    //            current = current->next;
    //        }
    //    }
    //        return *this;
    //}
    // 2
    // Произведение положительных 
    // элементов компонентного массива
    //float operator*() {
    //    float _multiplication = 1;
    //    if (count > 1) {
    //        cout << endl << "MegaPolina THe BEST!!!" << endl;
    //        node* current = this->head;
    //        while (current) {
    //            if (current->data > 0)
    //                _multiplication *= current->data;
    //            current = current->next;
    //        }
    //    }
    //    return _multiplication;
    //}
    // 5
    // Изменение знака элементов компонентного 
    // массива на противоположный
    DinoBaraClass operator*() {
        node* current = this->head;
        while (current) {
            current->data = current->data * (-1);
            current = current->next;
        }
        return *this;
    }
    //10
    // Поэлементное вычитание элементов 
    // компонентных массивов с нечетными номерами
    DinoBaraClass operator-(int _deductible) {
        cout << endl << endl << "MegaNastya THE BEST!";
        node* current = this->head;
        int index = 0;
        while (current) {
            if (index % 2 == 1) // нечетный элемент
                current->data = current->data - _deductible;
            current = current->next;
            index++;
        }
        return *this;
    }
    //20
    // Изменение знака элементов 
    // компонентного массива с нечетными 
    // номерами на противоположный
    //DinoBaraClass operator!() {
    //    cout << endl << endl << "MegaSashen'ka mili!";
    //    node* current = head;
    //    int index = 0;
    //    while (current) {
    //        if (index % 2 == 1) // нечетный элемент
    //            current->data = current->data *(-1);
    //        current = current->next;
    //        index++;
    //    }
    //    return *this;
    //}
    // 9
    DinoBaraClass operator++(int) {
        cout << "megaAlisa Alpha the BEST";
        node* curent = head;
        int index = 0;
        while (curent) {
            if (index % 2 == 1)
                curent->data = curent->data + 1;
            curent = curent->next;
            index++;
        }
        return *this;
    }
    // 13
    // Изменение знака элементов компонентного 
    // массива с нечетными номерами на противоположный
    DinoBaraClass operator!() {
        cout << "megaVarvara topchik i mili$)";
        node* curent = head;
        int index = 0;
        while (curent) {
            if (index % 2 == 1)
                curent->data = curent->data *(- 1);
            curent = curent->next;
            index++;
        }
        return *this;
    }



    //16
    friend void operator/(DinoBaraClass& _other, int num);
    //2
    friend void operator~(DinoBaraClass& _other);
};


//16
// Целочисленное деление отрицательных 
// элементов компонентного массива на число
 void operator/(DinoBaraClass& _other, int num) {
     node* current = _other.head;
     while (current) {
         current->data /= num;
         current = current->next;
     }
 };
 // 2
 // Изменение порядка следования элементов 
 // компонентного массива на противоположный     
 void operator~(DinoBaraClass& _other) {
     for (int i = 0; i < _other.count / 2; i++) {
         int tmp = _other.getElement(i);
         _other.setElement(i, _other.getElement(_other.count - i - 1));
         _other.setElement(_other.count - i - 1, tmp);
     }
 };