#include <iostream>

using namespace std;

int TonTaiLe(int);

int main()
{
	int n;
	cout << "Nhap n:";
	cin >> n;
	int s = TonTaiLe(n);
	cout << "Ket qua la: " << s;
	return 0;
}

int TonTaiLe(int nn)
{
	nn = abs(nn);
	if (nn <= 9)
	{
		if (nn % 2 != 0)
			return 1;
		return 0;
	}
	int dv = nn % 10;
	if (dv % 2 != 0)
		return 1;
	return TonTaiLe(nn / 10);
}