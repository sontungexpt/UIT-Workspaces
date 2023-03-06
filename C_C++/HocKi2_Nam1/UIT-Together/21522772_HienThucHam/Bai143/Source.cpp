#include <iostream>
#include <math.h>

using namespace std;

// initialize method
void Input(int&);
int SumOfDivisorLessThan(int);
bool IsPerfectNumber(int);


int main()
{
	int n;
	Input(n);
	int result = IsPerfectNumber(n);
	if (result == 1)
		cout << "La so hoan thien";
	else
		cout << "Khong la so hoan thien";
	return 0;
}

//method
void Input(int& nn)
{
	cout << "Nhap so nguyen n: ";
	cin >> nn;
}

int SumOfDivisorLessThan(int nn)
{
	int sum = 0;
	for (int i = 1; i < nn/2; i++)
		if (nn % i == 0)
			sum += i;
	return sum;
}
bool IsPerfectNumber(int nn)
{
	int sum = SumOfDivisorLessThan(nn);
	if (sum == nn)
		return 1;
	return 0;
}