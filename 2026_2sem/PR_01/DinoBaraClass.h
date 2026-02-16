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
    void getElement(int pos);
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

