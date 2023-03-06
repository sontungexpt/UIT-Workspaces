#include <iostream>

using namespace std;

int main()
{
	int n, unit;
	cout << "Nhap n: ";
	cin >> n;
	int S = 0;
	int temp = n;
	while (temp > 0)
	{
		unit = temp % 10;
		S += unit;
		temp /= 10;
	}
	cout <<"Ket qua la: " << S;
	return 0;
}