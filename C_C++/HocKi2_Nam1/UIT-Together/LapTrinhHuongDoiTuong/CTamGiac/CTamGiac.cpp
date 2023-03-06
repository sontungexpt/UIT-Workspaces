#include "CTamGiac.h"


CTamGiac::CTamGiac()
{
	this->A = { 0,0 };
	this->B = { 0,0 };
	this->C = { 0,0 };

}
CTamGiac::CTamGiac(CDiem A, CDiem B, CDiem C)
{
	this->A = A;
	this->B = B;
	this->C = C;
}
CTamGiac::CTamGiac(const CTamGiac& x)
{
	this->A = x.A;
	this->B = x.B;
	this->C = x.C;
}

CTamGiac::~CTamGiac()
{
	return;
}



void CTamGiac::Input()
{
	cout << "Nhap A: ";
	cin >> A;
	cout << "Nhap B: ";
	cin >> B;
	cout << "Nhap C: ";
	cin >> C;
}
void CTamGiac::Print()
{
	cout << "\nA ";
	cout << A;
	cout << "\nB ";
	cout << B;
	cout << "\nC ";
	cout << C;
}

float CTamGiac::GetPerimeter()
{
	float a = B.GetDistance(C);
	float b = C.GetDistance(A);
	float c = A.GetDistance(B);
	return (a + b + c);
}

float CTamGiac::GetArea()
{
	float a = B.GetDistance(C);
	float b = C.GetDistance(A);
	float c = A.GetDistance(B);
	float p = (a + b + c) / 2;
	return sqrt(p * (p - a) * (p - b) * (p - c));
}

CDiem CTamGiac::GetCentroid()
{
	CDiem centroid;
	centroid.SetX((A.GetX() + B.GetX() + C.GetX()) / 3);
	centroid.SetY((A.GetY() + B.GetY() + C.GetY()) / 3);
	return centroid;
}


istream& operator >> (istream& is, CTamGiac& x)
{
	cout << "Nhap A: ";
	is >> x.A;
	cout << "Nhap B: ";
	is >> x.B;
	cout << "Nhap C: ";
	is >> x.C;
	return is;
}
ostream& operator << (ostream& os, CTamGiac& x)
{
	os << "\nA " << x.A;
	os << "\nB " << x.B;
	os << "\nC " << x.C;
	return os;
}

bool CTamGiac::operator > (CTamGiac x)
{
	float a = this->GetArea();
	float b = x.GetArea();
	return (a > b);
}
bool CTamGiac::operator < (CTamGiac x)
{
	float a = this->GetArea();
	float b = x.GetArea();
	return (a < b);
}
bool CTamGiac::operator == (CTamGiac x)
{
	float a = this->GetArea();
	float b = x.GetArea();
	return (a == b);
}
bool CTamGiac::operator != (CTamGiac x)
{
	float a = this->GetArea();
	float b = x.GetArea();
	return (a != b);
}
bool CTamGiac::operator >= (CTamGiac x)
{
	float a = this->GetArea();
	float b = x.GetArea();
	return (a > b || a == b);
}
bool CTamGiac::operator <= (CTamGiac x)
{
	float a = this->GetArea();
	float b = x.GetArea();
	return (a < b || a == b);
}