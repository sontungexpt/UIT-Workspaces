#include <iostream>
#include <math.h>
using namespace std;

#define PI 3.14

int main()
{
	float r;
	cout << "Nhap r: ";
	cin >> r;
	double C = PI * 2 * r;
	cout << "Chu vi la: " << C;
	return 0;
}