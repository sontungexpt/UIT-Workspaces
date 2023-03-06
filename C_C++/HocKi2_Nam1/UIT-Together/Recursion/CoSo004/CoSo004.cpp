#include <iostream>

using namespace std;

int TongChan(int);
int Nhap(int);
int Nhap(float&, int&);

int main()
{
	int n;
	cout << "Nhap n:";
	cin >> n;;
	int kq = TongChan(n);
	cout << "Luy Thua la: " << kq;
	return 0;
}

int TongChan(int nn)
{
	nn = abs(nn);
	if (nn == 0)
		return 0;
	int s = TongChan(nn / 10);
	int dv = n % 10;
	if (dv % 2 == 0)
		s += dv;
	return s;
}
