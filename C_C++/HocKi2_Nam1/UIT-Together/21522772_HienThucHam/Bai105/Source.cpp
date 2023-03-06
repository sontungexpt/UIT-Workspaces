#include <iostream>
#include <math.h>

using namespace std;

// initialize method

//Ham tinh cap so cong cua n
int ArithmeticProgressionOf(int);
double Sum();


int main()
{
	double result = Sum();
	cout << "Tong voi do chinh xac 10^-6 la: " << result;
	return 0;
}

//method

int ArithmeticProgressionOf(int nn)
{
	int sum = 0;
	for (int i = 1; i <= nn; i++)
	{
		sum += i;
	}
	return sum;
}
double Sum()
{
	double sum = 0;
	double e = 1;
	for (int i = 1; e >= pow(10, -6); i ++)
	{
		int temp = ArithmeticProgressionOf(i);
		e = 1 / (double)temp;
		sum += e;
	}
	return sum;
}
