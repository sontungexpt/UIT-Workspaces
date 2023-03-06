#pragma once
#include <iostream>
#include "NhanVien.h"

#define MAX_AMOUNT_OF_STAFFS 1000

class Company
{
private:
	int amount;
	Staff *staffs[MAX_AMOUNT_OF_STAFFS];

public:

	// Input the staff information 
	void Input();

	// Calculate the wage of the staff
	int CalcWage();

	// Output the information of the staff
	void Print();

	// return the sum of wage of all staff
	int CalcSumOfWage();

	Staff* FindStaff();


};

