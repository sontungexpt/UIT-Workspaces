#include <iostream>
#include <math.h>

using namespace std;

struct diemkhonggian
{
	float x;
	float y;
	float z;

};
typedef struct diemkhonggian DIEMKHONGGIAN;

struct hinhcau
{
	DIEMKHONGGIAN I;
	float R;
};
typedef struct hinhcau HINHCAU;

void Nhap(HINHCAU&);
void Nhap(DIEMKHONGGIAN&);
void Xuat(HINHCAU);
void Xuat(DIEMKHONGGIAN);
float DienTich(HINHCAU);
float TheTich(HINHCAU);
int KtThuoc(HINHCAU, DIEMKHONGGIAN);
int TuongDoi(HINHCAU, HINHCAU);
float KhoangCach(DIEMKHONGGIAN, DIEMKHONGGIAN);

int main()
{
	HINHCAU a;
	HINHCAU b;
	Nhap(a);
	Xuat(a);
	Nhap(b);
	Xuat(b);
	cout << "\nDien tich: " << DienTich(a);
	cout << "\nThe tich: " << TheTich(a);
	cout << "Nhap diem b: ";
	DIEMKHONGGIAN c;
	Nhap(c);
	if (KtThuoc(a, c) == 1)
		cout << "\nB thuoc hinh cau";
	else
		cout << "\nB khong thuoc hinh cau";
	int result = TuongDoi(a, b);
	if (result == 0)
		cout << "Trung nhau";
	else if (result == 1)
		cout << "Roi nhau";
	else if (result == 2)
		cout << "Tiep xuc ngoai";
	else if (result == 3)
		cout << "Cat nhau";
	else if (result == 4)
		cout << "Tiep xuc trong";
	else
		cout << "Chua trong nhau";

	cout << "Khoang cach hai hinh cau la: " << KhoangCach(a.I, b.I);

}

void Nhap(HINHCAU& c)
{
	cout << "Nhap tam:\n";
	Nhap(c.I);
	cout << "Nhap ban kinh: ";
	cin >> c.R;
}
void Nhap(DIEMKHONGGIAN& A)
{
	cout << "Nhap x: ";
	cin >> A.x;
	cout << "Nhap y: ";
	cin >> A.y;
	cout << "Nhap z: ";
	cout << A.z;
}

void Xuat(DIEMKHONGGIAN A)
{
	cout << "\nX la: "<<A.x;
	cout << "\nY la: " << A.y;
	cout << "\nZ la: " << A.z;
}
void Xuat(HINHCAU c)
{
	cout << "\nTam:";
	Xuat(c.I);
	cout << "\nBan kinh: " << c.R;
}

float DienTich(HINHCAU c)
{
	return float(4 * 3.14 * c.R * c.R);
}

float TheTich(HINHCAU c)
{
	return float((float)4 / 3 * 3.14 * c.R *
		c.R * c.R);
}

int KtThuoc(HINHCAU c, DIEMKHONGGIAN P)
{
	float kc = KhoangCach(c.I, P);
	if (kc <= c.R)
		return 1;
	return 0;
}

int TuongDoi(HINHCAU c1, HINHCAU c2)
{
	float kc = KhoangCach(c1.I, c2.I);
	if (kc == 0 && c1.R == c2.R)
		return 0;
	else if (kc > (c1.R + c2.R))
		return 1;
	else if (kc == (c1.R + c2.R))
		return 2;
	else if (kc < (c1.R + c2.R) && kc>abs(c1.R - c2.R))
		return 3;
	else if (kc == abs(c1.R - c2.R))
		return 4;
	return 5;
}

float KhoangCach(DIEMKHONGGIAN A, DIEMKHONGGIAN B)
{
	return sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y) + (A.z - B.z) * (A.z - B.z));
}