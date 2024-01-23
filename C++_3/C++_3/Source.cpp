#include "Header.h"
#include <ctime>
#include <Windows.h>
#include "exeptions.h"
#define MATERIALS_MAX_LENGTH 15
#define BRAND_MAX_LENGTH 15
#define MATERIALS_MAX_LENGTH 15

Clock createClock()
{
	int hours, minutes, seconds;
	cout << "Input hours, minutes, seconds" << endl;
	hours = inputInt();
	minutes = inputInt();
	seconds = inputInt();
	Time time(hours, minutes, seconds);
	char material[MATERIALS_MAX_LENGTH];
	char brand[BRAND_MAX_LENGTH];
	cout << "Enter material clock" << endl;
	inputCharArray(material, MATERIALS_MAX_LENGTH);
	cout << "Enter brand clock" << endl;
	inputCharArray(brand, BRAND_MAX_LENGTH);
	bool pendulum, selfWinding;
	cout << "This clock have pendulum" << endl;
	pendulum = inputBool();
	cout << "This clock have self-winding" << endl;
	selfWinding = inputBool();
	Clock clock1(pendulum, selfWinding, material, brand, time);
	system("cls");
	return clock1;
}

int menu()
{
	cout << "1)Print data" << endl;
	cout << "2)Change time" << endl;
	cout << "3)Change distance" << endl;
	cout << "4)Change self-winding" << endl;
	cout << "5)Change pendulum" << endl;
	cout << "6)Change battery charge" << endl;
	cout << "7)Change body material" << endl;
	cout << "8)Change brand" << endl;
	cout << "9)Exit" << endl;
	int choise;
	choise = inputInt();
	system("cls");
	return choise;
}

int main() 
{
	system("chcp 1251");
	try {
		Clock clockItem = createClock();
		int start = clock();
		while (1)
		{
			int choise = menu();
			int end = clock();

			if (choise == 1)
			{
				int seconds = (end - start) / CLOCKS_PER_SEC;
				start = clock();
				clockItem.print(seconds);
			}
			else if (choise == 2)
			{
				int hours, minutes, seconds;
				cout << "Input hours, minutes, seconds" << endl;
				cin >> hours;
				cin >> minutes;
				cin >> seconds;
				Time newTime = Time(hours, minutes, seconds);
				clockItem.setTime(newTime);
			}
			else if (choise == 3)
			{

				int c;
				cout << "1)Change all" << endl;
				cout << "2)Change one distance" << endl;
				cin >> c;
				if (c == 1)
				{
					int newDistance[7];
					for (int i = 0; i < 7; i++)
					{
						cout << "Enter new distance " << i << " day" << endl;
						cin >> newDistance[i];
					}

					clockItem.setDistance(newDistance);
				}
				else if (c == 2)
				{
					int value;
					int num;
					cout << "Enter num" << endl;
					cin >> num;
					cout << "Enter value" << endl;
					cin >> value;
					clockItem.setDistance(value, num);
				}
			}
			else if (choise == 4)
			{
				bool c;
				cout << "Do the watches have a self-winding mechanism? (1-True 2-False)" << endl;
				cin >> c;
				clockItem.setStatus(c);
			}
			else if (choise == 5)
			{
				bool c;
				cout << "Do the watches have a pendulum mechanism? (1-True 2-False)" << endl;
				cin >> c;
				clockItem.setPendulum(c);
			}
			else if (choise == 6)
			{
				int battery;
				cout << "how much charge does a new battery have?" << endl;;
				cin >> battery;
				clockItem.setBattery(battery);
			}
			else if (choise == 7)
			{
				string material;
				cout << "Enter material" << endl;;
				cin >> material;
				clockItem.setBody(material.c_str());
			}
			else if (choise == 8)
			{
				string brand;
				cout << "Enter brand" << endl;;
				cin >> brand;
				clockItem.setBody(brand.c_str());
			}
			else if (choise == 9)
			{
				return 0;
			}

			system("pause");
			system("cls");
		}
	}
	catch(Exception &e)
	{
		e.show();
		exit(-1);
	}
	catch(...)
	{
		cout << "Time entered incorrectly" << endl;
		exit(-1);
	}
}
