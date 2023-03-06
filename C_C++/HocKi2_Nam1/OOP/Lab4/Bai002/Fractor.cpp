#include "Fractor.h"

Fractor::Fractor()
{
	numerator = 0;
	denominator = 1;
}
Fractor::Fractor(int numerator)
{
	this->numerator = numerator ;
	denominator = 1;
}

Fractor::~Fractor()
{
	return;
}


istream& operator >> (istream& is, Fractor& x)
{
	cout << "\nNhap numerator: ";
	is >> x.numerator;
	cout << "Nhap denominator: ";
	is >> x.denominator;
	return is;
}

ostream& operator << (ostream& os, Fractor& x)
{
	if (x.numerator * x.denominator < 0)
		os << "-" << abs(x.numerator) << "/" << abs(x.denominator);
	else
		os << abs(x.numerator) << "/" << abs(x.denominator);
	return os;
}

Fractor Fractor::operator + (Fractor B)
{
	Fractor sum;
	sum.numerator = numerator * B.denominator + denominator * B.numerator;
	sum.denominator = denominator * B.denominator;
	return sum;
}
Fractor Fractor::operator - (Fractor B)
{
	Fractor different;
	different.numerator = numerator * B.denominator - denominator * B.numerator;
	different.denominator = denominator * B.denominator;
	return different;
}
Fractor Fractor::operator * (Fractor B)
{
	Fractor product;
	product.numerator = numerator * B.numerator;
	product.denominator = denominator * B.denominator;
	return product;
}
Fractor Fractor::operator / (Fractor B)
{
	Fractor quotient;
	quotient.numerator = numerator * B.denominator;
	quotient.denominator = denominator * B.numerator;
	return quotient;
}

bool Fractor::operator == (Fractor x)
{
	float a = (float)this->numerator / this->denominator;
	float b = (float)x.numerator / x.denominator;
	return (a == b);
}
bool Fractor::operator != (Fractor x)
{
	float a = (float)this->numerator / this->denominator;
	float b = (float)x.numerator / x.denominator;
	return (a != b);
}
