#include <iostream>

using namespace std;


//begin ex087
struct fraction
{
	int numerator;
	int denominator;
};
typedef struct fraction FRACTION;
//end ex087

void Input(FRACTION&);
void Print(FRACTION);
FRACTION ShortenFraction(FRACTION);
int Gcd(int, int);
FRACTION Sum(FRACTION, FRACTION);
FRACTION Different(FRACTION, FRACTION);
FRACTION Product(FRACTION, FRACTION);
FRACTION Quotient(FRACTION, FRACTION);
bool isInvalidFraction(FRACTION);
bool isMinimalistFraction(FRACTION);
bool isPositiveFraction(FRACTION);
bool isNegativeFraction(FRACTION);
void QuyDongMau(FRACTION &, FRACTION &);
void QuyDongTu(FRACTION&, FRACTION&);
int Compare(FRACTION, FRACTION);
FRACTION operator+(FRACTION, FRACTION);
FRACTION operator-(FRACTION, FRACTION);
FRACTION operator*(FRACTION, FRACTION);
FRACTION operator/(FRACTION, FRACTION);


int main()
{
	FRACTION a;
	FRACTION b;
	cout << "Nhap phan so a: \n";
	Input(a);
	cout << "\nPhan so vua nhap la: ";
	Print(a);
	cout << "\nNhap phan so b: \n";
	Input(b);
	cout << "\nPhan so a sau khi duoc rut gon la: ";
	Print(ShortenFraction(a));
	cout << "\nTong hai phan so a va b la: ";
	Print(Sum(a, b));
	cout << "\nHIeu hai phan so a va b la: ";
	Print(Different(a, b));
	cout << "\nTich hai phan so a va b la: ";
	Print(Product(a, b));
	cout << "\nThuong hai phan so a va b la: ";
	Print(Quotient(a, b));
	if (isInvalidFraction(a) == true)
		cout << "\nPhan so a co nghia.";
	else
		cout << "\nPhan so a khong co nghia";
	if (isMinimalistFraction(a) == true)
		cout << "\nPhan so a toi gian";
	else 
		cout << "\nPhan so a chua toi gian";
	if (isPositiveFraction(a) == true)
		cout << "\nPhan so a duong";
	else
		cout << "Phan so a am";
	if (isNegativeFraction(a) == true)
		cout << "\nPhan so a am";
	else
		cout << "\nPhan so a duong";

	FRACTION c;
	FRACTION d;
	cout << "\nNhap phan so c: \n";
	Input(c);
	cout << "\nNhap phan so d: \n";
	Input(d);
	QuyDongMau(c, d);
	cout << "\nPhan so c sau khi quy dong mau la: ";
	Print(c);
	cout << "\nPhan so d sau khi quy dong mau la: ";
	Print(d);

	FRACTION e;
	FRACTION f;
	cout << "\nNhap phan so e: \n";
	Input(e);
	cout << "\nNhap phan so f: \n";
	Input(f);
	QuyDongTu(e, f);
	cout << "\nPhan so e sau khi quy dong tu la: ";
	Print(e);
	cout << "\nPhan so f sau khi quy dong tula: ";
	Print(f);
	
	FRACTION l;
	FRACTION m;
	cout << "\nNhap phan so l: \n";
	Input(l);
	cout << "\nNhap phan so m: \n";
	Input(m);
	cout << "\nKet qua sau khi nap chong toan tu cong cua l va m: ";
	Print(l+m);
	cout << "\nKet qua sau khi nap chong toan tu tru cua l va m: ";
	Print(l - m);
	cout << "\nKet qua sau khi nap chong toan tu nhan cua l va m: ";
	Print(l * m);
	cout << "\nKet qua sau khi nap chong toan tu chia cua l va m: ";
	Print(l / m);
}

//begin ex088
void Input(FRACTION& frac)
{
	cout << "Nhap tu: ";
	cin >> frac.numerator;
	cout << "Nhap mau: ";
	cin >> frac.denominator;
}
//end ex088

//begin ex089
void Print(FRACTION frac)
{
	cout << frac.numerator << "/" << frac.denominator;
}
//end ex089

//begin ex090
int Gcd(int a, int b)
{
	a = abs(a);
	b = abs(b);
	while (a * b != 0)
	{
		if (a > b)
			a %= b;
		else
			b %= a;
	}
	return a + b;
}

