#ifndef _Staff_h
#define _Staff_h
#include <iostream>
#include <string>
#include "Date.h"
using namespace std;

class Staff
{
protected:
	string fullName;
	Date birthDay;
	int wage;

public:
#pragma region Constructor
	Staff();
#pragma endregion

	int GetWage();
	friend  istream& operator >> (istream&, Staff&);
	friend  ostream& operator << (ostream&, Staff&);
	virtual void Print();

};

#endif


