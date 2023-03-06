//
// Created by tung on 13/06/2022.
//

#include "Developer.h"

Developer::Developer() : Staff()
{
	Overtime = 0;
}

Developer::~Developer()
{
	Overtime = 0;
}

void Developer::Read()
{
	Staff::Read();
	cout << "\nEnter the overtime of staff: ";
	cin >> Overtime;
}

void Developer::Print()const
{
	Staff::Print();
	cout << "\nOvertime: " << Overtime << " hours";
}

int Developer::GetSalary()const
{
	return BasicSalary + Overtime * 200000;
}
