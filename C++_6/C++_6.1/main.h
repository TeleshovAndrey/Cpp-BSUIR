#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;



//clock.cpp -------------------------------------
class Time
{
	int hours = 0;
	int minutes = 0;
	int seconds = 0;
public:
	Time();
	Time(int newHours, int newMinutes, int newSeconds);
	void print(int sec);
};

class FitnessTracker
{
protected:
	int distanceTraveled[7] = { 0 };
public:
	FitnessTracker();
	int* getDistance();
	void setDistance(int* newDistance);
	void setDistance(int value, int num);
};


class Watch
{
protected:
	bool selfWinding = 0;
public:
	Watch(bool num1);
	Watch();
	bool getStatus();
	void setStatus(bool num1);
};


class WallClock
{
protected:
	bool pendulum = 0;
public:
	WallClock(bool available);
	WallClock();
	bool getPendulum();
	void setPendulum(bool available);
};


class Electronic : public FitnessTracker
{
protected:
	int batteryCharge;
public:
	Electronic();
	int getBattery();
	void setBattery(int newBattery);
};

class Mechanic : public WallClock, public Watch
{
protected:
	char bodyMaterial[50];
public:
	Mechanic(bool num2, bool num1, const char* material);
	Mechanic();
	char* getBody();
	void setBody(const char* str);
};

class Clock : public Mechanic, public Electronic
{
	char brand[50];
	Time time;
public:
	Clock(bool available1, bool available2, const char* material, const char* brand, Time time);
	Clock();
	~Clock();
	char* getBrand();
	void setBrand(char* newBrand);
	Time getTime();
	void setTime(Time newTime);
	void print(int sec);
	bool operator > (Clock& clock) const
	{
		int thisLength = strlen(this->brand);
		int clockLength = strlen(clock.getBrand());

		return thisLength > clockLength;
	}
	friend ostream& operator<<(ostream& os, const Clock& clk)
	{
		os << clk.brand  << " " << clk.bodyMaterial << " " << clk.pendulum << endl;
		return os;
	}
	
};

//-------------------------------------------------


//tree.cpp ----------------------------------------
template<typename T>
class TNode
{
public:
	T data;
	TNode* left;
	TNode* right;

	TNode(T value);
	~TNode();
};


template <typename T>
class TTree
{
	TNode<T>* head;
public:
	TTree();
	~TTree();
	void push(T value);
	void pop(T value);
	bool search(T value);
	void print();
	TNode<T>* getHead();
private:
	TNode<T>* searchRec(T value, TNode<T>* point);
	TNode<T>* pushRec(T value, TNode<T>* point);
	void printRec(TNode<T>* point);
	TNode<T>* popRec(T value, TNode<T>* point);
};

//-------------------------------------------------------

//file.cpp ----------------------------------

void writeToTextFile(TTree<Clock>* tree, const std::string& filename);
void readFromTextFile(TTree<Clock>* tree, const std::string& filename);
void writeToBin(TTree<Clock>* tree, const std::string& filename);
void readFromBinFile(TTree<Clock>* tree, const std::string& filename);

//-----------------------------------------------

template <typename T>
TTree<T>::TTree()
{
	head = nullptr;
}
template <typename T>
TTree<T>:: ~TTree()
{
	delete head;
	cout << "Tree deleted";
}
template <typename T>
void TTree<T> ::push(T value)
{
	head = pushRec(value, head);
}
template <typename T>
void TTree<T> ::pop(T value)
{
	head = popRec(value, head);
}
template <typename T>
bool TTree<T>::search(T value)
{
	if (searchRec(value, head) == nullptr) return 0;
	return 1;
}
template <typename T>
void TTree<T>::print()
{
	printRec(head);
}

template <typename T>
TNode<T>* TTree<T>::searchRec(T value, TNode<T>* point)
{
	if (point != nullptr)
	{
		TNode<T>* buffer;
		if (point->data == value) return point;
		if (point->data > value) buffer = searchRec(value, point->left);
		else buffer = searchRec(value, point->right);
	}
	return nullptr;
}
template <typename T>
TNode<T>* TTree<T> ::pushRec(T value, TNode<T>* point)
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
template <typename T>
void TTree<T> ::printRec(TNode<T>* point)
{
	if (point != nullptr)
	{
		cout << point->data << endl;
		printRec(point->left);
		printRec(point->right);
	}
}
template <typename T>
TNode<T>* TTree<T>::popRec(T value, TNode<T>* point)
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

template <typename T>
TNode<T> ::TNode(T value)
{
	data = value;
	left = nullptr;
	right = nullptr;
}
template <typename T>
TNode<T> ::~TNode()
{

	cout << "TNode :" << data << "deleted" << endl;
	if (this->left != nullptr) delete this->left;
	if (this->right != nullptr) delete this->right;
}

template <typename T>
TNode<T>* TTree<T> ::getHead()
{
	return head;
}