#include "CHonSo.h"


CHonSo::CHonSo()
{
	this->Nguyen = 1;
	this->Tu = 0;
	this->Mau = 1;
}

CHonSo::CHonSo(int Nguyen, int Tu, int Mau)
{
	this->Nguyen = Nguyen;
	this->Tu = Tu;
	this->Mau = Mau;
}

CHonSo::CHonSo(const CHonSo& x)
{
	this->Nguyen = x.Nguyen;
	this->Tu = x.Tu;
	this->Mau = x.Mau;
}

CHonSo::~CHonSo()
{
	return ;
}

void CHonSo::Nhap()
{
	cout << "Nhap nguyen: ";
	cin >> Nguyen;
	cout << "Nhap tu: ";
	cin >> Tu;
	cout << "Nhap mau: ";
	cin >> Mau;
}

void CHonSo::Xuat()
{
	cout << "\nNguyen: " << Nguyen;
	cout << "\nTu: " << Tu;
	cout << "\nMau: " << Mau;
}

CHonSo CHonSo::RutGon()
{
	CHonSo newMixedNumber;
	int a = abs(Tu);
	int b = abs(Mau);
	while (a != b)
	{
		if (a > b)
			a = a - b;
		else
			b = b - a;
	}
	newMixedNumber.Tu = Tu / a;
	newMixedNumber.Mau = Mau / a;
	newMixedNumber.Nguyen = Nguyen + Tu / Mau;
	newMixedNumber.Tu = Tu % Mau;
	return newMixedNumber;
}

CHonSo CHonSo::operator+(CHonSo x)
{
	CHonSo result;
	result.Nguyen = Nguyen + x.Nguyen;
	result.Tu = Tu * x.Mau + x.Tu * Mau;
	result.Mau = Mau * x.Mau;
	return result.RutGon();
}

CHonSo CHonSo::operator-(CHonSo x)
{
	CHonSo result;
	result.Nguyen = Nguyen - x.Nguyen;
	result.Tu = Tu * x.Mau - x.Tu * Mau;
	result.Mau = Mau * x.Mau;
	return result.RutGon();
}

CHonSo CHonSo::operator*(CHonSo x)
{
	CHonSo result;
	result.Tu = Nguyen * Mau + Tu;
	result.Mau = Mau;
	result.Nguyen = 0;
	CHonSo temp;
	temp.Tu = x.Nguyen * x.Mau + x.Tu;
	temp.Mau = x.Mau;
	temp.Nguyen = 0;
	result.Tu = result.Tu * temp.Tu;
	result.Mau = result.Mau * temp.Mau;
	result.Nguyen = 0;
	return result.RutGon();
}

CHonSo CHonSo::operator/(CHonSo x)
{
	CHonSo result;
	result.Tu = Nguyen * Mau + Tu;
	result.Mau = Mau;
	result.Nguyen = 0;
	CHonSo temp;
	temp.Tu = x.Nguyen * x.Mau + x.Tu;
	temp.Mau = x.Mau;
	temp.Nguyen = 0;
	result.Tu = Tu * x.Mau;
	result.Mau = Mau * x.Tu;
	result.Nguyen = 0;
	return result.RutGon();
}

bool CHonSo::ToiGian()
{
	int a = abs(Tu);
	int b = abs(Mau);
	while (a != b)
	{
		if (a > b)
			a = a - b;
		else
			b = b - a;
	}
	if (a == 1 && Tu / Mau == 0)
		return 1;
	return 0;
}

void CHonSo::QuiDongMau(CHonSo& x)
{
	int mc = Mau * x.Mau;
	Tu = Tu * x.Mau;
	x.Tu = Mau * x.Tu;
	Mau = mc;
	x.Mau = mc;
}

void CHonSo::QuiDongTu(CHonSo& x)
{
	int tc = Tu * x.Tu;
	Mau = Mau * x.Tu;
	x.Mau = x.Mau * Tu;
	Tu = tc;
	x.Tu = tc;
}

istream& operator >> (istream& is, CHonSo& x)
{
	cout << "\nNhap nguyen: ";
	is >> x.Nguyen;
	cout << "Nhap tu: ";
	is >> x.Tu;
	cout << "Nhap mau: ";
	is >> x.Mau;
	return is;
}

ostream& operator << (ostream& os, CHonSo& x)
{
	os << "\nNguyen: " << x.Nguyen;
	os << "\nTu: " << x.Tu;
	os << "\nMau: " << x.Mau;
	return os;
}

CHonSo& CHonSo::operator = (const CHonSo& x)
{
	Nguyen = x.Nguyen;
	Mau = x.Mau;
	Tu = x.Tu;
	return *this;
}

bool CHonSo::operator > (CHonSo x)
{
	float a = (float)(this->Nguyen*this->Mau+this->Tu) / this->Mau;
	float b = (float)(x.Nguyen * x.Mau + x.Tu) / x.Mau;
	return (a > b);
}
bool CHonSo::operator < (CHonSo x)
{
	float a = (float)(this->Nguyen * this->Mau + this->Tu) / this->Mau;
	float b = (float)(x.Nguyen * x.Mau + x.Tu) / x.Mau;
	return (a < b);
}
bool CHonSo::operator == (CHonSo x)
{
	float a = (float)(this->Nguyen * this->Mau + this->Tu) / this->Mau;
	float b = (float)(x.Nguyen * x.Mau + x.Tu) / x.Mau;
	return (a == b);
}
bool CHonSo::operator != (CHonSo x)
{
	float a = (float)(this->Nguyen * this->Mau + this->Tu) / this->Mau;
	float b = (float)(x.Nguyen * x.Mau + x.Tu) / x.Mau;
	return (a != b);
}
bool CHonSo::operator >= (CHonSo x)
{
	float a = (float)(this->Nguyen * this->Mau + this->Tu) / this->Mau;
	float b = (float)(x.Nguyen * x.Mau + x.Tu) / x.Mau;
	return (a > b || a == b);
}
bool CHonSo::operator <= (CHonSo x)
{
	float a = (float)(this->Nguyen * this->Mau + this->Tu) / this->Mau;
	float b = (float)(x.Nguyen * x.Mau + x.Tu) / x.Mau;
	return (a < b || a == b);
}