FRACTION ShortenFraction(FRACTION frac)
{
	FRACTION result;
	int gcd = Gcd(frac.numerator, frac.denominator);
	result.numerator = frac.numerator / gcd;
	result.denominator = frac.denominator / gcd;
	return result;
}
//end ex090

//begin ex091
FRACTION Sum(FRACTION aa, FRACTION bb)
{
	FRACTION sum;
	sum.numerator = aa.numerator * bb.denominator + bb.numerator * aa.denominator;
	sum.denominator = aa.denominator * bb.denominator;
	sum = ShortenFraction(sum);
	return sum;
}
//end ex091

//begin ex092
FRACTION Different(FRACTION aa, FRACTION bb)
{
	FRACTION different;
	different.numerator = aa.numerator * bb.denominator - bb.numerator * aa.denominator;
	different.denominator = aa.denominator * bb.denominator;
	different = ShortenFraction(different);
	return different;
}
//end ex092

//begin ex093
FRACTION Product(FRACTION aa, FRACTION bb)
{
	FRACTION product;
	product.numerator = aa.numerator * bb.numerator;
	product.denominator = aa.denominator * bb.denominator;
	product = ShortenFraction(product);
	return product;
}
//end ex093

//begin ex094
FRACTION Quotient(FRACTION aa, FRACTION bb)
{
	FRACTION quotient;
	quotient.numerator = aa.numerator * bb.denominator;
	quotient.denominator = aa.denominator * bb.numerator;
	quotient= ShortenFraction(quotient);
	return quotient;
}
//end ex 094

//begin ex095
bool isInvalidFraction(FRACTION aa)
{
	if (aa.denominator != 0)
		return 1;
	return 0;
}
//end ex095

//begin ex096
bool isMinimalistFraction(FRACTION aa)
{
	if (Gcd(aa.numerator, aa.denominator) == 1)
		return 1;
	return 0;
}
//end ex096

//begin ex097
bool isPositiveFraction(FRACTION aa)
{
	if (aa.numerator * aa.denominator > 0)
		return 1;
	return 0;
}
//end ex097

//begin ex098
bool isNegativeFraction(FRACTION aa)
{
	if (aa.numerator * aa.denominator < 0)
		return 1;
	return 0;
}
//end ex098

//begin ex099
void QuyDongMau(FRACTION &aa, FRACTION &bb)
{
	int commonDenominator = aa.denominator * bb.denominator;
	aa.numerator = aa.numerator *bb.denominator;
	bb.numerator = aa.denominator * bb.numerator;
	aa.denominator = commonDenominator;
	bb.denominator = commonDenominator;
}
//end ex099


//begin ex100
void QuyDongTu(FRACTION& aa, FRACTION& bb)
{
	int commonNumerator = aa.numerator * bb.numerator;
	aa.denominator = aa.denominator * bb.numerator;
	bb.denominator = bb.denominator * aa.numerator;
	aa.numerator = commonNumerator;
	bb.numerator = commonNumerator;
}

//begin ex101
int Compare(FRACTION P, FRACTION Q)
{
	float a = (float)P.numerator / P.denominator;
	float b = (float)Q.numerator / Q.denominator;

	if (a > b)
		return 1;
	else if (a < b)
		return -1;
	return 0;
}
//end ex101

//begin ex102
FRACTION operator+(FRACTION a, FRACTION b)
{
	FRACTION temp;
	temp.numerator = a.numerator * b.denominator + b.numerator * a.denominator;
	temp.denominator = a.denominator * b.denominator;
	ShortenFraction(temp);
	return temp;
}
FRACTION operator-(FRACTION a, FRACTION b)
{
	FRACTION temp;
	temp.numerator = a.numerator * b.denominator - b.numerator * a.denominator;
	temp.denominator = a.denominator * b.denominator;
	ShortenFraction(temp);
	return temp;
}
FRACTION operator*(FRACTION a, FRACTION b)
{
	FRACTION temp;
	temp.numerator = a.numerator * b.numerator;
	temp.denominator = a.denominator * b.denominator;
	ShortenFraction(temp);
	return temp;
}
FRACTION operator/(FRACTION a, FRACTION b)
{
	FRACTION temp;
	temp.numerator = a.numerator * b.denominator;
	temp.denominator = a.denominator * b.numerator;
	ShortenFraction(temp);
	return temp;
}