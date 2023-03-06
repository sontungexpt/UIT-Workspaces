#include <iostream>

using namespace std;

int GiaiThua(int);

int main()
{
	int n;
	cout << "Nhap n:";
	cin >> n;
	int kq = GiaiThua(n);
	cout << "Tong la: " << kq;
	return 0;
}

int GiaiThua(int nn)
{
	if (nn == 1)
		return 1;
	return (GiaiThua(nn - 1) * nn);
}
