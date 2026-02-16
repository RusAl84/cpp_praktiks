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
    };
    void Edit(int pos, int data) {
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
    void Del(int pos) {
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

