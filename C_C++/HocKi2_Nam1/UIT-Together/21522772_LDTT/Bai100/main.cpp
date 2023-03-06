#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	int n;
	cout << "Nhap n: ";
	cin >> n;
	double S = 0;
	int T = 1;
	unsigned int i = 1;
	while( i <= n)
	{
		T *= i;
		S = pow(T + S, i + 1);
		i++;
	}
	cout << "Ket qua la: " << S;
	return 0;
}