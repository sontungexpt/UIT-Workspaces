#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	int n;
	cout << "Nhap n: ";
	cin >> n;
	double S = 0;
	unsigned int i = 1;
	while(i <= n)
	{
		S += 1 / ((i+1)*sqrt(i)+i*sqrt(i+1));
		i++;
	}
	cout << "Ket qua la: " << S;
	return 0;
}