#include "Header.h"

int main() 
{
	LIST* list = NULL;
	while(ON)
	{
		int choise = menu();
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
		else if (choise == 4)
		{
			delete list;
			return 0;
		}
		system("pause");
		system("cls");
	}
}