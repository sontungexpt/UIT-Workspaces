#include <iostream>

using namespace std;

int main()
{
	int a, b;
	cout << "Nhap lan luot a va b: ";
	cin >> a >> b;
	a = a - b;
	b = b + a;
	a = b - a;
	cout << "a va b sau khi duoc sap xep la: " << a << " " << b;
	return 0;
}
