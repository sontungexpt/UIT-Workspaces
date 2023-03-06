#include <iostream>

using namespace std;

int main()
{
	int n;
	cout << "Nhap n: ";
	cin >> n;
	double S = 0;
	unsigned int i = 1;
	while (i <= 2*n+1)
	{
		S += (double)i/(i+1);
		i += 2;
	}
	cout<<"Ket qua la: " << S;
	return 0;
}