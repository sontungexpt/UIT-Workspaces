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
	double result = Sum(n);
	cout << "Tong la: " << result;
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
	for (int i = nn; i > 0; i--)
		sum = sqrt(i + sum);
	return sum;
}
