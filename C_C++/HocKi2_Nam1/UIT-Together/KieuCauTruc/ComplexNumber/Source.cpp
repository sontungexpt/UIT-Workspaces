#include <iostream>
#include <math.h>

using namespace std;

struct complexnumber
{
	float realElement;
	float virtualElement;
};
typedef struct complexnumber COMPLEXNUMBER;

void Input(COMPLEXNUMBER&);
void Print(COMPLEXNUMBER);
float CalcModule(COMPLEXNUMBER);
COMPLEXNUMBER Sum(COMPLEXNUMBER, COMPLEXNUMBER);
COMPLEXNUMBER Different(COMPLEXNUMBER, COMPLEXNUMBER);
COMPLEXNUMBER Product(COMPLEXNUMBER, COMPLEXNUMBER);
COMPLEXNUMBER Quotient(COMPLEXNUMBER, COMPLEXNUMBER);
COMPLEXNUMBER LuyThua(COMPLEXNUMBER, int &);


int main()
{
	COMPLEXNUMBER A;
	COMPLEXNUMBER B;
	int n;
	cout << "Nhap so phuc A: \n";
	Input(A);
	cout << "\nPhan thuc A vua nhap la: \n";
	Print(A);
	cout << "\nSo phuc phuc B: \n";
	Input(B);
	cout << "\nSo phuc B vua nhap la: \n";
	Print(B);
	cout << "\nModule cua A la: " << CalcModule(A);
	cout << "\nTong hai so phuc A va B la: ";
	Print(Sum(A, B));
	cout << "\nHieu hai so phuc A va B la: ";
	Print(Different(A, B));
	cout << "\nTich hai so phuc A va B la: ";
	Print(Product(A, B));
	cout << "\nThuong hai so phuc A va B la: ";
	Print(Quotient(A, B));
	COMPLEXNUMBER result = LuyThua(A, n);
	cout << "A^" << n << " = ";
	Print(A);
	return 0;
}

void Input(COMPLEXNUMBER& n)
{
	cout << "Nhap phan thuc: ";
	cin >> n.realElement;
	cout << "Nhap phan ao: ";
	cin >> n.virtualElement;
}

void Print(COMPLEXNUMBER n)
{
	if (n.virtualElement > 0)
		cout << n.realElement << " + " << n.virtualElement << "i";
	else if (n.virtualElement < 0)
		cout << n.realElement << " - " << abs(n.virtualElement) << "i";
	else
		cout << n.realElement;
}

float CalcModule(COMPLEXNUMBER x)
{
	return sqrt(x.realElement * x.realElement + x.virtualElement * x.virtualElement);
}

COMPLEXNUMBER Sum(COMPLEXNUMBER x, COMPLEXNUMBER y)
{
	COMPLEXNUMBER result;
	result.realElement = x.realElement + y.realElement;
	result.virtualElement = x.virtualElement + x.virtualElement;
	return result;
}

COMPLEXNUMBER Different(COMPLEXNUMBER x, COMPLEXNUMBER y)
{
	COMPLEXNUMBER result;
	result.realElement = x.realElement - y.realElement;
	result.virtualElement = x.virtualElement - x.virtualElement;
	return result;
}

COMPLEXNUMBER Product(COMPLEXNUMBER x, COMPLEXNUMBER y)
{
	COMPLEXNUMBER result;
	result.realElement = x.realElement * y.realElement - x.virtualElement * x.virtualElement;
	result.virtualElement = x.realElement - y.virtualElement + x.virtualElement * y.realElement;
	return result;
}

COMPLEXNUMBER Quotient(COMPLEXNUMBER x, COMPLEXNUMBER y)
{
	float commonDenominator = y.realElement * y.realElement + y.virtualElement * y.virtualElement;
	COMPLEXNUMBER result;
	result.realElement = (x.realElement * y.realElement + x.virtualElement * x.virtualElement)/commonDenominator;
	result.virtualElement = (x.virtualElement * y.realElement - x.realElement * y.virtualElement)/commonDenominator;
	return result;
}

COMPLEXNUMBER LuyThua(COMPLEXNUMBER x, int &n)
{
	cout << "\nNhap so mu can tinh";
	cin >> n;
	COMPLEXNUMBER result = { 1,0 };
	for (int i = 1; i <= n; i++)
		result = Product(result, x);
	return result;
}