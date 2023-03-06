#ifndef _Job_h
#define _Job_h
#include "Date.h"
#include <string>


class Job
{
#pragma region Feilds
protected:
	string fullName;
	Date birthDay;
	string hometown;
#pragma endregion

public:
#pragma region Constructor
	Job();
	//Job(string; Date, string);
#pragma endregion

#pragma region Properties
	string GetFullName();
	void SetFullName(string);
	Date GetBirthDay();
	void SetBirthDay(Date);
	string GetHomeTown();
	void SetHomeTown(string);
#pragma endregion

#pragma region Method
	virtual void Input();
	virtual void Print();
#pragma endregion

};

#endif

