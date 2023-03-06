#include <iostream>
#include <math.h>
using namespace std;

#define PI 3.14

int main()
{
	double r;
	cout << "Nhap r: ";
	cin >> r;
	double S = PI*r*r;
	cout << "Dien tich la: "<<S;
	return 0;
}