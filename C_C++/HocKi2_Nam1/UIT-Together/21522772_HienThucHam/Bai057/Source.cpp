#include <iostream>
#include <math.h>

using namespace std;

// initialize method

void Input(int&);

int SumLessThan(int);

int main()
{
	int n;
	Input(n);
	int result = SumLessThan(n);
	cout << "Tong tat ca cac uoc so nho hon cua " << n << ": " << result;
	return 0;
}

//method

void Input(int& nn)
{
	cout << "Nhap so nguyen n: ";
	cin >> nn;
}
int SumLessThan(int nn)
{
	int sum = 0;
	for (int i = 1; i < nn; i ++)
		if (nn % i == 0)
			sum+=i;
	return sum;
}
