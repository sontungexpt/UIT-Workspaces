#include <iostream>

using namespace std;

int TinhAn(int);

int main()
{
	int n;
	cout << "Nhap n:";
	cin >> n;
	int s = TinhAn(n);
	cout << "Ket qua la: " << s;
	return 0;
}

int TinhAn(int nn)
{
	if (nn == 1)
		return 2;
	return TinhAn(nn - 1) + 2 * nn + 1;
}