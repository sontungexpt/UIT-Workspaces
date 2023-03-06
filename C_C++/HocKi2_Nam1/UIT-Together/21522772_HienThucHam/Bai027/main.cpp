#include <iostream>
#include <math.h>

using namespace std;

// initialize method
void Input(int&);
int Sum(int );

int main()
{
	int n;
	Input(n);
	int sum = Sum(n);
	cout << "Tong cac so nguyen tu 1 den " << n << ": " << sum;
	return 0;
}

//method
void Input(int& nn)
{
	cout << "Nhap so nguyen n: ";
	cin >> nn;
}
int Sum(int nn)
{
	int sum = 0;
	for (int i = 1; i <= nn; i++)
	{
		sum += i;
	}
	return sum;
}

