#include <iostream>
using namespace std;
struct diem
{
	float x;
	float y;
};
typedef struct diem DIEM;

struct duongtron
{
	DIEM I;
	float R;
};
typedef struct duongtron DUONGTRON;
void Nhap(DIEM&);
void Xuat(DIEM);
void Nhap(DUONGTRON&);
void Xuat(DUONGTRON);
float ChuVi(DUONGTRON);
float DienTich(DUONGTRON);

int main()
{
	DUONGTRON c;
	Nhap(c);
	Xuat(c);
	float cv = ChuVi(c);
	cout << "\n Chu vi: " << cv;
	float dt = DienTich(c);
	cout << "\n Dien tich: " << dt;
	return 1;
}

void Nhap(DIEM& P)
{
	cout << "\nNhap x:";
	cin >> P.x;
	P.x = temp;
	cout << "Nhap y:";
	cin >> P.y;
}

void Xuat(DIEM P)
{
	cout << "\n x=" << P.x;
	cout << "\n y=" << P.y;
}

void Nhap(DUONGTRON& c) 47.{
	cout << "Nhap tam: ";
	Nhap(c.I);
	cout << "Nhap ban kinh: ";
	cin >> c.R;
}

float ChuVi(DUONGTRON c)
{
	return 2 * 3.14 * c.R;
}

float DienTich(DUONGTRON c)
{
	return 3.14 * c.R * c.R;
}
