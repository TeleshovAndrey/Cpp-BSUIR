#include "main.h"

//Time---------------------------------------

Time::Time(int newHours, int newMinutes, int newSeconds)
{
	if (newHours >= 24 || newMinutes >= 60 || newSeconds >= 60 || newHours < 0 || newMinutes < 0 || newSeconds < 0)
		throw Time();
	hours = newHours;
	minutes = newMinutes;
	seconds = newSeconds;
}

Time::Time()
{
	hours = 0;
	minutes = 0;
	seconds = 0;
}

void Time::print(int sec)
{
	cout << hours << ":" << minutes << ":" << seconds << endl;
	seconds = seconds + sec;
	if (seconds >= 60)
	{
		minutes += seconds / 60;
		seconds = seconds % 60;
	}
	if (minutes >= 60)
	{
		hours += minutes / 60;
		minutes = minutes % 60;
	}
	if (hours >= 24)
	{
		hours = hours % 24;
	}
}

//-------------------------------------------


// FitnessTracker-----------------------------------------

FitnessTracker::FitnessTracker()
{
	for (int i = 0; i < 7; i++)
	{
		distanceTraveled[i] = 0;
	}
}

int* FitnessTracker::getDistance()
{
	return distanceTraveled;
}

void FitnessTracker::setDistance(int* newDistance)
{
	for (int i = 0; i < 7; i++)
	{
		distanceTraveled[i] = newDistance[i];
	}
}

void FitnessTracker::setDistance(int value, int num)
{
	distanceTraveled[num] = value;
}

//----------------------------------------------------------

//Watch-----------------------------------------------------

Watch::Watch(bool num1)
{
	selfWinding = num1;
}

Watch::Watch()
{
	selfWinding = 0;
}

bool Watch::getStatus()
{
	return selfWinding;
}

void Watch::setStatus(bool num1)
{
	selfWinding = num1;
}

//---------------------------------------------------------

//WallClock------------------------------------------------

WallClock::WallClock(bool available)
{
	pendulum = available;
}

WallClock::WallClock()
{
	pendulum = 0;
}

bool WallClock::getPendulum()
{
	return pendulum;
}

void WallClock::setPendulum(bool available)
{
	pendulum = available;
}

//---------------------------------------------------------

//Electronic-----------------------------------------------

Electronic::Electronic() : FitnessTracker()
{
	batteryCharge = 100;
}

int Electronic::getBattery()
{
	return batteryCharge;
}

void Electronic::setBattery(int newBattery)
{
	batteryCharge = newBattery;
}

//------------------------------------------------------

//Mechanic----------------------------------------------

Mechanic::Mechanic(bool num2, bool num1, const char* material) : WallClock(num2), Watch(num1)
{
	strcpy_s(bodyMaterial, strlen(material) + 1, material);
}

Mechanic::Mechanic()
{
	const char buffer[] = "";
	strcpy_s(bodyMaterial, strlen(buffer) + 1, buffer);
}

char* Mechanic::getBody()
{
	return bodyMaterial;
}

void Mechanic::setBody(const char* str)
{
	strcpy_s(bodyMaterial, strlen(str) + 1, str);
}

//------------------------------------------------------

//Clock-------------------------------------------------

Clock::Clock(bool available1, bool available2, const char* material, const char* newBrand, Time newTime) : Mechanic(available1, available2, material), Electronic()
{
	strcpy_s(brand, strlen(newBrand) + 1, newBrand);
	time = newTime;
}

Clock:: Clock()
{
	const char buffer[] = "";
	strcpy_s(brand, strlen(buffer) + 1, buffer);
}

Clock:: ~Clock()
{
	//cout << "Clock deleted" << endl;
}

char* Clock::getBrand()
{
	return brand;
}

Time Clock::getTime()
{
	return time;
}

void Clock::setBrand(char* newBrand)
{
	strcpy_s(brand, strlen(newBrand) + 1, newBrand);
}

void Clock::setTime(Time newTime)
{
	time = newTime;
}

void Clock::print(int sec)
{
	string material(bodyMaterial);
	string brandStr(brand);
	time.print(sec);
	cout << "Brand - " << brandStr << endl;
	cout << "Material - " << material << endl;
	cout << "Self-winding - " << selfWinding << endl;
	cout << "Pendulum - " << pendulum << endl;
	cout << batteryCharge << "%" << endl;
	cout << "\nDistance travaled on thr week days" << endl;
	for (int i = 0; i < 7; i++)
	{
		cout << i + 1 << ") " << distanceTraveled[i] << " km" << endl;
	}
}

//------------------------------------------------------