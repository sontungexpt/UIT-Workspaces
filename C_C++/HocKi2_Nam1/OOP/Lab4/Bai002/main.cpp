#include "Fractor.h"

int main()
{
	Fractor specialNumber(3);
	cout << "Special fractor = " << specialNumber;
	Fractor x;
	cout << "\nInput the x fractor: ";
	cin >> x;
	cout << "x =  " << x;
	Fractor y;
	cout << "\nInput y fractor: ";
	cin >> y;
	cout << "y = " << y;
	if (x == y)
		cout << "\nx = y";
	if (x != y)
		cout << "\nx!= y";
	cout << "\nx + y = ";
	Fractor result = x + y;
	cout << result;
	cout << "\nx - y = ";
	result = x - y;
	cout << result;
	cout << "\nx * y = ";
	result = x * y;
	cout << result;
	cout << "\nx / y = ";
	result = x / y;
	cout << result;
	return 0;
}