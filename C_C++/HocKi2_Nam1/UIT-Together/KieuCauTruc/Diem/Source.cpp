#include <iostream>
using namespace std;

struct diem
{
	float x;
	float y;
};
typedef struct diem DIEM;

void Nhap(DIEM&);
void Xuat(DIEM);
float KhoangCach(DIEM, DIEM);
DIEM DoiXungGoc(DIEM);
DIEM DoiXungTung(DIEM);
DIEM DoiXungHoanh(DIEM);
DIEM DoiXungPhanGiac1(DIEM);
DIEM DoiXungPhanGiac2(DIEM);
bool KtPhanTu1(DIEM);
bool KtPhanTu2(DIEM);
bool KtPhanTu3(DIEM);
bool KtPhanTu4(DIEM);

int main()
{
	DIEM A;
	DIEM B;
	cout << "Nhap toa do diem A:\n";
	Nhap(A);
	cout << "\nDiem A la:";
	Xuat(A);
	cout << "\n\nNhap toa do diem B:\n";
	Nhap(B);
	cout << "\nDiem B la:";
	Xuat(B);
	float kq = KhoangCach(A, B);
	cout << "\n\nKhoang cach AB la: " << kq;
	cout << "\n\nToa do diem doi xung qua goc toa do cua A la: ";
	Xuat(DoiXungGoc(A));
	cout << "\n\nToa do diem doi xung qua tung do cua A la: ";
	Xuat(DoiXungTung(A));
	cout << "\n\nToa do diem doi xung qua hoanh do cua A la: ";
	Xuat(DoiXungHoanh(A));
	cout << "\n\nToa do diem doi xung qua phan giac 1 cua A la: ";
	Xuat(DoiXungPhanGiac1(A));
	cout << "\n\nToa do diem doi xung qua phan giac 2 cua A la: ";
	Xuat(DoiXungPhanGiac2(A));
	if (KtPhanTu1(A) == true)
		cout << "\nThuoc phan tu 1:";
	else 
		cout << "\nKhong thuoc phan tu 1:";
	if (KtPhanTu2(A) == true)
		cout << "\nThuoc phan tu 2:";
	else
		cout << "\nKhong thuoc phan tu 2:";
	if (KtPhanTu3(A) == true)
		cout << "\nThuoc phan tu 3:";
	else
		cout << "\nKhong thuoc phan tu 3:";
	if (KtPhanTu4(A) == true)
		cout << "Thuoc phan tu 4:";
	else
		cout << "\nKhong thuoc phan tu 4:";
	return 1;
}

void Nhap(DIEM& P)
{
	cout << "Nhap x: ";
	cin >> P.x;
	cout << "Nhap y: ";
	cin >> P.y;
}

void Xuat(DIEM P)
{
	cout << "\nx = " << P.x;
	cout << "\ny = " << P.y;
}

float KhoangCach(DIEM P, DIEM Q)
{
	return sqrt((Q.x - P.x) * (Q.x - P.x) + (Q.y - P.y) * (Q.y - P.y));
}

DIEM DoiXungGoc(DIEM P)
{
	DIEM Q;
	Q.x = -P.x;
	Q.y = -P.y;
	return Q;
}

DIEM DoiXungTung(DIEM P)
{
	DIEM Q;
	Q.x = -P.x;
	Q.y = P.y;
	return Q;
}
DIEM DoiXungHoanh(DIEM P) 
{
	DIEM Q;
	Q.x = P.x;
	Q.y = -P.y;
	return Q;
}
DIEM DoiXungPhanGiac1(DIEM P)
{
	DIEM Q;
	Q.x = P.y;
	Q.y = P.x;
	return Q;
}
DIEM DoiXungPhanGiac2(DIEM P)
{
	DIEM Q;
	Q.x = -P.y;
	Q.y = -P.x;
	return Q;
}
bool KtPhanTu1(DIEM P)
{
	if (P.x > 0 && P.y > 0)
		return 1;
	return 0;
}
bool KtPhanTu2(DIEM P)
{
	if (P.x < 0 && P.y > 0)
		return 1;
	return 0;
}

bool KtPhanTu3(DIEM P)
{
	if (P.x < 0 && P.y < 0)
		return 1;
	return 0;
}
bool KtPhanTu4(DIEM P)
{
	if (P.x > 0 && P.y < 0)
		return 1;
	return 0;
}