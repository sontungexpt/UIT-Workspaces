//
// Created by tung on 13/06/2022.
//

#include "Tester.h"

Tester::Tester() :Staff()
{
	NumberOfBugs = 0;
}

Tester::~Tester()
{
	NumberOfBugs = 0;
}

void Tester::Read()
{
	Staff::Read();
	cout << "\nEnter the number of bugs: ";
	cin >> NumberOfBugs;
}

void Tester::Print()const
{
	Staff::Print();
	cout << "\nNumber of bugs: " << NumberOfBugs;
}

int Tester::GetSalary()const
{
	return BasicSalary + NumberOfBugs * 50000;
}