// 2  variant

#include <iostream>

using namespace std;

struct node
{
	int value;
	node* next;
	node* prev;
};

static node* head;
static int count;

int main()
{
	setlocale(LC_ALL, "Russian");

	// Dannie kot vvodim
	float mas[4];
	mas[0] = 0.1;
	mas[1] = 1.1;
	mas[2] = 2.1;
	mas[3] = 3.1;
	head = NULL;


	for (int i = 0; i < 4; i++) {
		int value = mas[i];
		if (!head)
		{
			head = new node;
			head->value = value;
			head->next = NULL;
			head->prev = NULL;

		}
		else
		{
			node* tmp = new node;
			tmp->value = value;
			tmp->next = head;
			tmp->prev = NULL;
			head = tmp;
			head->next->next->prev = head->next;
		}
	}
    std::cout << "Hello World!\n";
}
