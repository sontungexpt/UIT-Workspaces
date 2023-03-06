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
		S = sqrt(2+S);
		i++;
	}
	cout << "Ket qua la: " << S;
	return 0;
}