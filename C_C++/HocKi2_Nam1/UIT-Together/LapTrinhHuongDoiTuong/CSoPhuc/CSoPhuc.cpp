#include "CSoPhuc.h"


CSoPhuc::CSoPhuc()
{
	this->realEle = 1;
	this->virtualEle = 1;
}
CSoPhuc::CSoPhuc(float realEle, float virtualEle)
{
	this->realEle = realEle;
	this->virtualEle = virtualEle;
}
CSoPhuc::CSoPhuc(const CSoPhuc& x)
{
	this->realEle = x.realEle;
	this->virtualEle = x.virtualEle;
}

CSoPhuc::~CSoPhuc()
{
	return;
}
void CSoPhuc::Input()
{
	cout << "\nNhap phan thuc: ";
	cin >> realEle;
	cout << "Nhap phan ao: ";
	cin >> virtualEle;
}

void CSoPhuc::Print()
{
	if (virtualEle < 0)
		cout << realEle << "i - " << abs(virtualEle);
	else
		cout << realEle << "i + " << virtualEle;
}

float CSoPhuc::GetRealEle()
{
	return realEle;
}

void CSoPhuc::SetRealEle(float value)
{
	realEle = value;
}

float CSoPhuc::GetVirtualEle()
{
	return virtualEle;
}

void CSoPhuc::SetVirtualEle(float value)
{
	virtualEle = value;
}

float CSoPhuc::Module()
{
	return sqrt(realEle * realEle + virtualEle * virtualEle);
}


CSoPhuc CSoPhuc::operator + (CSoPhuc value)
{
	CSoPhuc sum;
	sum.realEle = this->realEle + value.realEle;
	sum.virtualEle = this->virtualEle + value.virtualEle;
	return sum;
}

CSoPhuc CSoPhuc::operator -(CSoPhuc value)
{
	CSoPhuc different;
	different.realEle = this->realEle - value.realEle;
	virtualEle = this->virtualEle - value.virtualEle;
	return different;
}

CSoPhuc CSoPhuc::operator *(CSoPhuc value)
{
	CSoPhuc product;
	product.realEle = this->realEle * this->virtualEle - value.realEle * value.virtualEle;
	product.virtualEle = this->realEle * value.virtualEle + value.realEle * this->virtualEle;
	return product;
}

CSoPhuc CSoPhuc::operator / (CSoPhuc value)
{
	CSoPhuc quotient;
	float denominator = this->virtualEle * this->virtualEle + value.virtualEle * value.virtualEle;
	quotient.realEle = (this->realEle * this->virtualEle + value.realEle * value.virtualEle) / denominator;
	quotient.virtualEle = (this->virtualEle * value.realEle - this->realEle * value.virtualEle) / denominator;
	return quotient;
}


istream& operator >>(istream& is,  CSoPhuc& x)
{
	cout << "Nhap phan thuc: ";
	is >> x.realEle;
	cout << "Nhap phan ao: ";
	is >> x.virtualEle;
	return is;
} 
ostream& operator <<(ostream& os, CSoPhuc& x)
{
	if (x.virtualEle > 0)
		os << x.realEle << " + " << abs(x.virtualEle) << "i";
	else if (x.virtualEle < 0)
		os << x.realEle << " - " << abs(x.virtualEle) << "i";
	else
		os << x.realEle;
	return os;
}

bool CSoPhuc::operator > (CSoPhuc x)
{
	float a = this->Module();
	float b = x.Module();
	return (a > b);
}
bool CSoPhuc::operator < (CSoPhuc x)
{
	float a = this->Module();
	float b = x.Module();
	return (a < b);
}
bool CSoPhuc::operator == (CSoPhuc x)
{
	float a = this->Module();
	float b = x.Module();
	return (a == b);
}
bool CSoPhuc::operator != (CSoPhuc x)
{
	float a = this->Module();
	float b = x.Module();
	return (a != b);
}
bool CSoPhuc::operator >= (CSoPhuc x)
{
	float a = this->Module();
	float b = x.Module();
	return (a > b || a == b);
}
bool CSoPhuc::operator <= (CSoPhuc x)
{
	float a = this->Module();
	float b = x.Module();
	return (a < b || a == b);
}