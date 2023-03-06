#ifndef _Staff_h
#define _Staff_h
#include <iostream>
#include <string>
#include "Date.h"
using namespace std;

class Staff
{
private:
	int wage;
	int basicWage;
	string fullName;
	Date birthDay;

public:
	
#pragma region Constructor
	Staff();
	Staff(string, Date , int );
	Staff(const Staff&);
	
#pragma endregion

#pragma region Properties
	int GetWage();
	void SetWage(int value);
#pragma endregion
	
#pragma region Method

	virtual void Input();
	virtual void Print();
	virtual void CalcWage();
	//virtual Staff* FindStaff();
#pragma endregion



};
#endif

