#ifndef _ManagerStaff_h
#define _ManagerStaff_h
#include "Staff.h"
#include <iostream>
using namespace std;

class ManagerStaff:public Staff
{
private:
	int positionCoefficient;
	int reward;

public:
#pragma region Constructor
	ManagerStaff(int, int);
#pragma endregion


#pragma region Method
	void CalcWage();
	//virtual ManagerStaff* FindStaff();
	void Input();
	void Print();
#pragma endregion

	
};

#endif // !_ManagerStaff_h



