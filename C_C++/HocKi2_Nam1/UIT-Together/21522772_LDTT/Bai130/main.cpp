#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	double x, y, z;
	cout << "Nhap lan luot x,y,z";
	cin >> x >> y >> z;
	if (abs(y - z) < x && x < y + z)
		cout << "Ton tai";
	else
		cout << "Khong ton tai";
	return 0;
}