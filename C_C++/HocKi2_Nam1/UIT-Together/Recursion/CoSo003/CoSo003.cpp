#include <iostream>

using namespace std;

int LuyThua(float, int);
int Nhap(float&, int&);

int main()
{
	float x;
	int n;
	Nhap(x, n);
	int kq = LuyThua(x,n);
	cout << "Luy Thua la: " << kq;
	return 0;
}
int Nhap(float& xx, int& nn)
{
	cout << "Nhap x:";
	cin >> xx;
	cout << "Nhap n:";
	cin >> nn;
}
int LuyThua(float xx, int nn)
{
	if (nn == 1)
		return xx;
	return (LuyThua(xx,nn - 1) * xx);
}
