#include "CDonThuc.h"


CDonThuc::CDonThuc()
{
	this->a = 1;
	this->n = 1;
}
CDonThuc::CDonThuc(float a, int n)
{
	this->a = a;
	this->n = n;
}
CDonThuc::CDonThuc(const CDonThuc& x)
{
	this->a = x.a;
	this->n = x.n;
}

CDonThuc::~CDonThuc()
{
	return;
}


void CDonThuc::Input()
{
	cout << "Nhap he so: ";
	cin >> a;
	cout << "Nhap so mu: ";
	cin >> n;
}

void CDonThuc::Print()
{
	cout << a << "x^" << n;
}

CDonThuc CDonThuc::Nhan(CDonThuc g)
{
	CDonThuc result;
	result.a = a * g.a;
	result.n = n + g.n;
	return result;
}

CDonThuc CDonThuc::Chia(CDonThuc g)
{
	CDonThuc result;
	result.a = a / g.a;
	result.n = n - g.n;
	return result;
}

CDonThuc CDonThuc::Derivatives()
{
	CDonThuc result;
	result.a = a * n;
	result.n = n - 1;
	return result;
}

CDonThuc CDonThuc::Derivatives(int k)
{
	cout << "Nhap cap cua dao ham: ";
	cin >> k;
	CDonThuc result;
	for (int i = 1; i <= k; i++)
		result.Derivatives();
	return result;
}

float CDonThuc::GetValue(float x)
{
	cout << "Nhap x0: ";
	cin >> x;
	return a * pow(x, n);
}

istream& operator >> (istream& is, CDonThuc& x)
{
	cout << "Nhap he so: ";
	is >> x.a;
	cout << "Nhap so mu: ";
	is >> x.n;
	return is;
}
ostream& operator << (ostream& os, CDonThuc& x)
{
	os << endl<<x.a << "x^" << x.n;
	return os;
}