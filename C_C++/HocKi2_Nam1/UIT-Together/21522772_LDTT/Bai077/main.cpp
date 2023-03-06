#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	int n,k;
	cout << "Nhap lan luot n,k: ";
	cin >> n >> k;
	double S = 0;
	unsigned int i = 1;
	while(i <= n)
	{
		S += pow(i,k);
		i++;
	}
	cout << "Ket qua la: " << S;
	return 0;
}