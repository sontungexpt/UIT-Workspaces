#include <iostream>

using namespace std;

#define PI 3.14

int main()
{
	int n;
	double r;
	cout << "Nhap lan luot n, r: ";
	cin >> n >> r;
	double S = n * r * r * sin(2 * PI / n) / 2;
	cout << "Dien tich la: " << S;
	return 0;
}