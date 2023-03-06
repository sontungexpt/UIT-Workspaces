#include "CHinhCau.h"

CHinhCau::CHinhCau()
{
	I = { 0,0 };
	R = 1;
}
CHinhCau::CHinhCau(CDiem I, float R)
{
	this->I = I;
	this->R = R;
}
CHinhCau::CHinhCau(const CHinhCau& x)
{
	this->I = x.I;
	this->R = x.R;
}
CHinhCau::~CHinhCau()
{
	return;
}

void CHinhCau::Input()
{
	cout << "Nhap tam: ";
	cin >> I;
	cout << "Nhap ban kinh: ";
	cin >> R;
}

void CHinhCau::Print()
{
	cout << "\nTam";
	cout << I;
	cout << "\nBan kinh: " << R;
}

float CHinhCau::GetArea()
{
	return 4* PI * R * R;
}

float CHinhCau::GetVolumn()
{
	return PI * R * R *R /3 * 4;
}

istream& operator >> (istream& is, CHinhCau& x)
{
	cout << "Nhap tam: "; CHinhCau;
	is >> x.I;
	cout << "Nhap ban kinh: ";
	is >> x.R;
	return is;
}
ostream& operator << (ostream& os, CHinhCau& x)
{
	cout << "\nTam I";
	os << x.I;
	os << "\nBan kinh: " << x.R;
	return os;
}


bool CHinhCau::operator > (CHinhCau x)
{
	float a = this->GetVolumn();
	float b = x.GetVolumn();
	return (a > b);
}
bool CHinhCau::operator < (CHinhCau x)
{
	float a = this->GetVolumn();
	float b = x.GetVolumn();
	return (a < b);
}
bool CHinhCau::operator == (CHinhCau x)
{
	float a = this->GetVolumn();
	float b = x.GetVolumn();
	return (a == b);
}
bool CHinhCau::operator != (CHinhCau x)
{
	float a = this->GetVolumn();
	float b = x.GetVolumn();
	return (a != b);
}
bool CHinhCau::operator >= (CHinhCau x)
{
	float a = this->GetVolumn();
	float b = x.GetVolumn();
	return (a > b || a == b);
}
bool CHinhCau::operator <= (CHinhCau x)
{
	float a = this->GetVolumn();
	float b = x.GetVolumn();
	return (a < b || a == b);
}