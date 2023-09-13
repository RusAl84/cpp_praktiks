#include <iostream>

using namespace std;
struct node {
    int data;
    struct node* next;
};
struct node* myHead;
int countItem = 0;

void addItem(int data) {
    struct node* newItem = new node();
    newItem->data = data;
    if (countItem == 0) {
        newItem->next = NULL;    
    }
    else
    {
        newItem->next = myHead;
    }
    myHead = newItem;
    countItem++;
}

void editItem(int index, int data) {
    if (index >= 0 and index < countItem) {
        struct node* current = myHead;
        for (int i = 0; i < index;  i++) {
            current = current->next;
            //cout << "+" << current->data;
        }
        current->data = data;
    }
    else {
        cout << "Ошибка индекс не в диапазоне";
    }

}

void printMyList() {
    struct node* current = myHead;
    cout << endl;
    while (current) {
        cout << " " << current->data;
        current = current->next;
    }
}

int main()
{
    cout << "myList\n";

    addItem(1);
    addItem(2);
    addItem(3);
    addItem(4);
    printMyList();
    editItem(2, 8);
    printMyList();
}