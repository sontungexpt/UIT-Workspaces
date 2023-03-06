#include <iostream>

using namespace std;

struct monomial
{
	float a;
	int n;
};
typedef struct monomial MONOMIAL;

void Input(MONOMIAL&);
void Print(MONOMIAL);
MONOMIAL Product(MONOMIAL, MONOMIAL);
MONOMIAL Quotient(MONOMIAL, MONOMIAL);
MONOMIAL Derivatives(MONOMIAL);
MONOMIAL Derivatives(MONOMIAL, int&);
float GetValue(MONOMIAL, float&);
MONOMIAL operator *(MONOMIAL, MONOMIAL);
MONOMIAL operator /(MONOMIAL, MONOMIAL);

int main()
{
	MONOMIAL f;
	MONOMIAL g;
	int k;
	float x;
	cout << "Nhap don thuc 1: \n";
	Input(f);
	cout << "\nDon thuc f vua nhap la: ";
	Print(f);
	cout << "\nNhap don thuc 2: \n";
	Input(g);
	cout << "\nDon thuc g vua nhap la: ";
	Print(g);
	cout << "\nTich cua hai don thuc f va g la: ";
	Print(Product(f, g));
	cout << "\nThuong cua hai don thuc f va g la: ";
	Print(Quotient(f, g));
	cout << "\nDon thuc f sau khi dao ham cap 1 la: ";
	Print(Derivatives(f));
	cout << "\nDon thuc f sau khi dao ham cap k la: ";
	Print(Derivatives(f, k));
	float value = GetValue(f, x);
	cout << "\nGia tri cua don thuc tai x = " << x << ": "<<value;
	cout << "\nTich cua hai don thuc f va g la: ";
	Print(f*g);
	cout << "\nThuong cua hai don thuc f va g la: ";
	Print(f / g);
	return 0;
}

void Input(MONOMIAL& f)
{
	cout << "Nhap he so: ";
	cin >> f.a;
	cout << "Nhap so mu: ";
	cin >> f.n;
}

void Print(MONOMIAL f)
{
	cout << f.a << "x^" << f.n;
}

MONOMIAL Product(MONOMIAL f, MONOMIAL g)
{
	MONOMIAL result;
	result.a = f.a * g.a;
	result.n = f.n + g.n;
	return result;
}

MONOMIAL Quotient(MONOMIAL f, MONOMIAL g)
{
	MONOMIAL result;
	result.a = f.a / g.a;
	result.n = f.n - g.n;
	return result;
}

MONOMIAL Derivatives(MONOMIAL f)
{
	MONOMIAL result;
	result.a = f.a * f.n;
	result.n = f.n - 1;
	return result;
}

MONOMIAL Derivatives(MONOMIAL f, int &k)
{
	cout << "Nhap cap cua dao ham: ";
	cin >> k;
	MONOMIAL result = f;
	for (int i = 1; i <= k; i++)
		result = Derivatives(result);
	return result;
}

float GetValue(MONOMIAL f, float &x)
{
	cout << "Nhap x0: ";
	cin >> x;
	return f.a * pow(x, f.n);
}

MONOMIAL operator *(MONOMIAL f, MONOMIAL g)
{
	MONOMIAL result;
	result.a = f.a * g.a;
	result.n = f.n + g.n;
	return result;
}

MONOMIAL operator /(MONOMIAL f, MONOMIAL g)
{
	MONOMIAL result;
	result.a = f.a / g.a;
	result.n = f.n - g.n;
	return result;
}