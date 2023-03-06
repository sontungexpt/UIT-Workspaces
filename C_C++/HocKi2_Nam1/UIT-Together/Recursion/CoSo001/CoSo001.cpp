#include <iostream>

using namespace std;

int Tong(int);

int main()
{
	int n;
	cout << "Nhap n:";
	cin >> n;
	int s = Tong(n);
	cout << "Tong la: " << s;
	return 0;
}

int Tong(int nn)
{
	if (nn == 0)
		return 0;
	return (Tong(nn - 1)+ nn);
}
