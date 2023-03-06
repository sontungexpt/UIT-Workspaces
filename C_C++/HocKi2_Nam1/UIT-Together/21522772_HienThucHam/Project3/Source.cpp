#include <iostream>
#include <math.h>

using namespace std;

// initialize method

void Input(int&);

double Sum(int);

//hàm tìm cấp số cộng
int ArithmeticProgressionOf(int);

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

int ArithmeticProgressionOf(int nn)
{
	int sum = 0;
	for (int i = 1; i <= nn; i++)
	{
		sum += i;
	}
	return sum;
}
double Sum(int nn)
{
	double sum = 0;
	for (int i = 1; i <= nn; i ++)
	{
		//mẩu số
		int denomiator = ArithmeticProgressionOf(i);
		sum += 1/(double)denomiator;
	}
	return sum;
}