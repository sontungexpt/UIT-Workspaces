#include <iostream>
#include <math.h>

using namespace std;

// initialize method
void Input(int&);
bool IsPrimeNumber(int);


int main()
{
	int n;
	Input(n);
	bool result = IsPrimeNumber(n);
	if (result == 1)
		cout << "La so nguyen to";
	else
		cout << "Khong la so nguyen to";
	return 0;
}

//method
void Input(int& nn)
{
	cout << "Nhap so nguyen n: ";
	cin >> nn;
}

bool IsPrimeNumber(int nn)
{
	if (nn <= 1)
	{
		return 0;
	}
	else
	{
		for (int i = 2; i <= nn/2; i++)
		{
			if (nn % i == 0)
				return 0;
		}
		return 1;
	}
}