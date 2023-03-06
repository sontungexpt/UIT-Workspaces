#include "Staff.h"

Staff::Staff()
{
	fullName = "";
	birthDay = { 1,1,1 };
	wage = 0;
}

int Staff::GetWage()
{
	return wage;
}
istream& operator >> (istream& is, Staff& inValue)
{
	cout << "\nInput full name: ";
	is >> inValue.fullName;
	cout << "Input birthday: ";
	is >> inValue.birthDay; 
	return is;
}
ostream& operator << (ostream& os, Staff& outValue)
{
	os << "\nFull name: " << outValue.fullName;
	os << "\nBirthday: " << outValue.birthDay;
	return os;
}

void Staff::Print()
{
	return;
}