#include "Staff.h"

#pragma region Constructor
Staff::Staff()
{
	this->basicWage = 0;
	this->fullName = "";
	this->wage = 0;
}
Staff::Staff(string fullName, Date birthDay, int basicWage)
{
	this->basicWage = 0;
	this->fullName = "";
	this->birthDay = birthDay;
}
Staff::Staff(const Staff& x)
{
	this->basicWage = x.basicWage;
	this->fullName = x.fullName;
	this->wage = x.wage;
	this->birthDay = x.birthDay;
}

#pragma endregion

#pragma region Properties
int Staff::GetWage()
{
	return wage;
}
void Staff::SetWage(int value)
{
	wage = value;
}
#pragma endregion

#pragma region Method

void Staff::CalcWage()
{
	return;
}
Staff* Staff::FindStaff()
{
	return new Staff;
}
void Staff::Input()
{
	return;
}
void Staff::Print()
{
	return;
}
#pragma endregion


