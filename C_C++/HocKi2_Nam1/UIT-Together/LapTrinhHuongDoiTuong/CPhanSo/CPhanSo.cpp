#include "CPhanSo.h"

CPhanSo::CPhanSo()
{
	Tu = 0;
	Mau = 1;
}
CPhanSo::CPhanSo(int t, int m)
{
	Tu = t;
	Mau = m;
}
CPhanSo::CPhanSo(const CPhanSo& x)
{
	this->Tu = x.Tu;
	this->Mau = x.Mau;
}

CPhanSo::~CPhanSo()
{
	return;
}

void CPhanSo::Input()
{
	cout << "Nhap Tu: ";
	cin >> Tu;
	cout << "Nhap Mau: ";
	cin >> Mau;
}
CPhanSo CPhanSo::Shorten()
{
	CPhanSo result;
	int a = abs(Tu);
	int b = abs(Mau);
	while (a != b)
	{
		if (a > b)
			a = a - b;
		else
			b = b - a;
	}
	result.Tu = Tu / a;
	result.Mau = Mau / a;
	return result;
}

void CPhanSo::Print()
{
	if (Tu * Mau < 0)
		cout << "-" << abs(Tu) << "/" << abs(Mau);
	else
		cout << abs(Tu) << "/" << abs(Mau);
}

int CPhanSo::XetDau()
{
	if (Tu * Mau > 0)
		return 1;
	if (Tu * Mau < 0)
		return -1;
	return 0;
}

int CPhanSo::CompareWith(CPhanSo B)
{
	float a = (float)Tu / Mau;
	float b = (float)B.Tu / B.Mau;
	if (a > b)
		return 1;
	if (a < b)
		return -1;
	return 0;
}

CPhanSo CPhanSo::Plus(CPhanSo B)
{
	CPhanSo sum;
	sum.Tu = Tu * B.Mau + Mau * B.Tu;
	sum.Mau = Mau * B.Mau;
	return sum.Shorten();
}
CPhanSo CPhanSo::Minus(CPhanSo B)
{
	CPhanSo different;
	different.Tu = Tu * B.Mau - Mau * B.Tu;
	different.Mau = Mau * B.Mau;
	return different.Shorten();
}
CPhanSo CPhanSo::MultipliedBy(CPhanSo B)
{
	CPhanSo product;
	product.Tu = Tu * B.Tu;
	product.Mau = Mau * B.Mau;
	return product.Shorten();
}
CPhanSo CPhanSo::DivideBy(CPhanSo B)
{
	CPhanSo quotient;
	quotient.Tu = Tu * B.Mau;
	quotient.Mau = Mau * B.Tu;
	return quotient.Shorten();
}

istream& operator >> (istream& is, CPhanSo& x)
{
	cout << "\nNhap Tu: ";
	is >> x.Tu;
	cout << "Nhap Mau: ";
	is >> x.Mau;
	return is;
}

ostream& operator << (ostream& os, CPhanSo& x)
{
	if (x.Tu * x.Mau < 0)
		os << "-" << abs(x.Tu) << "/" << abs(x.Mau);
	else
		os << abs(x.Tu) << "/" << abs(x.Mau);
	return os;
}

CPhanSo CPhanSo::operator + (CPhanSo B)
{
	CPhanSo sum;
	sum.Tu = Tu * B.Mau + Mau * B.Tu;
	sum.Mau = Mau * B.Mau;
	return sum;
}
CPhanSo CPhanSo::operator - (CPhanSo B)
{
	CPhanSo different;
	different.Tu = Tu * B.Mau - Mau * B.Tu;
	different.Mau = Mau * B.Mau;
	return different;
}
CPhanSo CPhanSo::operator * (CPhanSo B)
{
	CPhanSo product;
	product.Tu = Tu * B.Tu;
	product.Mau = Mau * B.Mau;
	return product;
}
CPhanSo CPhanSo::operator / (CPhanSo B)
{
	CPhanSo quotient;
	quotient.Tu = Tu * B.Mau;
	quotient.Mau = Mau * B.Tu;
	return quotient;
}

bool CPhanSo::operator > (CPhanSo x)
{
	float a = (float)this->Tu / this->Mau;
	float b = (float)x.Tu / x.Mau;
	return (a > b );
}
bool CPhanSo::operator < (CPhanSo x)
{
	float a = (float)this->Tu / this->Mau;
	float b = (float)x.Tu / x.Mau;
	return (a < b);
}
bool CPhanSo::operator == (CPhanSo x)
{
	float a = (float)this->Tu / this->Mau;
	float b = (float)x.Tu / x.Mau;
	return (a == b);
}
bool CPhanSo::operator != (CPhanSo x) 
{
	float a = (float)this->Tu / this->Mau;
	float b = (float)x.Tu / x.Mau;
	return (a != b);
}
bool CPhanSo::operator >= (CPhanSo x)
{
	float a = (float)this->Tu / this->Mau;
	float b = (float)x.Tu / x.Mau;
	return (a > b||a ==b);
}
bool CPhanSo::operator <= (CPhanSo x)
{
	float a = (float)this->Tu / this->Mau;
	float b = (float)x.Tu / x.Mau;
	return (a < b || a == b);
}