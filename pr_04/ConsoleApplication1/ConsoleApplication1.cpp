#include <iostream>

using namespace std;

struct node
{
    int value;
    node* next;
};

static node* head;
static int count;

void print_list(){
	node* curr;
    curr = head;
    while(curr)
	{	
		cout<<curr->value;
		cout<<endl;
		curr=curr->next;
	}
}

int main()
{
    setlocale(LC_ALL, "Russian");

	// Dannie kot vvodim
	int mas[4];
	mas[0] = 0;
	mas[1] = 1;
	mas[2] = 2;
	mas[3] = 3;
	head = NULL;
	count = 0;

	for(int i=0;i<4;i++){
		int value = mas[i];
		if (!head)
		{
			head = new node;
			head->value=value;
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

	int change_value = 2;
	int set_change_value = 3;

	node* curr;
	curr = head;
	while (curr)
	{
		int current_value = curr->value;
		if (current_value == change_value) {
			curr->value = set_change_value;
		}
		curr = curr->next;
	}


	print_list();
}
