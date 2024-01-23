#include "Header.h"

//template <typename T>
//class TNode
//{
//public:
//	TNode* left;
//	TNode* right;
//	TNode* prev;
//	T data;
//	int deep;
//	TNode(T value, int newDeep=1, TNode* prevNode = nullptr)  
//	{
//		left = nullptr;
//		right = nullptr;
//		prev = prevNode;
//		deep = newDeep;
//		data = value;
//	}
//	~TNode()
//	{
//		cout << "Node deleted" << endl;
//		if (this->left != nullptr) delete this->left;
//		if (this->right != nullptr) delete this->right;
//	}
//	T getData()
//	{
//		return data;
//	}
//};
//
//template <class T>
//class TTree 
//{
//	TNode<T>* head;
//	TNode<T>* current;
//public:
//	TTree(T value)
//	{
//		current = new TNode<T>(value);
//		head = current;
//	}
//	~TTree()
//	{
//		delete current;
//	}
//	void push(T value)
//	{
//		string intStr("int");
//		
//		TNode<T>* point = current;
//		int check = 1;
//		
//		while (check)
//		{
//			if (value >= point->data)
//			{
//
//				if (point->right != nullptr) point = point->right;
//				else 
//				{
//					check = 0;
//					TNode<T>* newNode = new TNode<T>(value, point->deep+1, point);
//					point->right = newNode;
//				}
//					
//			}
//			else if (value < point->data)
//			{
//				if (point->left != nullptr) point = point->left;
//				else
//				{
//					check = 0;
//					TNode<T>* newNode = new TNode<T>(value, point->deep+1, point);
//					point->left = newNode;
//				}
//			}
//		}
//	}
//
//	void pop(T* value = nullptr)
//	{
//		if (value == nullptr)
//		{
//			TNode<T>* prev = current->prev;
//			if (prev != nullptr)
//			{
//				if (prev->left == current) prev->left = nullptr;
//				else if (prev->right == current) prev->right = nullptr;
//			}
//		}
//		else 
//		{
//			TNode<T>* currentNodes[50];
//			currentNodes[0] = head;
//			int currentCount = 1;
//			int checkExit = 1;
//			while(checkExit)
//			{
//				TNode<T>* nextNodes[50];
//				int nextCount = 0;
//				for(int i=0; i<currentCount;i++)
//				{
//					if(currentNodes[i]->data == (*value))
//					{
//						if (currentNodes[i]->prev == nullptr)
//						{
//							current = nullptr;
//							head = nullptr;
//							delete currentNodes[i];
//						}
//						else
//						{
//							TNode<T>* prev = currentNodes[i]->prev;
//							if (prev->left == currentNodes[i]) prev->left = nullptr;
//							else if (prev->right == currentNodes[i]) prev->right = nullptr;
//							delete currentNodes[i];
//						}
//						return;
//					}
//					else 
//					{
//						if (currentNodes[i]->left != nullptr)
//						{
//							nextNodes[nextCount] = currentNodes[i]->left;
//							nextCount++;
//						}
//						if (currentNodes[i]->right != nullptr)
//						{
//							nextNodes[nextCount] = currentNodes[i]->left;
//							nextCount++;
//						}
//					}
//				}
//				if (nextCount == 0)
//				{
//					checkExit = 0;
//				}
//				else 
//				{
//					for (int i = 0; i < nextCount; i++)
//					{
//						currentNodes[i] = nextNodes[i];
//					}
//					currentCount = nextCount;
//				}
//			}
//		}
//		cout << "This node was not found" << endl;
//	}
//
//
//	void peek()
//	{
//		cout << "Data current item " << current->data << endl;
//	}
//	void print()
//	{
//		if (head != nullptr)
//		{
//			TNode<T>* currentTNode[50];
//			currentTNode[0] = head;
//			int currentCount = 1;
//			int deep = 1;
//			int checkExit = 0;
//			while (checkExit == 0)
//			{
//				TNode<T>* nextTNode[50];
//				int nextCount = 0;
//				for (int i = 0, j =0; i < currentCount; i++)
//				{
//					if (deep == currentTNode[i]->deep)
//					{
//						cout << currentTNode[i]->data << "\t";
//						if (currentTNode[i]->left != nullptr) 
//						{
//							nextTNode[j] = currentTNode[i]->left;
//							nextCount++;
//							j++;
//						}
//						if (currentTNode[i]->right != nullptr)
//						{
//							nextTNode[j] = currentTNode[i]->right;
//							nextCount++;
//							j++;
//						}
//					}
//					else 
//					{
//						nextTNode[j] = currentTNode[i];
//						nextCount++;
//						j++;
//					}
//				}
//				cout << endl;
//				deep++;
//				
//				for (int i = 0; i < nextCount; i++)
//				{
//					currentTNode[i] = nextTNode[i];
//					currentCount = nextCount;
//				}
//				
//				if (nextCount == 0) checkExit = 1;
//			}
//		}
//	}
//	TTree& operator++()
//	{
//		this->current = this->current->right;
//		return *this;
//	}
//	TTree& operator--()
//	{
//		this->current = this->current->left;
//		return *this;
//	}
//	TTree& operator *()
//	{
//		if (current->prev != nullptr) current = current->prev;
//		return *this;
//	}
//
//};
//
//int treeMenu()
//{
//	cout << "1)Print tree" << endl
//		 << "2)Push" << endl
//		 << "3)Pop" << endl
//		 << "4)Peek" << endl
//		 << "5)++" << endl
//		 << "6)--" << endl
//		 << "7)*" << endl
//		 << "8)exit" << endl;
//	
//	int choise;
//	cin >> choise;
//	return choise;
//}
//
//int typeMenu()
//{
//	cout << "What type are you want to use" << endl
//		 << "1)String" << endl
//		 << "2)Integer" << endl;
//	int choise;
//	cin >> choise;
//	system("cls");
//	return choise;
//}
//
//template<typename T>
//void menu()
//{
//	T data;
//	cout << "Enter data" << endl;
//	cin >> data;
//
//	TTree<T> *tree = new TTree<T>(data);
//	
//	while(1)
//	{
//		int choise = treeMenu();
//		if (choise == 1)
//		{
//			tree->print();
//		}
//		else if (choise == 2)
//		{
//			cout << "Enter data" << endl;
//			T data;
//			cin >> data;
//			tree->push(data);
//		}
//		else if (choise == 3)
//		{
//			cout << "1)Delete current ell" << endl;
//			cout << "2)Delete ell to value" << endl;
//			int ch1;
//			cin >> ch1;
//			if (ch1 == 1)
//			{
//				tree->pop();
//			}
//			else if (ch1 == 2)
//			{
//				cout << "Enter the value to be remived" << endl;
//				T value;
//				cin >> value;
//				tree->pop(&value);
//			}
//		}
//		else if (choise == 4)
//		{
//			tree->peek();
//		}
//		else if (choise == 5)
//		{
//			tree++;
//			cout << "The current ellement chifted to the right" << endl;
//		}
//		else if (choise == 6) 
//		{
//			tree--;
//			cout << "The current ellement chifted to the left" << endl;
//		}
//		else if (choise == 7) 
//		{
//			//tree*;
//			cout << "Current element moved up" << endl;
//		}
//		else if (choise == 8)
//		{
//			delete tree;
//			return;
//		}
//		system("pause");
//		system("cls");
//	}
//}
//
//int main() 
//{
//	int choiseType = typeMenu();
//	if (choiseType == 1) menu<string>();
//	else if (choiseType == 2) menu<int>();
//
//}