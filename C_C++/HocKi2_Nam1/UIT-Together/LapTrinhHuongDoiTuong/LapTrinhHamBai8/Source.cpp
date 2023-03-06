#include <iostream>
#include <cmath>
using namespace std;
struct diem
{
	float x;
	float y;
};
typedef struct diem DIEM;

struct tamgiac
{
	DIEM A;
	DIEM B;
	DIEM C;
};
typedef struct tamgiac TAMGIAC;

void Nhap(DIEM&);
void Xuat(DIEM);
float KhoangCach(DIEM, DIEM);
void Nhap(TAMGIAC&);
void Xuat(TAMGIAC);
float ChuVi(TAMGIAC);
float DienTich(TAMGIAC);
DIEM TrongTam(TAMGIAC);

int main()
{
	TAMGIAC tg;
	Nhap(tg);
	Xuat(tg);
	float cv = ChuVi(tg);
	cout << "\nChu vi: " << cv;
	float dt = DienTich(tg);
	cout << "\nDien tich: " << dt;
	DIEM G = TrongTam(tg);
	cout << "\nTrong tam: ";
	Xuat(G);
	return 1;
}

void Nhap(DIEM& P)
{
	cout << "\nNhap x:";
	cin >> P.x;
	cout << "Nhap y:";
	cin >> P.y;
}

void Xuat(DIEM P)
{
	cout << "\n x=" << P.x;
	cout << "\n y=" << P.y;
}

float KhoangCach(DIEM P, DIEM Q)
{
	return sqrt((P.x - Q.x) * (P.x - Q.x) + (P.y - Q.y) * (P.y - Q.y));
}

void Nhap(TAMGIAC& t) {
	cout << "Nhap A: ";
	Nhap(t.A);
	cout << "Nhap B: ";
	Nhap(t.B);
	cout << "Nhap C: ";
	Nhap(t.C);
}
void Xuat(TAMGIAC t)
{
	cout << "\n A: ";
	Xuat(t.A);
	cout << "\n B: ";
	Xuat(t.B);
	cout << "\n C: ";
	Xuat(t.C);
}

float ChuVi(TAMGIAC t)
{
	float a = KhoangCach(t.B, t.C);
	float b = KhoangCach(t.C, t.A);
	float c = KhoangCach(t.A, t.B);
	return (a + b + c);
}

float DienTich(TAMGIAC t)
{
	float a = KhoangCach(t.B, t.C);
	float b = KhoangCach(t.C, t.A);
	float c = KhoangCach(t.A, t.B);
	float p = (a + b + c) / 2;
	return sqrt(p * (p - a) * (p - b) * (p - c));
}

DIEM TrongTam(TAMGIAC t)
{
	DIEM temp;
	temp.x = (t.A.x + t.B.x + t.C.x) / 3;
	temp.y = (t.A.y + t.B.y + t.C.y) / 3;
	return temp;
}
