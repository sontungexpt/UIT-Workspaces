#include <iostream>
#include <math.h>

using namespace std;

// initialize method

void Input(int&);

//hàm đếm số lượng ước số
int CountDivisorOf(int);

int main()
{
	int n;
	Input(n);
	int result = CountDivisorOf(n);
	cout << "So luong uoc so cua " << n << ": " << result;
	return 0;
}

//method

void Input(int& nn)
{
	cout << "Nhap so nguyen n: ";
	cin >> nn;
}

int CountDivisorOf(int nn)
{
	int count = 0;
	for (int i = 1; i <= nn; i++)
		if (nn % i == 0)
			count ++;
	return count;
}

