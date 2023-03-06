#include "CDiem.h"

CDiem::CDiem()
{
	this->x = 0;
	this->y = 0;
}
CDiem::CDiem(float x, float y)
{
	this->x = x;
	this->y = y;
}
CDiem::CDiem(const CDiem& x)
{
	this->x = x.x;
	this->y = x.y;
}
CDiem::~CDiem()
{
	return;
}

float CDiem::GetX()
{
	return x;
}

void CDiem::SetX(float x)
{
	this->x = x;
}

float CDiem::GetY()
{
	return y;
}

void CDiem::SetY(float y)
{
	this->y = y;
}

void  CDiem::SetXY(float x, float y)
{
	this->x = x;
	this->y = y;
}

void CDiem::Input()
{
	cout << "\nNhap x:";
	cin >> x;
	cout << "Nhap y:";
	cin >> y;
}

void CDiem::Print()
{
	cout << "(x , y) = (" << x << " , " << y << ")";
}

float CDiem::GetDistance(CDiem B)
{
	return sqrt((x - B.x) * (x - B.x) + (y - B.y) * (y - B.y));
}

istream& operator >> (istream& is, CDiem& x)
{
	cout << "\nNhap x: ";
	is >> x.x;
	cout << "Nhap y: ";
	is >> x.y;
	return is;
}
ostream& operator << (ostream& os, CDiem& x)
{
	os << "(x , y) = (" << x.x << " , " << x.y << ")";
	return os;
}

bool CDiem::operator > (CDiem x)
{
	CDiem O = { 0,0 };
	float a = this->GetDistance(O);
	float b = x.GetDistance(O);
	return (a > b);
}
bool CDiem::operator < (CDiem x)
{
	CDiem O = { 0,0 };
	float a = this->GetDistance(O);
	float b = x.GetDistance(O);
	return (a < b);
}
bool CDiem::operator == (CDiem x)
{
	CDiem O = { 0,0 };
	float a = this->GetDistance(O);
	float b = x.GetDistance(O);
	return (a == b);
}
bool CDiem::operator != (CDiem x)
{
	CDiem O = { 0,0 };
	float a = this->GetDistance(O);
	float b = x.GetDistance(O);
	return (a != b);
}
bool CDiem::operator >= (CDiem x)
{
	CDiem O = { 0,0 };
	float a = this->GetDistance(O);
	float b = x.GetDistance(O);
	return (a > b || a == b);
}
bool CDiem::operator <= (CDiem x)
{
	CDiem O = { 0,0 };
	float a = this->GetDistance(O);
	float b = x.GetDistance(O);
	return (a < b || a == b);
}