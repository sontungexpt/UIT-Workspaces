#include "ProductionStaff.h"

ProductionStaff::ProductionStaff()
{
	basicWage = 0;
	productAmount = 0;
}


void ProductionStaff::CalcWage()
{
	wage = basicWage + productAmount * 5000;
}

istream& operator >> (istream& is, ProductionStaff& inValue)
{
	cin.ignore();
	cout << "\nInput full name: ";
	getline(is, inValue.fullName);
	cout << "Input birthday: ";
	is >> inValue.birthDay;
	cout << "Input basic wage: ";
	is >> inValue.basicWage;
	cout << "Input amount of products: ";
	is >> inValue.productAmount;
	return is;
}
ostream& operator << (ostream& os, ProductionStaff& outValue)
{
	os << "\nFull name: " << outValue.fullName;
	os << "\nBirthday: " << outValue.birthDay;
	os << "\nBasic wage: " << outValue.basicWage;
	os << "\nAmount of product: " << outValue.productAmount;
	os << "\nWage: " << outValue.wage;
	return os;
}

void ProductionStaff::Print()
{
	cout<< "\nFull name: " << fullName;
	cout<< "\nBirthday: " << birthDay;
	cout<< "\nBasic wage: " << basicWage;
	cout<< "\nAmount of product: " << productAmount;
	cout<< "\nWage: " << wage;
}
