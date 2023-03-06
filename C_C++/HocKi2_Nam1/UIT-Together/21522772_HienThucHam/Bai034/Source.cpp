#include <iostream>
#include <math.h>

using namespace std;

// initialize method
void Input(int&);
double Sum(int);

int main()
{
	int n;
	Input(n);
	double sum = Sum(n);
	cout << "Tong la: " << sum;
	return 0;
}

//method
void Input(int& nn)
{
	cout << "Nhap so nguyen n: ";
	cin >> nn;
}
double Sum(int nn)
{
	double sum = 0;
	for (int i = 1; i <=2*nn+1; i+=2)
	{
		sum += (double)i / (i + 1);
	}
	return sum;
}

