#ifndef _Officer_h
#define _Officer_h
#include "Staff.h"

class Officer:public Staff
{
#pragma region Feilds
private:
	int workDayAmount;

#pragma endregion

#pragma region Method
public:
	Officer();
	void CalcWage();
	friend istream& operator >> (istream&, Officer&);
	friend ostream& operator << (ostream&, Officer&);
	void Print();
#pragma endregion


};



#endif // !Officer
