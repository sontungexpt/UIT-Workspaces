#include <iostream>

using namespace std;

int main()
{
	double fDegree;
	cout << "Nhap do F can chuyen sang do C: ";
	cin >> fDegree;
	double cDegree = 5*(fDegree-32)/9;
	cout << "Do C la: " << cDegree;
	return 0;
}