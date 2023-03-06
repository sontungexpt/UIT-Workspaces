#include <iostream>

using namespace std;

int ChuSoLonNhat(int);

int main()
{
	int n;
	cout << "Nhap n:";
	cin >> n;
	int s = ChuSoLonNhat(n);
	cout << "Ket qua la: " << s;
	return 0;
}

int ChuSoLonNhat(int nn)
{
	nn = abs(nn);
	if (nn == 0)
		return 0;
	int max = ChuSoLonNhat(nn / 10);
	int dv = nn % 10;
	if (dv > max)
		max = dv;
	return max;
}