#pragma once
#include <iostream>
#include <windows.h>
#include <stdio.h>

using namespace std;

struct node {
public:
    int data;
    node* next;
};

class DinoBaraClass
{
public:
    DinoBaraClass() {
        head=nullptr;
        count=0;
    };
    void Add(int element) {
        node* tPoint = head;
        head = new node;
        if (count == 0) {
            head->data = element;
            head->next = nullptr;
            
        }
        else {
            head->next = tPoint;
            head->data = element;
        }
        count++;
    };
    void Edit(int pos);
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
                    }
                    current = current->next;
                    ind++;
                }
            }
        return element;
    }
    void del(int pos);
    void display() {
        node* current = head;
        cout << endl << "__Display";
        while (current) {
            cout << endl << current->data;
            current = current->next;
        }
    }
private:
    node* head;
    int count;
};

