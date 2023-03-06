#include "CDiem.h"

CDiem::CDiem()
{
	x = 0;
	y = 0;
}

CDiem::CDiem(float x, float y)
{
	this->x = x;
	this->y = y;
}

CDiem::CDiem(const CDiem& P)
{
	x = P.x;
	y = P.y;
}

CDiem::~CDiem()
{
	return;
}

void CDiem::Nhap()
{
	cout << "Nhap x: ";
	cin >> x;
	cout << "Nhap y: ";
	cin >> y;
}

void CDiem::Xuat()
{
	cout << "x = " << x << endl;
	cout << "y = " << y << endl;
}

istream& operator>>(istream& is, CDiem& P)
{
	cout << "Nhap x: ";
	is >> P.x;
	cout << "Nhap y: ";
	is >> P.y;
	return is;
}

ostream& operator<<(ostream& os, CDiem& P)
{
	cout << "x = " << P.x << endl;
	cout << "y = " << P.y << endl;
	return os;
}

CDiem& CDiem::operator=(const CDiem& P)
{
	x = P.x;
	y = P.y;
	return *this;
}

float CDiem::KhoangCach() const
{
	return sqrt(x * x + y * y);
}

int CDiem::operator<(const CDiem& d)
{
	if (KhoangCach() < d.KhoangCach())
		return 1;
	return 0;
}

int CDiem::operator>(const CDiem& d)
{
	if (KhoangCach() > d.KhoangCach())
		return 1;
	return 0;
}

int CDiem::operator<=(const CDiem& d)
{
	if (KhoangCach() <= d.KhoangCach())
		return 1;
	return 0;
}

int CDiem::operator>=(const CDiem& d)
{
	if (KhoangCach() >= d.KhoangCach())
		return 1;
	return 0;
}

int CDiem::operator==(const CDiem& d)
{
	if (KhoangCach() == d.KhoangCach())
		return 1;
	return 0;
}

int CDiem::operator!=(const CDiem& d)
{
	if (KhoangCach() != d.KhoangCach())
		return 1;
	return 0;
}

float CDiem::getX() const
{
	return x;
}

float CDiem::getY() const
{
	return y;
}

void CDiem::setX(float x)
{
	this->x = x;
}

void CDiem::setY(float y)
{
	this->y = y;
}