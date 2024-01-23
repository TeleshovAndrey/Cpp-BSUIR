#include "Header.h"
#include "str.h"

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

void LIST:: add(string value)
{
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

void LIST:: print(int startPos, int finishPos)
{
	int count = 0;
	Node* point = head;

	while (point != NULL && count <= finishPos)
	{
		if (count >= startPos) cout << point->value << " ";
		point = point->next;
		count++;
	}
	if (count <= startPos) cout << "There is no such boundary";
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

LIST* LIST:: operator+(LIST& list)
{
	Node* point = this->head;
	LIST* newList = NULL;
	string value;

	while (point != NULL)
	{
		value = point->value;
		if (newList == NULL) newList = new LIST(value);
		else newList->add(value);
		point = point->next;
	}
	point = list.head;

	while (point != NULL)
	{
		value = point->value;
		newList->add(value);
		point = point->next;
	}

	return newList;
}

int mainMenu()
{
	int choise;
	cout << "1) List1 " << endl;
	cout << "2) List2 " << endl;
	cout << "3) Create List3 (List1 + List2)" << endl;
	cout << "4) exit" << endl;
	cin >> choise;
	system("cls");
	return choise;
}

LIST* menuList(LIST* list)
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

	if (choise == 0)
	{
		string data;
		cout << "Enter element\n";
		cin >> data;

		list->findList(data);
	}
	else if (choise == 1) list->print();
	else if (choise == 2)
	{
		string data;
		cout << "Enter data\n";
		cin >> data;

		if (list != NULL) list->add(data);
		else list = new LIST(data);
	}
	else if (choise == 3)
	{
		string data;
		cout << "Enter item for delete\n";
		cin >> data;

		list->del(data);
	}
	else if (choise == 4) return list;
	system("pause");
	system("cls");
	list = menuList(list);
}

//----------------------------------------------------------------

Str Str:: operator()(int num1, int num2)
{
	char buffer[255];

	int point1 = num1;
	int point2 = 0;

	while (value[point1] != '\0')
	{
		buffer[point2] = value[point1];
		point1++;
		point2++;
	}
	buffer[point2] = '\0';
	string str(buffer);
	Str result(str);
	return result;
}

Str Str:: operator[] (int& num)
{
	if (num >= 0 && num < size) {
		char result[2];
		result[0] = value[num];
		result[1] = '\0';
		string buffer(result);
		Str res(buffer);
		return res;
	}
	else
	{
		int pos;
		int correct;
		if (num < 0)
		{
			pos = 0 - num - 1;

			while (pos < 0 && pos >= size)
			{
				correct = pos - size + 1;
			}
		}
		if (num >= size)
		{
			pos = size - 1;
		}
	}
}

bool Str:: operator!=(Str& str)
{
	if (strcmp(value, str.getStr()) == 0)
		return 0;
	else
		return 1;
}

bool Str:: operator==(Str& str)
{
	if (strcmp(value, str.getStr()) == 0)
		return 1;
	else
		return 0;
}

void Str:: operator+=(Str& str)
{
	string buffer(value);
	delete value;
	int length = str.getSize() + size - 1;
	value = new char[length];
	strcpy_s(value, size, buffer.c_str());
	strcat_s(value, length, str.getStr());
}

Str Str:: operator+(Str& str)
{
	string str1(value);
	string str2(str.getStr());
	Str newStr(str1 + str2);
	return newStr;
}

void Str:: operator=(Str& str)
{
	delete value;

	int length = str.getSize();

	value = new char[length];
	strcpy_s(value, length, str.getStr());
}

void Str:: print()
{
	string buffer(value);
	cout << buffer << endl;
}

int Str:: getSize()
{
	return size;
}

char* Str:: getStr()
{
	return value;
}

Str:: ~Str()
{
	cout << "MEMORY FREE" << endl;
	delete value;
}

Str:: Str(string data)
{
	int length = data.size() + 1;
	value = new char[length];
	size = length;
	strcpy_s(value, length, data.c_str());
}