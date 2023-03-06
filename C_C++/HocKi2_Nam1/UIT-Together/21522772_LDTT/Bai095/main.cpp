#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	int n;
	cout << "Nhap n: ";
	cin >> n;
	double S = 0;
	unsigned int i = n;
	while(i > 0)
	{
		S = sqrt(i + S);
		i--;
	}
	cout << "Ket qua la: " << S;
	return 0;
}