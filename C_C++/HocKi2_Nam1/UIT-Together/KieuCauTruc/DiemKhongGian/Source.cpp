#include <iostream>
using namespace std;

struct diemkhonggian
{
	float x;
	float y;
	float z;
};
typedef struct diemkhonggian DIEMKHONGGIAN;

void Nhap(DIEMKHONGGIAN&);
void Xuat(DIEMKHONGGIAN);
float KhoangCach(DIEMKHONGGIAN, DIEMKHONGGIAN);
float KhoangCachX(DIEMKHONGGIAN, DIEMKHONGGIAN);
float KhoangCachY(DIEMKHONGGIAN, DIEMKHONGGIAN);
float KhoangCachZ(DIEMKHONGGIAN, DIEMKHONGGIAN);
float KhoangCachGoc(DIEMKHONGGIAN);
DIEMKHONGGIAN DoiXungGoc(DIEMKHONGGIAN);
DIEMKHONGGIAN DoiXungOxy(DIEMKHONGGIAN);
DIEMKHONGGIAN DoiXungOyz(DIEMKHONGGIAN);
DIEMKHONGGIAN DoiXungOxz(DIEMKHONGGIAN);
bool KtTrung(DIEMKHONGGIAN, DIEMKHONGGIAN);

int main()
{
	DIEMKHONGGIAN A;
	DIEMKHONGGIAN B;
	cout << "Nhap toa do diem A:\n";
	Nhap(A);
	cout << "\nDiem A la:";
	Xuat(A);
	cout << "\n\nNhap toa do diem B:\n";
	Nhap(B);
	cout << "\nDiem B la:";
	Xuat(B);
	cout << "\n\nKhoang cach AB la: " << KhoangCach(A, B);
	cout << "\n\nKhoang cach X cua A la: " << KhoangCachX(A, B);
	cout << "\n\nKhoang cach Y cua A la: " << KhoangCachY(A, B);
	cout << "\n\nKhoang cach Z cua A la: " << KhoangCachZ(A, B);
	cout << "\n\nToa do diem doi xung qua goc toa do cua A la: ";
	Xuat(DoiXungGoc(A));
	cout << "\n\nToa do diem doi xung qua Oxy cua A la: ";
	Xuat(DoiXungOxy(A));
	cout << "\n\nToa do diem doi xung qua Oyz cua A la: ";
	Xuat(DoiXungOyz(A));
	cout << "\n\nToa do diem doi xung qua Oxz cua A la: ";
	Xuat(DoiXungOxz(A));
	if (KtTrung(A, B) == true)
		cout << "A trung B";
	else
		cout << "A  khong trung B";
	return 1;
}

void Nhap(DIEMKHONGGIAN& P)
{
	cout << "Nhap x: ";
	cin >> P.x;
	cout << "Nhap y: ";
	cin >> P.y;
	cout << "Nhap z: ";
	cin >> P.z;
}

void Xuat(DIEMKHONGGIAN P)
{
	cout << "\nx = " << P.x;
	cout << "\ny = " << P.y;
	cout << "\nz = " << P.z;
}

float KhoangCach(DIEMKHONGGIAN P, DIEMKHONGGIAN Q)
{
	return sqrt((Q.x - P.x) * (Q.x - P.x) + (Q.y - P.y) * (Q.y - P.y) + (Q.z - P.z) * (Q.z - P.z));
}

float KhoangCachX(DIEMKHONGGIAN P, DIEMKHONGGIAN Q)
{
	return abs(Q.x - P.x);
}
float KhoangCachY(DIEMKHONGGIAN P, DIEMKHONGGIAN Q)
{
	return abs(Q.y - P.y);
}

float KhoangCachZ(DIEMKHONGGIAN P, DIEMKHONGGIAN Q)
{
	return abs(Q.z - P.z);
}

float KhoangCachGoc(DIEMKHONGGIAN P)
{
	return sqrt(P.x * P.x + P.y * P.y + P.z * P.z);
}

DIEMKHONGGIAN DoiXungGoc(DIEMKHONGGIAN P)
{
	DIEMKHONGGIAN Q;
	Q.x = -P.x;
	Q.y = -P.y;
	Q.z = -P.z;
	return Q;
}

DIEMKHONGGIAN DoiXungOxy(DIEMKHONGGIAN P)
{
	DIEMKHONGGIAN Q;
	Q.x = P.x;
	Q.y = P.y;
	Q.z = -P.z;
	return Q;
}
DIEMKHONGGIAN DoiXungOyz(DIEMKHONGGIAN P)
{
	DIEMKHONGGIAN Q;
	Q.x = -P.x;
	Q.y = P.y;
	Q.z = P.z;
	return Q;
}
DIEMKHONGGIAN DoiXungOxz(DIEMKHONGGIAN P)
{
	DIEMKHONGGIAN Q;
	Q.x = P.x;
	Q.y = -P.y;
	Q.z = P.z;
	return Q;
}

bool KtTrung(DIEMKHONGGIAN P, DIEMKHONGGIAN Q)
{
	if (P.x == Q.x && P.y == Q.y && P.z == Q.z)
		return 1;
	return 0;
}