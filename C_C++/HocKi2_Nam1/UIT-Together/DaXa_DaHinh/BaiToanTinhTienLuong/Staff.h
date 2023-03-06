#ifndef _Staff_h
#define _Staff_h
#include <iostream>
#include <string>
#include "CNgay.h"

using namespace std;

class Staff
{
protected:
	int wage;
	int basicWage;
	string fullName;
	Date birthDay;

public:
	
#pragma region Constructor
	Staff();
	Staff(string, Date, int );
	Staff(const Staff&);
	
#pragma endregion

#pragma region Properties
	virtual int GetWage();
	virtual void SetWage(int);
#pragma endregion
	
#pragma region Method

	virtual void CalcWage();
	//virtual Staff* FindStaff();
	virtual void Input();
	virtual void Print();
#pragma endregion



};
#endif

