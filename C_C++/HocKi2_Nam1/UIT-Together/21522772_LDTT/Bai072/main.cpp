#include <iostream>

using namespace std;

int main()
{
	int M = 0;
	double S = 0;
	int n;
	cout << "Nhap n: ";
	cin >> n;
	unsigned int i = 1;
	while(i <= n)
	{
		M += i;
		S += 1/M;
		i++;
	}
	cout <<"Ket qua la: " << S;
	return 0;
}