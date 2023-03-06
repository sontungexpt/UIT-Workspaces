#include "Fraction.h"


int Fraction::GetNumerator()
{
	return numerator;
}
void Fraction::SetNumerator(int value)
{
	this->numerator = value;
}
int Fraction::GetDenominator()
{
	return denominator;
}
void Fraction::SetDenominator(int value)
{
	if (value != 0)
		this->denominator = value;
	else
		cout << "Can not divide by 0";
}
Fraction Fraction::Plus(Fraction frac)
{
	Fraction sum;
	sum.numerator = this->numerator * frac.denominator + frac.numerator * this->denominator;
	sum.denominator = this->denominator * frac.denominator;
	return sum;
}
Fraction Fraction::Minus(Fraction frac)
{
	Fraction different;
	different.numerator = this->numerator * frac.denominator - frac.numerator * this->denominator;
	different.denominator = this->denominator * frac.denominator;
	return different;
}
Fraction Fraction::MultipliedBy(Fraction frac)
{
	Fraction product;
	product.numerator = this->numerator * frac.numerator;
	product.denominator = this->denominator * frac.denominator;
	return product;
}
Fraction Fraction::DivideBy(Fraction frac)
{
	Fraction quotient;
	quotient.numerator = this->numerator * frac.denominator;
	quotient.denominator = this->denominator * frac.numerator;
	return quotient;
}

void Fraction::Print()
{
	cout << numerator << "/" << denominator;
}

void Fraction::Input()
{
	cout << "\nInput Numerator: ";
	cin >> numerator;
	cout << "Input Denominator: ";
	cin >> denominator;
	cout << endl;
}