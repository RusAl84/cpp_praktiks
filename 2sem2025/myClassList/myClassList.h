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
        newItem->next = myHead;

        countItem++;
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
};

