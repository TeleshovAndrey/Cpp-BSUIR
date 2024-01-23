#include <iostream>
#include <string>
#define ON 1
using namespace std;

class Str {
	char* value = NULL;
	int size;
public:
	Str(string data);

	~Str();

	char* getStr();

	int getSize();

	void print();

	void operator=(Str& str);

	Str operator+(Str& str);

	void operator+=(Str& str);

	bool operator==(Str& str);

	bool operator!=(Str& str);

	Str operator[] (int& num);

	Str operator()(int num1, int num2);
};
