#include "CDuongThang.h"

istream& operator>>(istream& is, CDuongThang& P)
{
	cout << "Nhap a: ";
	is >> P.a;
	cout << "Nhap b: ";
	is >> P.b;
	cout << "Nhap c: ";
	is >> P.c;
	return is;
}

void CDuongThang::KhoiTao()
{
	a = 1;
	b = 1;
	c = 1;
}

void CDuongThang::KhoiTao(float aa, float bb, float cc)
{
	a = aa;
	b = bb;
	c = cc;
}

void CDuongThang::KhoiTao(const CDuongThang& P)
{
	a = P.a;
	b = P.b;
	c = P.c;
}

CDuongThang::CDuongThang()
{
	a = 1;
	b = 1;
	c = 1;
}

CDuongThang::CDuongThang(float aa, float bb, float cc)
{
	a = aa;
	b = bb;
	c = cc;
}

CDuongThang::CDuongThang(const CDuongThang& P)
{
	a = P.a;
	b = P.b;
	c = P.c;
}

void CDuongThang::Nhap()
{
	cout << "Nhap a: ";
	cin >> a;
	cout << "Nhap b: ";
	cin >> b;
	cout << "Nhap c: ";
	cin >> c;
}

void CDuongThang::Xuat()
{
	cout << "\na = " << a;
	cout << "\nb = " << b;
	cout << "\nc = " << c;
}

ostream& operator << (ostream& os, CDuongThang& P)
{
	os << "\na = " << P.a;
	os << "\nb = " << P.b;
	os << "\nc = " << P.c;
	return os;
}

float CDuongThang::getA()
{
	return a;
}

float CDuongThang::getB()
{
	return b;
}

float CDuongThang::getC()
{
	return c;
}

CDuongThang& CDuongThang::operator = (const CDuongThang& P)
{
	a = P.a;
	b = P.b;
	c = P.c;
	return *this;
}

void CDuongThang::setA(float aa)
{
	a = aa;
}

void CDuongThang::setB(float bb)
{
	b = bb;
}

void CDuongThang::setC(float cc)
{
	c = cc;
}

int CDuongThang::isThuoc(const CDiem& P)
{
	if (a * P.getX() + b * P.getY() + c)
		return 1;
	return 0;
}

int CDuongThang::isTrung(const CDuongThang& P)
{
	float t = a * P.b - b * P.a;
	float Dx = -c * P.b + P.c * b;
	if (t == 0 && Dx == 0)
		return 1;
	return 0;
}

int CDuongThang::isKhongTrung(const CDuongThang& P)
{
	float t = a * P.b - P.a * b;
	float Dx = -c * P.b + P.c * b;
	if (!(t == 0 && Dx == 0))
		return 1;
	return 0;
}

int CDuongThang::ktSongSong(const CDuongThang& P)
{
	float t = a * P.b - P.a * b;
	float Dx = -c * P.b + P.c * b;
	if (t == 0 && Dx != 0)
		return 1;
	return 0;
}

int CDuongThang::ktCatNhau(const CDuongThang& P)
{
	float D = a * P.b - P.a * b;
	if (D != 0)
		return 1;
	return 0;
}

int CDuongThang::ktVuongGoc(const CDuongThang& P)
{
	float D = a * P.a + P.b * b;
	if (D == 0)
		return 1;
	return 0;
}

int CDuongThang::operator==(const CDuongThang& P)
{
	if (KhoangCachGoc() == P.KhoangCachGoc())
		return 1;
	return 0;
}

int CDuongThang::operator!=(const CDuongThang& P)
{
	if (KhoangCachGoc() != P.KhoangCachGoc())
		return 1;
	return 0;
}

int CDuongThang::operator > (const CDuongThang& P)
{
	if (KhoangCachGoc() > P.KhoangCachGoc())
		return 1;
	return 0;
}

int CDuongThang::operator < (const CDuongThang& P)
{
	if (KhoangCachGoc() < P.KhoangCachGoc())
		return 1;
	return 0;
}

int CDuongThang::operator >= (const CDuongThang& P)
{
	if (KhoangCachGoc() >= P.KhoangCachGoc())
		return 1;
	return 0;
}

int CDuongThang::operator <= (const CDuongThang& P)
{
	if (KhoangCachGoc() <= P.KhoangCachGoc())
		return 1;
	return 0;
}

float CDuongThang::KhoangCachGoc() const
{
	float t = sqrt(a * a + b * b);
	return (abs(c) / t);
}

float CDuongThang::KhoangCachDiemVaDuongThang(const CDiem& P)
{
	float D = abs(a * P.getX() + b * P.getY() + c);
	float t = sqrt(a * a + b * b);
	return (D / t);
}

CDiem CDuongThang::GiaoDiem(const CDuongThang& P)
{
	CDiem temp;
	temp.setX((float)(P.b - b) / (a - P.a));
	temp.setY(a * temp.getX() + b);
	return temp;
}

CDuongThang::~CDuongThang()
{
	return;
}
