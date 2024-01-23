#include <iostream>
#include <string>
#define ON 1
using namespace std;

int menu();
class Node {
public:

	~Node() { cout << "Node containing " << this->value << " deleted \n"; }

	string value = "";
	Node* next;
};

class LIST {
	Node* head;
public:

	LIST(string value);

	~LIST();

	void add(string value);

	void del(string value);

	void print();

	void findList(string value);

	void free();
};