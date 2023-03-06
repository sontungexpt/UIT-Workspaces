#ifndef _Time_h
#define _Time_h
#include <iostream>
#include <math.h>
using namespace std;

class Time
{
#pragma region Feilds
private:
	int hour;
	int minute;
	int second;

#pragma endregion

public:
#pragma region Constructor
	Time();
	Time(int, int, int);
	Time(const Time&);
#pragma endregion

#pragma region Destructor
	~Time();

#pragma endregion

#pragma region Properties
	int GetHour();
	void SetHour(int);
	int GetMinute();
	void SetMinute(int);
	int GetSecond();
	void SetSecond(int);
#pragma endregion


#pragma region Method
	void Input();
	friend istream& operator >> (istream&, Time&);
	void Print();
	friend ostream& operator << (ostream&, Time&);
	bool IsInvalidTime();
	Time FindNextTime();
	Time FindPreviousTime();
	int NumberOfSecond();
	int Distance(Time);
	int Compare(Time);
#pragma endregion

	//method
	
};
#endif

