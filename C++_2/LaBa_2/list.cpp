#include "Header.h"

int main() 
{		
	LIST* list1 = NULL;
	LIST* list2 = NULL;
	LIST* list3 = NULL;
	
	while(ON)
	{
		int choise = mainMenu();
		
		if (choise == 1) list1 = menuList(list1);
		else if (choise == 2) list2 = menuList(list2);
		else if (choise == 3) 
		{
			if (list1 == NULL) cout << "Error (list1 is empty)" << endl;
			else if (list2 == NULL) cout << "Error (list2 is empty)" << endl;
			else
			{
				list3 = (*list1) + (*list2);
				list3->print();
			}
		}
		else if (choise == 4)
		{
			if (list1 != NULL)delete list1;
			if (list2 != NULL)delete list2;
			if (list3 != NULL)delete list3;
			return 0;
		}
		
		system("pause");
		system("cls");
	}
}