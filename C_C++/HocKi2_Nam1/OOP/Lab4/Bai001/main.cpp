#include "ComplexNumber.h"


int main()
{
	ComplexNumber specialNumber(3);
	cout << "Special complex = " << specialNumber;
	ComplexNumber x;
	cout << "\nInput the x complex number: ";
	cin >> x;
	cout << "x =  " << x;
	ComplexNumber y;
	cout << "\nInput y complex number: ";
	cin >> y;
	cout << "y = " << y;
	if (x == y)
		cout << "\nx = y";
	if (x != y)
		cout << "\nx!= y";
	cout << "\nx + y = ";
	ComplexNumber result = x + y;
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