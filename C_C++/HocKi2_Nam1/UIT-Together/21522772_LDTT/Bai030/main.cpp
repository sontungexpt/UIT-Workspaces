#include <iostream>

using namespace std;

int main()
{
	int n;
	cout << "Nhap n: ";
	cin >> n;
	double S = 0;
	unsigned int i = 2;
	while(i <= 2*n )
	{
		S += 1/(double)i;
		i+=2;
	}
	cout << "Ket qua la: " << S;
	return 0;
}