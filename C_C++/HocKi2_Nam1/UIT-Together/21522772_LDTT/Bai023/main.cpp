#include <iostream>

using namespace std;

int main()
{
	int n;
	cout << "Nhap n: ";
	cin >> n;
	double chuc = (n / 10) % 10;
	cout << "Chu so hang chuc la: " << chuc;
	return 0;
}
