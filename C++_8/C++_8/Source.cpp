#include <iostream>
#include <map>

using namespace std;



map<int,int> initMap()
{
    map <int, int>  street;
    int n;

    cout << "������� ���������� ����� �� �����: "; cin >> n;      // ��������� ���������� 
    cout << "������� ��� � ������� � ��� ����� �����: " << endl;  // ����� 

    for (int i = 0; i < n; i++)
    {
        int house, people;
        cout << i << ") ��� ";
        cin >> house; cin >> people;  // ��������� ��������� ��������
        street.insert(make_pair(house, people));
    }
    return street;
}

void deleteHouse(map<int,int>&street)
{
    int deleter;
    cout << "����� ��� �������: ";  cin >> deleter;
    if (street.find(deleter) == street.end())
    {
        cout << "��� ��� � ������, �������� ��� �������� :)";
    }
    else
    {
        street.erase(street.find(deleter));
        cout << "������� ������! " << endl;
    }
}

void printHosesPeople(map<int,int>street)
{
    int house;
    cout << "������� ����� ����: "; cin >> house;
    if (street.count(house))
    {
        cout << "���������� �����: " <<
            street[house] << endl;
    }
    else
    {
        cout << "������ ���� �� ����������! " << endl;
    }


}

void addHouse(map<int,int>&street)
{
    int house, people;
    cout << "����� ��� ��������: "; cin >> house;
    cout << "����� ���������� ����� ��� ���������: "; cin >> people;
    street[house] = people;
}



int main() 
{
    system("chcp 1251");
    map <int, int>  street = initMap(); 


    int amount;
    cout << endl << "������� ���������� ��������: ";
    cin >> amount;

    for (int i = 0; i < amount; i++) 
    {
        cout << i << ") ������� ����� �������� (0 - ������ ���-�� ����� � ���� , 1 - ������� ��� , 2 - �������� ���";
        int choise; cin >> choise;

        if (choise == 0) printHosesPeople(street);
        if (choise == 1) deleteHouse(street);
        if (choise == 2) addHouse(street);
    }

    return 0;
}