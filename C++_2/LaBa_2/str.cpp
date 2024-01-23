#include "str.h"

int stringMenu() 
{
	cout << "1)operator '+'" << endl;
	cout << "2)operator '='" << endl;
	cout << "3)operator '+='" << endl;
	cout << "4)operator '=='" << endl;
	cout << "5)operator '!='" << endl;
	cout << "6)operator '[]'" << endl;
	cout << "7)operator '()'" << endl;
	cout << "8)Exit" << endl;
	
	int choise;
	char correct;
	cin >> choise;
	cin.getline(&correct, 1);
	system("cls");
	return choise;
}

int main()
{
	string value;
	
	
	while(ON)
	{
		system("cls");
		int choise = stringMenu();
		cout << "Enter str1" << endl;
		getline(cin, value);
		Str str1(value);
		
		cout << "Enter str2" << endl;
		getline(cin, value);
		Str str2(value);
		
		if (choise == 1)
		{
			cout << "str1 + str2" << endl;
			(str1 + str2).print();
		}
		if (choise == 2)
		{
			str1 = str2;
			cout << "str1 = str2" << endl;
			str1.print();
		}
		if (choise == 3) 
		{
			str1 += str2;
			cout << "str1 += str2" << endl;
			str1.print();
		}
		if (choise == 4) 
		{
			string result;
			if (str1 == str2) result = "Equale";
			else result = "Not equale";
			cout << result << endl;
		}
		if (choise == 5) 
		{
			string result;
			if (str1 != str2) result = "Not equale";
			else result = "equale";
			cout << result << endl;
		}
		if (choise == 6) 
		{
			int index;
			cout << "Enter symvol num" << endl;
			cin >> index;
			str1[index].print();
			str2[index].print();
		}
		if (choise == 7) 
		{
			int num1, num2;
			cout << "Enter start bords" << endl;
			cin >> num1;
			cout << "Enter finish bords" << endl;
			cin >> num2;

			str1(num1, num2).print();
			str2(num1, num2).print();
		}
		if (choise == 8)
		{
			return 0;
		}
		system("pause");
	}
}