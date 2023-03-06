#include <iostream>
#include <math.h>

using namespace std;

// initialize method

void Input(int&);

int SumEvenDivisorOf(int);

int main()
{
	int n;
	Input(n);
	int result = SumEvenDivisorOf(n);
	cout << "Tong tat ca cac uoc so chan cua " << n << ": "<<result;
	return 0;
}

//method

void Input(int& nn)
{
	cout << "Nhap so nguyen n: ";
	cin >> nn;
}
int SumEvenDivisorOf(int nn)
{
	int sum = 0;
	for (int i = 2; i <= nn; i+=2)
		if (nn % i == 0)
			sum += i;
	return sum;
}
