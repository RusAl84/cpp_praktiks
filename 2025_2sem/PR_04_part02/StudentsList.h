#pragma once
#include "initial_data.h"
struct node {
    struct Student *data;
    struct node* next;
};

class StudentsList	// ����� "�������� ����������� ������
{
	Node* first;	// ��������� �� ������ ���� ������
	Node* last;	// ��������� �� ��������� ���� ������
public:
	StudentsList();	// �������� ������������
	// ������ � �������, ����������� ����������� ����� �������
    struct node* myHead;
    int countItem = 0;

    //������������ ��� ���������� � �������� ��������� � ����������� ������.
    //https://www.cs.usfca.edu/~galles/visualization/StackLL.html

    /// <summary>
    /// ��������� ������� � ������.
    /// </summary>
    /// <param name="data"> ������ ��������</param>
    void addItem(struct Student *data)
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
    /// <summary>
    /// ������� �������� � ������
    /// </summary>
    /// <param name="index">������ ����� �������� ��������</param>
    /// <param name="data">�������� ������� ���������� ��������</param>
    void insertItem(int index, struct Student* data) {
        if (not (index >= 0 and index <= countItem and countItem >= 0))
            return;
        if (index == 0)
            addItem(data);
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
    void editItem(int index, struct Student* data) {
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
            cout << current->data->first_name << endl;
            current = current->next;
        }
    }

    /// <summary>
    /// ��������� � ����
    /// </summary>
    void saveData() {
        struct Student* st = new Student();
        struct indexStud* indS = new indexStud();
        struct Grade* grades = new Grade();
        struct node* current = myHead;
        int numStud = 0;
        FILE* studTextFile;
        fopen_s(&studTextFile, "studTextFile.txt", "w+");
        FILE* indexStudTextFile;
        fopen_s(&indexStudTextFile, "indexStudTextFile.txt", "w+");
        FILE* gradesTextFile;
        fopen_s(&gradesTextFile, "gradesTextFile.txt", "w+");
        while (current) {
            //cout << current->data->first_name << endl;
            fprintf(studTextFile, "%s\n%s\n%s\n%s\n", \
                current->data->number.c_str(), \
                current->data->first_name.c_str(), \
                current->data->birth_day.c_str(), \
                current->data->group.c_str() \
               );
            numStud++;
            int countGrade= current->data->results.size();
            string sNumStud=to_string(numStud); //https://www.geeksforgeeks.org/converting-number-to-string-in-cpp/
            string sCountGrade =to_string(countGrade);
            fprintf(indexStudTextFile, "%s\n%s\n", \
                sNumStud.c_str(), \
                sCountGrade.c_str() \
            ); 

            for (int i = 0; i < countGrade; i++) {
                string sMark = to_string(current->data->results[i].mark);
                fprintf(gradesTextFile, "%s\n%s\n%s\n", \
                    current->data->results[i].subject.c_str(), \
                    current->data->results[i].date.c_str(), \
                    sMark.c_str() \
                );
            }
            current = current->next;
        }
        fclose(studTextFile);
        fclose(indexStudTextFile);
        fclose(gradesTextFile);

    }
};

