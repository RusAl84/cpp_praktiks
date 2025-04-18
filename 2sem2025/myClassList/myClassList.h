#pragma once
#include <iostream>

using namespace std;

/// <summary>
/// ��������� ���� ������������� ������
/// </summary>
struct node {
    int data;
    struct node* next;
};

//������������ ��� ���������� � �������� ��������� � ����������� ������.
//https://www.cs.usfca.edu/~galles/visualization/StackLL.html

class myClassList
{
private:
    struct node* myHead;
    int countItem = 0;
public:
    /// <summary>
    /// ��������� ������� � ������.
    /// </summary>
    /// <param name="data"> ������ ��������</param>
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
/// ������� �������� � ������
/// </summary>
/// <param name="index">������ ����� �������� ��������</param>
/// <param name="data">�������� ������� ���������� ��������</param>
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
    /// �������� ������� ������
    /// </summary>
    /// <param name="index">������ ����������� ��������</param>
    /// <param name="data">�������� �� ������� ����� ��������</param>
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
            cout << endl << "������ ������ �� � ���������";
        }
    }
    /// <summary>
    /// ������� ��� �������� �������� �� ������������� ������
    /// </summary>
    /// <param name="index">������ ���������� ��������</param>
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
    /// ������ ������
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
    /// �������� ���������� ���������
    /// </summary>
    /// <returns>���������� ���������</returns>
    int getCountItem() {
        return countItem;
    }
};

