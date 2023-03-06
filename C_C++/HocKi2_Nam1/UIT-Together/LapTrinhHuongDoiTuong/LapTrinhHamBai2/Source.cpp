#include <iostream>
#include<cmath>
using namespace std;
struct diemkg
{
	float x;
	float y;
	float z;
};
typedef struct diemkg DIEMKG;

void Nhap(DIEMKG&);
void Xuat(DIEMKG);
float KhoangCach(DIEMKG, DIEMKG);


int main()
{
	DIEMKG A, B;
	Nhap(A);
	Nhap(B);
	float kq = KhoangCach(A, B);
	Xuat(A);
	Xuat(B);
	cout << "\nKet qua: " << kq;
	return 1;
}

float KhoangCach(DIEMKG P, DIEMKG Q)
{
	return sqrt((Q.x - P.x) * (Q.x - P.x) + (Q.y - P.y) * (Q.y - P.y) + (Q.z - P.z) * (Q.z - P.z));
}

void Xuat(DIEMKG P)
{
	cout << "\n x = " << P.x;
	cout << "\n y = " << P.y;
	cout << "\n z = " << P.z;
}

void Nhap(DIEMKG& P) 
{
	cout << "Nhap x: "; 
	cin >> P.x;
	cout << "Nhap y: "; 
	cin >> P.y;
	cout << "Nhap z: ";
	cin >> P.z;
}
