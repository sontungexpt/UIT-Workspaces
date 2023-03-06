#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	double x, y, z;
	cout << "nhap lan luot x,y,z: ";
	cin >> x >> y >> z;
	if (x <= y && y <= z)
		cout << "Bat dang thuc dung";
	else
		cout << "Bat dang thuc khong dung";
	
	return 0;
}