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
	for (int i =2; i <= nn; i++)
		sum = pow(i+1,1/(i+1));
	return sum;
}
