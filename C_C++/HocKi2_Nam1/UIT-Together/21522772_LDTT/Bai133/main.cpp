 #include <iostream>
#include <math.h>

using namespace std;

int main()
{
	double x, y, z;
	cout << "Nhap lan luot x,y,z: ";
	cin >> x >> y >> z;
	if (abs(x - y) < z && z < x + y)
	{
		if (x == y && y == z && z == x)
		{
			cout << "Tam giac deu";
		}
		else
		{
			if (x * x == y * y + z * z || y * y == x * x + z * z || z * z == y * y + x * x)
			{
				if (x == y || x == z || y == z)
				{
					cout << "Tam giac vuong can";
				}
				else
				{
					cout << "Tam giac vuong";
				}
			}
			else
			{
				if (x == y || x == z || y == z)
				{
					cout << "Tam giac can";
				}
				else
				{
					cout << "Tam giac thuong";
				}
			}
		}
	}
	else
	{
		cout << "Khong la tam giac";
	}

	return 0;
}