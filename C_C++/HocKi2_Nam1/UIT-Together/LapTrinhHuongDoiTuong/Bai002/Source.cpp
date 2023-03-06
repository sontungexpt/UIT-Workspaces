#include <iostream>
#include <string>
using namespace std;

class Fraction
{
private:
	int numerator;
	int denominator;
public:
	void Input();
	Fraction Shorten();
	void Print();
	int XetDau();
	int CompareWith(Fraction);
	Fraction Plus(Fraction);
	Fraction Minus(Fraction);
	Fraction MultipliedBy(Fraction);
	Fraction DivideBy(Fraction);
};

int main()
{
	Fraction ps1;
	Fraction ps2;
	cout << "Nhap phan so 1:\n";
	ps1.Input();
	cout << "\nNhap phan so 2:\n";
	ps2.Input();
	cout << "\nPhan so 1 la: ";
	ps1.Print();
	cout << "\nPhan so 2 la: ";
	ps2.Print();
	cout << "\nPhan so 1 sau khi rut gon la: ";
	ps1.Shorten().Print();
	
	int kq = ps1.XetDau();
	if (kq == 1)
		cout << "\nPhan so duong";
	else if(kq == -1)
		cout << "\nPhan so am";
	else 
		cout << "\nPhan so bang 0";

	kq = ps1.CompareWith(ps2);
	if (kq == 1)
		cout << "\nPhan so 1 > Phan so 2";
	else if (kq == -1)
		cout << "\nPhan so 1 < Phan so 2";
	else
		cout << "\nPhan so 1 = Phan so 2";

	cout << "\nTong phan so 1 va 2 la: ";
	ps1.Plus(ps2).Print();
	cout << "\nHieu phan so 1 va 2 la: ";
	ps1.Minus(ps2).Print();
	cout << "\nTich phan so 1 va 2 la: ";
	ps1.MultipliedBy(ps2).Print();
	cout << "\nThuong phan so 1 va 2 la: ";
	ps1.DivideBy(ps2).Print();
	return 1;
}

void Fraction::Input()
{
	cout << "Nhap tu: ";
	cin >> numerator;
	cout << "Nhap mau: ";
	cin >> denominator;
}
Fraction Fraction::Shorten()
{
	Fraction result;
	int a = abs(numerator);
	int b = abs(denominator);
	while (a != b)
	{
		if (a > b)
			a = a - b;
		else
			b = b - a;
	}
	result.numerator = numerator / a;
	result.denominator = denominator /a;
	return result;
}

void Fraction::Print()
{
	if(numerator*denominator < 0)
		cout << "-" << abs(numerator) << "/" << abs(denominator);
	else 
		cout << abs(numerator) << "/" << abs(denominator);
}

int Fraction::XetDau()
{
	if (numerator * denominator > 0)
		return 1;
	if (numerator * denominator < 0)
		return -1;
	return 0;
}

int Fraction::CompareWith(Fraction B)
{
	float a = (float)numerator / denominator;
	float b = (float)B.numerator / B.denominator;
	if (a > b)
		return 1;
	if (a < b)
		return -1;
	return 0;
}

Fraction Fraction::Plus(Fraction B)
{
	Fraction sum;
	sum.numerator = numerator * B.denominator + denominator * B.numerator;
	sum.denominator = denominator * B.denominator;
	return sum.Shorten();
}
Fraction Fraction::Minus(Fraction B)
{
	Fraction different;
	different.numerator = numerator * B.denominator - denominator * B.numerator;
	different.denominator = denominator * B.denominator;
	return different.Shorten();
}
Fraction Fraction::MultipliedBy(Fraction B)
{
	Fraction product;
	product.numerator = numerator * B.numerator;
	product.denominator = denominator * B.denominator;
	return product.Shorten();
}
Fraction Fraction::DivideBy(Fraction B)
{
	Fraction quotient;
	quotient.numerator = numerator * B.denominator;
	quotient.denominator = denominator * B.numerator;
	return quotient;
}