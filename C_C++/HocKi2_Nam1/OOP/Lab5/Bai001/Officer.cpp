#include "Officer.h"

Officer::Officer()
{
	workDayAmount = 0;
}

void Officer::CalcWage()
{
	wage =  workDayAmount * 100000;
}

istream& operator >> (istream& is, Officer& inValue)
{
	cin.ignore();
	cout << "\nInput full name: ";
	getline(is,inValue.fullName);
	cout << "Input birthday: ";
	is >> inValue.birthDay;
	cout << "Input amount of work day: ";
	is >> inValue.workDayAmount;
	return is;
}
ostream& operator << (ostream& os, Officer& outValue)
{
	os << "\nFull name: "<<outValue.fullName;
	os << "\nBirthday: "<<outValue.birthDay;
	os << "\nAmount of work day: "<<outValue.workDayAmount;
	os << "\nWage: " << outValue.wage;
	return os;
}
void Officer::Print()
{
	cout << "\nFull name: " << fullName;
	cout << "\nBirthday: " << birthDay;
	cout << "\nAmount of work day: " << workDayAmount;
	cout << "\nWage: " << wage;
}