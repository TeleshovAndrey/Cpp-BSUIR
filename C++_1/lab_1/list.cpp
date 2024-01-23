#include "Header.h"

LIST:: LIST(string value)
{
	head = new Node;
	head->value = value;
	head->next = NULL;
}

LIST:: ~LIST()
{
	this->free();
	cout << "List deleted \n";
}

void LIST:: add(string value){
	Node* point = head;

	while (point != NULL)
	{
		if (point->next == NULL)
		{
			point->next = new Node;
			point->next->value = value;
			point->next->next = NULL;
			return;
		}
		else point = point->next;
	}
}

void LIST:: del(string value)
{
	Node* point = head;
	Node* prev = NULL;
	while (point != NULL)
	{
		if (point->value == value)
		{
			if (prev == NULL)
			{
				head = point->next;
				delete point;
			}
			else
			{
				prev->next = point->next;
				delete point;
			}
			return;
		}
		prev = point;
		point = point->next;
	}
}


void LIST:: print()
{
	Node* point = head;

	while (point != NULL)
	{
		cout << point->value << " ";
		point = point->next;
	}
	cout << endl;
}

void LIST:: findList(string value)
{
	Node* point = head;

	while (point != NULL)
	{
		if (point->value == value)
		{
			cout << "Item found\n";
			return;
		}
		point = point->next;
	}
	cout << "Element not found\n";
}

void LIST:: free()
{
	Node* point = head;
	Node* prev = NULL;

	if (point != NULL)
	{
		while (point->next != NULL)
		{
			if (point->next != NULL) prev = point;
			point = point->next;
		}
		if (prev != NULL)
		{
			prev->next = NULL;
			delete point;
		}
		else
		{
			delete point;
			head = NULL;
		}
		this->free();
	}
}

int menu()
{
	int choise;
	cout << "Choise number\n";
	cout << "0) Find element\n";
	cout << "1) Print list \n";
	cout << "2) Add list \n";
	cout << "3) Delete list \n";
	cout << "4) exit\n";
	cin >> choise;
	system("cls");
	return choise;
}