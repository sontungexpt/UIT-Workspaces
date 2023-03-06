#include <iostream>
#include <math.h>
using namespace std;

#define PI 3.14

int main()
{
	int n;
	double r;
	cout << "Nhap lan luot n, r:";
	cin >> n >> r;
	double P = 2*n*r*sin(PI/2);
	cout << "Chu vi la: " << P;
	return 0;
}