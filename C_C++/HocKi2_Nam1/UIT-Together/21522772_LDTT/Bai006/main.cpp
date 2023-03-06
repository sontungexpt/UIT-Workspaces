#include <iostream>

using namespace std;

int main()
{
	double cDegree;
	cout << "Nhap do C can doi sang do F: ";
	cin >> cDegree;
	double fDegree = 9*cDegree/5 + 32;
	cout <<"Do F la: " << fDegree;
	return 0;
}