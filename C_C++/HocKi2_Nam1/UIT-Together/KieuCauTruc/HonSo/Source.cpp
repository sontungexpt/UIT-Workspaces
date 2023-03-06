#include <iostream>

using namespace std;

struct honso
{
	int Nguyen;
	int Tu;
	int Mau;
};
typedef struct honso HONSO;

void Nhap(HONSO&);
void Xuat(HONSO);
void RutGon(HONSO&);
int Gcd(int, int);
HONSO Tong(HONSO, HONSO);
HONSO Hieu(HONSO, HONSO);
HONSO Tich(HONSO, HONSO);
HONSO Thuong(HONSO, HONSO);
bool KtToiGian(HONSO);
void QuiDongMau(HONSO&, HONSO&);
void QuiDongTu(HONSO&, HONSO&);


int main()
{
	HONSO a;
	cout << "Nhap hon so a: ";
	Nhap(a);
	cout << "\nHon so a ban dau la: \n";
	Xuat(a);
	RutGon(a);
	cout << "\nHon so a sau khi rut gon la: \n";
	Xuat(a);
	HONSO b;
	cout << "\nNhap hon so b: \n";
	Nhap(b);
	HONSO c;
	cout << "\nNhap hon so c: \n";
	Nhap(c);
	cout << "\nTong hai hon so la: ";
	Xuat(Tong(b, c));
	cout << "\nHieu hai hon so la: ";
	Xuat(Hieu(b, c));
	cout << "\nTich hai hon so la: ";
	Xuat(Tich(b, c));
	cout << "\nThuong hai hon so la: ";
	Xuat(Thuong(b, c));
	if (KtToiGian(a) == true)
		cout << "\na la hon so toi gian";
	else
		cout << "\\na khong la hon so toi gian";
	HONSO d;
	cout << "\nNhap hon so d: \n";
	Nhap(d);
	HONSO e;
	cout << "\nNhap hon so e: \n";
	Nhap(e);
	QuiDongMau(d, e);
	cout << "\nHon so d sau khi quy dong mau la: ";
	Xuat(d);
	cout << "\nHon so e sau khi quy dong mau la: ";
	Xuat(e);
	HONSO f;
	cout << "\nNhap hon so f: \n";
	Nhap(f);
	HONSO g;
	cout << "\nNhap hon so g: \n";
	Nhap(g);
	QuiDongTu(f, g);
	cout << "\nHon so d sau khi quy dong tu la: ";
	Xuat(f);
	cout << "\nHon so e sau khi quy dong tu la: ";
	Xuat(g);
}

void Nhap(HONSO& x)
{
	cout << "Nhap nguyen: ";
	cin >> x.Nguyen;
	cout << "Nhap tu: ";
	cin >> x.Tu;
	cout << "Nhap mau: ";
	cin >> x.Mau;
}

void Xuat(HONSO x)
{
	cout << "\nNguyen: " << x.Nguyen;
	cout << "\nTu: " << x.Tu;
	cout << "\nMau: " << x.Mau;
}

int Gcd(int a, int b)
{
	a = abs(a);
	b = abs(b);
	while (a != b)
	{
		if (a > b)
			a = a - b;
		else
			b = b - a;
	}
	return a;

}

void RutGon(HONSO& x)
{
	int gcd = Gcd(x.Tu, x.Mau);
	x.Tu = x.Tu / gcd;
	x.Mau = x.Mau / gcd;
	x.Nguyen = x.Nguyen + x.Tu / x.Mau;
	x.Tu = x.Tu % x.Mau;
}

HONSO Tong(HONSO x, HONSO y)
{
	HONSO result;
	result.Nguyen = x.Nguyen + y.Nguyen;
	result.Tu = x.Tu * y.Mau + y.Tu * x.Mau;
	result.Mau = x.Mau * y.Mau;
	RutGon(result);
	return result;
}

HONSO Hieu(HONSO x, HONSO y)
{
	HONSO result;
	result.Nguyen = x.Nguyen - y.Nguyen;
	result.Tu = x.Tu * y.Mau - y.Tu * x.Mau;
	result.Mau = x.Mau * y.Mau;
	RutGon(result);
	return result;
}

HONSO Tich(HONSO x, HONSO y)
{
	x.Tu = x.Nguyen * x.Mau + x.Tu;
	x.Nguyen = 0;
	y.Tu = y.Nguyen * y.Mau + y.Tu;
	y.Nguyen = 0;
	HONSO result;
	result.Tu = x.Tu * y.Tu;
	result.Mau = x.Mau * y.Mau;
	result.Nguyen = 0;
	RutGon(result);
	return result;
}

HONSO Thuong(HONSO x, HONSO y)
{
	x.Tu = x.Nguyen * x.Mau + x.Tu;
	x.Nguyen = 0;
	y.Tu = y.Nguyen * y.Mau + y.Tu;
	y.Nguyen = 0;
	HONSO result;
	result.Tu = x.Tu * y.Mau;
	result.Mau = x.Mau * y.Tu;
	result.Nguyen = 0;
	RutGon(result);
	return result;
}

bool KtToiGian(HONSO x)
{
	if (Gcd(x.Tu, x.Mau) == 1 && x.Tu / x.Mau == 0)
		return 1;
	return 0;
}

void QuiDongMau(HONSO& x, HONSO& y)
{
	int mc = x.Mau * y.Mau;
	x.Tu = x.Tu * y.Mau;
	y.Tu = x.Mau * y.Tu;
	x.Mau = mc;
	y.Mau = mc;
}

void QuiDongTu(HONSO& x, HONSO& y)
{
	int tc = x.Tu * y.Tu;
	x.Mau = x.Mau * y.Tu;
	y.Mau = y.Mau * x.Tu;
	x.Tu = tc;
	y.Tu = tc;
}