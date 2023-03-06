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
PHANSO Tong(PHANSO, PHANSO);
PHANSO Hieu(PHANSO, PHANSO);
PHANSO Tich(PHANSO, PHANSO);
PHANSO Thuong(PHANSO, PHANSO);


int main()
{
	PHANSO a, b, kq;
	cout << "\nNhap phan so thu 1:";
	Nhap(a);
	cout << "\nNhap phan so thu 2:";
	Nhap(b);
	kq = Tong(a, b);
	cout << "\n Tong hai phan so:";
	Xuat(kq);
	kq = Hieu(a, b);
	cout << "\n Hieu hai phan so:";
	Xuat(kq);
	kq = Tich(a, b);
	cout << "\n Tich hai phan so:";
	Xuat(kq);
	kq = Thuong(a, b);
	cout << "\n Thuong hai phan so:";
	Xuat(kq);
	return 1;
}


void Xuat(PHANSO x)
{
	cout << "\n Tu:" << x.tu;
	cout << "\n Mau: " << x.mau;
}

void Nhap(PHANSO& x)
{
	cout << "Nhap tu:";

	cout << "Nhap mau:";
	cin >> x.mau;
}

PHANSO Tong(PHANSO x, PHANSO y)
{
	PHANSO temp;
	temp.tu = x.tu * y.mau + x.mau * y.tu;
	temp.mau = x.mau * y.mau;
	return temp;
}

PHANSO Hieu(PHANSO x, PHANSO y)
{
	PHANSO temp;
	temp.tu = x.tu * y.mau - x.mau * y.tu;
	temp.mau = x.mau * y.mau;
	return temp;
}

PHANSO Tich(PHANSO x, PHANSO y)
{
	PHANSO temp;
	temp.tu = x.tu * y.tu;
	temp.mau = x.mau * x.mau;
	return temp;
}

PHANSO Thuong(PHANSO x, PHANSO y)
{
	PHANSO temp;
	temp.tu = x.tu * y.mau;
	temp.mau = x.mau * y.tu;
	return temp;
}
