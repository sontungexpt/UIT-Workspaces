#include <iostream>
#include <math.h>

using namespace std;

// initialize method

void Input(int&);

int CountEvenDivisorOf(int);

int main()
{
	int n;
	Input(n);
	int result = CountEvenDivisorOf(n);
	cout << "Tich tat ca cac uoc so le cua " << n << ": " << result;
	return 0;
}

//method

void Input(int& nn)
{
	cout << "Nhap so nguyen n: ";
	cin >> nn;
}
int CountEvenDivisorOf(int nn)
{
	int count = 0;
	for (int i = 2; i <= nn; i += 2)
		if (nn % i == 0)
			count ++;
	return count;
}
