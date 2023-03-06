#include "CDiemKhongGian.h"

CDiemKhongGian::CDiemKhongGian()
{
	this->x = 0;
	this->y = 0;
	this->z = 0;
}
CDiemKhongGian::CDiemKhongGian(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}
CDiemKhongGian::CDiemKhongGian(const CDiemKhongGian& x)
{
	this->x = x.x;
	this->y = x.y;
	this->z = x.z;
}

CDiemKhongGian::~CDiemKhongGian()
{
	return;
}


float CDiemKhongGian::GetDistance(CDiemKhongGian B)
{
	return sqrt((x - B.x) * (x - B.x) + (y - B.y) * (y - B.y) + (z - B.z) * (z - B.z));
}

void CDiemKhongGian::Print()
{
	cout << "(x , y , z) = (" << x << " , " << y << " , " << z << ")";
}

void CDiemKhongGian::Input()
{
	cout << "Nhap x: ";
	cin >> x;
	cout << "Nhap y: ";
	cin >> y;
	cout << "Nhap z: ";
	cin >> z;
}


istream& operator >>(istream& is, CDiemKhongGian& x)
{
	cout << "Nhap x: ";
	is >> x.x;
	cout << "Nhap y: ";
	is >> x.y;
	cout << "Nhap z: ";
	is >> x.z;
	return is;
}

ostream& operator <<(ostream& os, CDiemKhongGian& x)
{
	os << "\n(x,y,z) = (" << x.x << " , " << x.y << " , " << x.z << ")";
	return os;
}

bool CDiemKhongGian::operator > (CDiemKhongGian x)
{
	CDiemKhongGian O = { 0,0 ,0};
	float a = this->GetDistance(O);
	float b = x.GetDistance(O);
	return (a > b);
}
bool CDiemKhongGian::operator < (CDiemKhongGian x)
{
	CDiemKhongGian O = { 0,0 ,0};
	float a = this->GetDistance(O);
	float b = x.GetDistance(O);
	return (a < b);
}
bool CDiemKhongGian::operator == (CDiemKhongGian x)
{
	CDiemKhongGian O = { 0,0 ,0 };
	float a = this->GetDistance(O);
	float b = x.GetDistance(O);
	return (a == b);
}
bool CDiemKhongGian::operator != (CDiemKhongGian x)
{
	CDiemKhongGian O = { 0,0 ,0 };
	float a = this->GetDistance(O);
	float b = x.GetDistance(O);
	return (a != b);
}
bool CDiemKhongGian::operator >= (CDiemKhongGian x)
{
	CDiemKhongGian O = { 0,0 ,0 };
	float a = this->GetDistance(O);
	float b = x.GetDistance(O);
	return (a > b || a == b);
}
bool CDiemKhongGian::operator <= (CDiemKhongGian x)
{
	CDiemKhongGian O = { 0,0 ,0 };
	float a = this->GetDistance(O);
	float b = x.GetDistance(O);
	return (a < b || a == b);
}