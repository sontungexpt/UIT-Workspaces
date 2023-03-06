#include <iostream>
#include <cmath>
using namespace std;
struct Diem
{
	float x;
	float y;
};
typedef struct Diem DIEM;

void Nhap(DIEM&); 
void Xuat(DIEM);
float KhoangCach(DIEM, DIEM);

int main()
{
	DIEM A, B;
	Nhap(A);
	Nhap(B);
	float kq = KhoangCach(A, B);
	Xuat(A);
	Xuat(B);
	cout << "\n Ket Qua = " << kq;
	return 1;
}

void Xuat(DIEM P)
{
	cout << "\n x = " << P.x;
	cout << "\n y = " << P.y;
}
float KhoangCach(DIEM P, DIEM Q)
{
	return sqrt((Q.x - P.x) * (Q.x - P.x) +
		(Q.y - P.y) * (Q.y - P.y));
}

void Nhap(DIEM& P)
{
	cout << "Nhap x:";
	cin >> P.x;
	cout << "Nhap y:";
	cin >> P.y;
}