////#in	void push(T value)
//{
//	string intStr("int");
//
//	TNode<T>* prev = current->prev;
//	TNode<T>* point = current;
//	int check = 1;
//
//	if (typeid(value).name() == intStr)
//	{
//		while (check)
//		{
//			if (point->data >= value)
//			{
//				if (point->right != nullptr)
//				{
//					prev = point;
//					point = point->right;
//				}
//				else
//				{
//					TNode<T>* newNode = new TNode<T>(value, point->deep, prev);
//					point->right = newNode;
//					check = 0;
//				}
//			}
//			if (point->data < value)
//			{
//				if (point->left != nullptr)
//				{
//					prev = point;
//					point = point->left;
//				}
//				else
//				{
//					TNode<T>* newNode = new TNode<T>(value, point->deep, prev);
//					point->left = newNode;
//					check = 0;
//				}
//			}
//		}
//	}
//	else
//	{
//		while (check)
//		{
//			if (point->data >= value)
//			{
//				if (point->right != nullptr)
//				{
//					prev = point;
//					point = point->left;
//				}
//				else
//				{
//					TNode<T>* newNode = new TNode<T>(value, point->deep, prev);
//					point->right = newNode;
//					check = 0;
//				}
//			}
//			if (point->data < value)
//			{
//				if (point->left != nullptr)
//				{
//					prev = point;
//					point = point->left;
//				}
//				else
//				{
//					TNode<T>* newNode = new TNode<T>(value, point->deep, prev);
//					point->left = newNode;
//					check = 0;
//				}
//			}
//		}
//	}
//	}