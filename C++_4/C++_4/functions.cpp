#include "Header.h"

template<typename T>
class TNode
{
public:
	T data;
	TNode* left;
	TNode* right;

	TNode(T value)
	{
		data = value;
		left = nullptr;
		right = nullptr;
	}
	~TNode()
	{
		cout << "TNode :" << this->data << "deleted" << endl;
		if (this->left != nullptr) delete this->left;
		if (this->right != nullptr) delete this->right;
	}
};

template <typename T>
class TTree
{
	TNode<T>* head;
public:
	TTree()
	{
		head = nullptr;
	}

	~TTree()
	{
		delete head;
		cout << "Tree deleted";
	}
	
	void push(T value)
	{
		head = pushRec(value, head);
	}

	void pop(T value)
	{
		head = popRec(value,head);
	}

	bool search(T value)
	{
		if (searchRec(value, head) == nullptr) return 0;
		return 1;
	}

	void print()
	{
		printRec(head);
	}

private:
	TNode<T>* searchRec(T value, TNode<T>* point)
	{
		if (point != nullptr) 
		{
			TNode<T>* buffer;
			if(point->data == value) return point;
			if (point->data > value) buffer = searchRec(value, point->left);
			else buffer = searchRec(value, point->right);
		}
		return nullptr;
	}

	TNode<T>* pushRec(T value, TNode<T>* point)
	{
		if (point != nullptr)
		{
			if (point->data > value) point->left = pushRec(value, point->left);
			else point->right = pushRec(value, point->right);
			return point;
		}
		TNode<T>* newEll = new TNode<T>(value);
		return newEll;
	}

	void printRec (TNode<T>*point)
	{
		if (point != nullptr)
		{
			cout << point->data << endl;
			printRec(point->left);
			printRec(point->right);
		}
	}

	TNode<T>* popRec(T value,TNode<T>* point)
	{
		if (point != nullptr)
		{
			if (value == point->data) 
			{
				delete point;
				return nullptr;
			}
			else if (value < point->data) point->left = popRec(value, point->left);
			else point->right = popRec(value, point->right);
			return point;
		}
	}
};

int typeMenu()
{
	cout << "1)Int" << endl
		<< "2)String" << endl;
	int choise;
	cin >> choise;

	return choise;
}


int treeMenu()
{
	
	cout << "1)push tree" << endl
		<< "2) pop tree" << endl
		<< "3) print tree" << endl
		<< "4) search tree" << endl
		<< "5) end" << endl;
	int choise;
	cin >> choise;
	return choise;

}


template<typename T>
void mainMenu()
{
	TTree<T>* tree = new TTree<T>();
	while (1)
	{
		int choise = treeMenu();
		if (choise == 1)
		{
			T number;
			cin >> number;
			tree->push(number);
		}
		else if (choise == 2)
		{
			T number;
			cin >> number;
			tree->pop(number);
		}
		else if (choise == 3)
		{
			tree->print();
		}
		else if (choise == 4)
		{
			T number;
			cin >> number;
			if (tree->search(number)) cout << "True" << endl;
			else cout << "False" << endl;
		}
		else if (choise == 5)
		{
			delete tree;
			return;
		}

		system("pause");
		system("cls");
	}
}


int main()
{
	int choiseType = typeMenu();
	if (choiseType == 1) mainMenu<int>();
	if (choiseType == 2) mainMenu<string>();
}