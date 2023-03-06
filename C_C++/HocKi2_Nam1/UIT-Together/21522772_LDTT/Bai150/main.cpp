#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	int a, b, BCNN;
	cout << "nhap lan luot a,b: ";
	cin >> a >> b;
	int tempA = a;
	int tempB = b;
	while (tempA != tempB)
	{
		if (tempA > tempB)
			tempA = tempA - tempB;
		else
			tempB = tempB - tempA;
	}
	BCNN = abs(a * b) / tempA;
	cout << BCNN;
	return 0;
}