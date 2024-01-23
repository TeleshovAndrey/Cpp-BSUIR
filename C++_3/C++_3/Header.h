#include <iostream>
#include <string>

using namespace std;

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
	int distanceTraveled[7] = {0};
public:
	FitnessTracker();
	int* getDistance();
	void setDistance(int* newDistance);
	void setDistance(int value, int num);
	void statistics();
};


class Watch 
{
protected:
	bool selfWinding = 0;
public:
	Watch(bool num1);
	bool getStatus();
	void setStatus(bool num1);
};


class WallClock 
{
protected:
	bool pendulum = 0;
public:
	WallClock(bool available);
	bool getPendulum();
	void setPendulum(bool available);
};


class Electronic: public FitnessTracker
{
protected:
	int batteryCharge;
public:
	Electronic();
	int getBattery();
	void setBattery(int newBattery);
};

class Mechanic: public WallClock, public Watch 
{
protected:
	char bodyMaterial[50];
public:
	Mechanic(bool num2, bool num1, const char* material);
	char* getBody();
	void setBody(const char* str);
};

class Clock: public Mechanic, public Electronic 
{
	char brand[50];
	Time time;
public:
	Clock(bool available1, bool available2, const char* material, const char* brand, Time time);
	~Clock();
	char* getBrand();
	void setBrand(char* newBrand);
	Time getTime();
	void setTime(Time newTime);
	void print(int sec);
};

void inputCharArray(char* str, int maxLength);
int inputInt();
bool inputBool();
