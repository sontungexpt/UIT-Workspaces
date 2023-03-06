#include "Monomial.h"

#pragma region Constructor

Monomial::Monomial()
{
	this->coefficient = 0;
	this->indexNumber = 0;
}
Monomial::Monomial(int coefficient, int indexNumber)
{
	this->coefficient = coefficient;
	this->indexNumber = indexNumber;
}
Monomial::Monomial(const Monomial& newMonomial)
{
	this->coefficient = newMonomial.coefficient;
	this->indexNumber = newMonomial.indexNumber;
}
#pragma endregion

#pragma region Properties

int Monomial::GetCoefficient()
{
	return coefficient;
}
void Monomial::SetCoefficient(int value)
{
	this->coefficient == value;
}

int Monomial::GetIndexNumber()
{
	return coefficient;
}
void Monomial::SetIndexNumber(int value)
{
	this->indexNumber = value;
}

#pragma endregion

#pragma region Method
istream& operator >> (istream& is, Monomial& monomial)
{
	cout << "Input the coefficient: ";
	is >> monomial.coefficient;
	cout << "Input the index: ";
	is >> monomial.indexNumber;
	return is;
}
ostream& operator << (ostream& os, Monomial& monomial)
{
	os << monomial.coefficient << "x^" << monomial.indexNumber;
	return os;
}

double Monomial::CalcMonomial(double x)
{
	return this->coefficient * pow(x, this->indexNumber);
}
#pragma endregion