#include <iostream>
#include <map>

using namespace std;



map<int,int> initMap()
{
    map <int, int>  street;
    int n;

    cout << "Введите количество домов на улице: "; cin >> n;      // считываем количество 
    cout << "Укажите дом и сколько в нем живет людей: " << endl;  // домов 

    for (int i = 0; i < n; i++)
    {
        int house, people;
        cout << i << ") Дом ";
        cin >> house; cin >> people;  // считываем введенные значения
        street.insert(make_pair(house, people));
    }
    return street;
}

void deleteHouse(map<int,int>&street)
{
    int deleter;
    cout << "Какой дом удалить: ";  cin >> deleter;
    if (street.find(deleter) == street.end())
    {
        cout << "Его нет в списке, возможно уже разрушен :)";
    }
    else
    {
        street.erase(street.find(deleter));
        cout << "Элемент удален! " << endl;
    }
}

void printHosesPeople(map<int,int>street)
{
    int house;
    cout << "Укажите номер дома: "; cin >> house;
    if (street.count(house))
    {
        cout << "Количество людей: " <<
            street[house] << endl;
    }
    else
    {
        cout << "Такого дома не существует! " << endl;
    }


}

void addHouse(map<int,int>&street)
{
    int house, people;
    cout << "Какой дом добавить: "; cin >> house;
    cout << "Какое количество людей там проживает: "; cin >> people;
    street[house] = people;
}



int main() 
{
    system("chcp 1251");
    map <int, int>  street = initMap(); 


    int amount;
    cout << endl << "Введите количество операций: ";
    cin >> amount;

    for (int i = 0; i < amount; i++) 
    {
        cout << i << ") Введите номер операции (0 - узнать кол-во людей в доме , 1 - удалить дом , 2 - добавить дом";
        int choise; cin >> choise;

        if (choise == 0) printHosesPeople(street);
        if (choise == 1) deleteHouse(street);
        if (choise == 2) addHouse(street);
    }

    return 0;
}