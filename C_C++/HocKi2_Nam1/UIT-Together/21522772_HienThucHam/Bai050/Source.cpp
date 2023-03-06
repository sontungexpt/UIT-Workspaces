#include <iostream>
#include <math.h>

using namespace std;

// initialize method

void Input(int&);

//hàm tinh tổng tất cả các ước số
int SumDivisorOf(int);

int main()
{
	int n;
	Input(n);
	int result = SumDivisorOf(n);
	cout << "Tong tat ca cac uoc so cua " << n << ": " << result;
	return 0;
}

//method

void Input(int& nn)
{
	cout << "Nhap so nguyen n: ";
	cin >> nn;
}

int SumDivisorOf(int nn)
{
	int sum = 0;
	for (int i = 1; i <= nn; i++)
		if (nn % i == 0)
			sum += i;
	return sum;
}

