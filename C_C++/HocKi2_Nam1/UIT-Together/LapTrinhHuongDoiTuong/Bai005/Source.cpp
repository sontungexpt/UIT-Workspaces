#include <iostream>
#include <math.h>

using namespace std;

class ComplexNumber
{
private:
	float realEle;
	float virtualEle;
public:
	//constuctor
	ComplexNumber(float realEle = 1, float virtualEle = 0)
	{
		this->realEle = realEle;
		this->virtualEle = virtualEle;
	}

	//method
	void Input();
	void Print();
	float GetRealEle();
	void SetRealEle(float);
	float GetVirtualEle();
	void SetVirtualEle(float);
	ComplexNumber Plus(ComplexNumber);
	ComplexNumber Minus(ComplexNumber);
	ComplexNumber MultipliedBy(ComplexNumber);
	ComplexNumber DivideBy(ComplexNumber);
};



int main()
{
	ComplexNumber num1;
	ComplexNumber num2;

	cout << "Nhap so phuc 1: ";
	num1.Input();
	cout << "Nhap so phuc 2: ";
	num2.Input();
	cout << "\n(";
	num1.Print();
	cout << ") + (";
	num2.Print();
	cout << ") = ";
	ComplexNumber sum = num1.Plus(num2);
	sum.Print();
	cout << "\n(";
	num1.Print();
	cout << ") - (";
	num2.Print();
	cout << ") = ";
	ComplexNumber different = num1.Minus(num2);
	different.Print();
	cout << "\n(";
	num1.Print();
	cout << ") * (";
	num2.Print();
	cout << ") = ";
	ComplexNumber product = num1.MultipliedBy(num2);
	product.Print();
	cout << "\n(";
	num1.Print();
	cout << ") / (";
	num2.Print();
	cout << ") = ";
	ComplexNumber quotient = num1.DivideBy(num2);
	quotient.Print();
	return 0;
}

void ComplexNumber::Input()
{
	cout << "\nNhap phan thuc: ";
	cin >> realEle;
	cout << "Nhap phan ao: ";
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

