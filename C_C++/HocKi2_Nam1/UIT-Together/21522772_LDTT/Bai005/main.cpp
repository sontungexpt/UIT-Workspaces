#include <iostream>
using namespace std;

#define PI 3.14

int main()
{
	float r;
	cout << "Nhap r: ";
	cin >> r;
	double V = (4 *PI * r * r * r) /3 ;
	cout << "The tich la: " << V;
	return 0;
}