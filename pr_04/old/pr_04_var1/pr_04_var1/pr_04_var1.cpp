// pr_04_var1.cpp
#include <iostream>
#include <cstring>
using namespace std;

struct node
{
	string value;
    node* next;
};

static node* head;

void print_list() {
	node* curr = head;
	while(curr) {
		cout << curr->value;
		cout << endl;
		curr = curr->next;
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");

	// Dannie kot vvodim
	string mas[4];

	mas[0] = "asperin";
	mas[1] = "vazelin";
	mas[2] = "nikotin";
	mas[3] = "c++";

	head = NULL;

	for (int i = 0; i < 4; i++) {
		string value = mas[i];
		if (!head)
		{
			head = new node;
			head->value = value;
			head->next = NULL;
		}
		else
		{
			node* tmp = new node;
			tmp->value = value;
			tmp->next = head;
			head = tmp;
		}
	}


	print_list();

	string compare_value = "vazelin";
	string set_value = "assembler";

	node* curr = head;
	while (curr) {
		if (compare_value.compare(curr->value)==0) {
			//cout << curr->value;
			//cout << endl;
			curr->value = set_value;
		}
		curr = curr->next;
	}
	cout << endl;
	print_list();

}

