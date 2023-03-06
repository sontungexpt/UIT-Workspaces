#include <iostream>
#include <math.h>

using namespace std;

// initialize method

double Sum();


int main()
{
	double result = Sum();
	cout << "Tong voi do chinh xac 10^-6 la: " << result;
	return 0;
}

//method

double Sum()
{
	double sum = 3;
	double e = 1;
	int  flag = 1;
	for (int i = 2; e >= pow(10, -6); i += 2)
	{
		e = 4 / ((double)i*(i+1)*(i+2));
		sum += flag * e;
		flag = -flag;
	}
	return sum;
}
