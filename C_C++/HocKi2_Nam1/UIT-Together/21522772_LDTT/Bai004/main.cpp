#include <iostream>
using namespace std;

#define PI 3.14

int main()
{
	float r;
	cout << "Nhap r: ";
	cin >> r;
	double S = 4 *PI * r * r;
	cout << "Dien tich la: " << S;
	return 0;
}