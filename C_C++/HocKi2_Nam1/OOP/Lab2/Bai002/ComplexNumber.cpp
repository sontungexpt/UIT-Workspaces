#include "ComplexNumber.h"

void ComplexNumber::Input()
{
	cout << "\nInput real element: ";
	cin >> realEle;
	cout << "Input virtual element: ";
	cin >> virtualEle;
}

void ComplexNumber::Print()
{
	if (virtualEle < 0)
		cout << realEle << "i - " << abs(virtualEle);
	else
		cout << realEle << "i + " << virtualEle;
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

ComplexNumber ComplexNumber::Plus(ComplexNumber value)
{
	ComplexNumber sum;
	sum.realEle = this->realEle + value.realEle;
	sum.virtualEle = this->virtualEle + value.virtualEle;
	return sum;
}

ComplexNumber ComplexNumber::Minus(ComplexNumber value)
{
	ComplexNumber different;
	different.realEle = this->realEle - value.realEle;
	virtualEle = this->virtualEle - value.virtualEle;
	return different;
}

ComplexNumber ComplexNumber::MultipliedBy(ComplexNumber value)
{
	ComplexNumber product;
	product.realEle = this->realEle * this->virtualEle - value.realEle * value.virtualEle;
	product.virtualEle = this->realEle * value.virtualEle + value.realEle * this->virtualEle;
	return product;
}

ComplexNumber ComplexNumber::DivideBy(ComplexNumber value)
{
	ComplexNumber quotient;
	float denominator = this->virtualEle * this->virtualEle + value.virtualEle * value.virtualEle;
	quotient.realEle = (this->realEle * this->virtualEle + value.realEle * value.virtualEle) / denominator;
	quotient.virtualEle = (this->virtualEle * value.realEle - this->realEle * value.virtualEle) / denominator;
	return quotient;
}

float ComplexNumber::GetModule()
{
	return sqrt(this->realEle * this->realEle + this->virtualEle * this->virtualEle);
}

