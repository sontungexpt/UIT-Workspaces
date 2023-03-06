#include <iostream>
#include <string>
using namespace std;

struct PhanSo
{
	int tu;
	int mau;
};
typedef struct PhanSo PHANSO;

void Nhap(PHANSO&);
void Xuat(PHANSO);
void RutGon(PHANSO&);
template<typename T>
T Gcd(T, T);
int XetDau(PHANSO);

int main()
{
	PHANSO ps;
	Nhap(ps);
	int kq = XetDau(ps);
	switch (kq)
	{
	case 1: cout << "Phan so > 0";
		break;

	case -1: cout << "Phan so < 0";
		break;
	case 0: cout << "Phan so = 0";
		break;
	}
	Xuat(ps);
	return 1;
}

void Xuat(PHANSO x)
{
	cout << "\n Tu:" << x.tu;
	cout << "\n Mau: " << x.mau;
}

template<typename T>
T Gcd(T x, T y)
{
	int a = abs(x);
	int b = abs(y);
	while (a != b)
	{
		if (a > b)
			a = a - b;
		else
			b = b - a;
	}
	return a;
}

void RutGon(PHANSO& x)
{
	int gcd = Gcd(x.tu, x.mau);
	x.tu = x.tu / gcd;
	x.mau = x.mau / gcd;

}
void Nhap(PHANSO& x)
{
	cout << "Nhap tu:";

	cout << "Nhap mau:";
	cin >> x.mau;
}

int XetDau(PHANSO x)
{
	if (x.tu * x.mau > 0)
		return 1;
	if (x.tu * x.mau < 0)
		return -1;
	return 0;
}
