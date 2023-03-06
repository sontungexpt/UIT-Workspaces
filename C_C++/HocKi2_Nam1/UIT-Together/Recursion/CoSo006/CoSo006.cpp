#include <iostream>

using namespace std;

int DemChuSo(int);

int main()
{
	int n;
	cout << "Nhap n:";
	cin >> n;
	int s = DemChuSo(n);
	cout << "Ket qua la: " << s;
	return 0;
}

int DemChuSo(int nn)
{
	nn = abs(nn);
	if (nn <= 9)
		return 1;
	return (DemChuSo(nn / 10) + 1);
}