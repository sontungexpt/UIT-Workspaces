#include "ComplexNumber.h"

ComplexNumber::ComplexNumber()
{
	this->realEle = 1;
	this->virtualEle = 0;
}
ComplexNumber::ComplexNumber(float realNumber)
{
	this->realEle = realNumber;
	this->virtualEle = 0;
}

ComplexNumber::~ComplexNumber()
{
	return;
}

float ComplexNumber::GetRealEle()
{
	return realEle;
}

void ComplexNumber::SetRealEle(float value)
{
	realEle = value;
}

float ComplexNumber::GetVirtualEle()
{
	return virtualEle;
}

void ComplexNumber::SetVirtualEle(float value)
{
	virtualEle = value;
}

float ComplexNumber::Module()
{
	return sqrt(realEle * realEle + virtualEle * virtualEle);
}


ComplexNumber ComplexNumber::operator + (ComplexNumber value)
{
	ComplexNumber sum;
	sum.realEle = this->realEle + value.realEle;
	sum.virtualEle = this->virtualEle + value.virtualEle;
	return sum;
}

ComplexNumber ComplexNumber::operator -(ComplexNumber value)
{
	ComplexNumber different;
	different.realEle = this->realEle - value.realEle;
	virtualEle = this->virtualEle - value.virtualEle;
	return different;
}

ComplexNumber ComplexNumber::operator *(ComplexNumber value)
{
	ComplexNumber product;
	product.realEle = this->realEle * this->virtualEle - value.realEle * value.virtualEle;
	product.virtualEle = this->realEle * value.virtualEle + value.realEle * this->virtualEle;
	return product;
}

ComplexNumber ComplexNumber::operator / (ComplexNumber value)
{
	ComplexNumber quotient;
	float denominator = this->virtualEle * this->virtualEle + value.virtualEle * value.virtualEle;
	quotient.realEle = (this->realEle * this->virtualEle + value.realEle * value.virtualEle) / denominator;
	quotient.virtualEle = (this->virtualEle * value.realEle - this->realEle * value.virtualEle) / denominator;
	return quotient;
}


istream& operator >>(istream& is, ComplexNumber& x)
{
	cout << "\nNhap phan thuc: ";
	is >> x.realEle;
	cout << "Nhap phan ao: ";
	is >> x.virtualEle;
	return is;
}
ostream& operator <<(ostream& os, ComplexNumber& x)
{
	if (x.virtualEle > 0)
		os << x.realEle << " + " << abs(x.virtualEle) << "i";
	else if (x.virtualEle < 0)
		os << x.realEle << " - " << abs(x.virtualEle) << "i";
	else
		os << x.realEle;
	return os;
}

bool ComplexNumber::operator > (ComplexNumber x)
{
	float a = this->Module();
	float b = x.Module();
	return (a > b);
}
bool ComplexNumber::operator < (ComplexNumber x)
{
	float a = this->Module();
	float b = x.Module();
	return (a < b);
}
bool ComplexNumber::operator == (ComplexNumber x)
{
	float a = this->Module();
	float b = x.Module();
	return (a == b);
}
bool ComplexNumber::operator != (ComplexNumber x)
{
	float a = this->Module();
	float b = x.Module();
	return (a != b);
}
