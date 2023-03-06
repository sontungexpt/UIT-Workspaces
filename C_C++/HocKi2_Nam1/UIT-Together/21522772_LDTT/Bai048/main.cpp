#include <iostream>

using namespace std;

int main()
{
	int n;
	double x;
	cout << "Nhap lan luot x , n: ";
	cin >> x>> n;
	double S = x;
	unsigned int i = 1;
	while(i <= n)
	{
		S *= (x+i);
		i++;
	}
	cout <<"Ket qua la: " << S;
	return 0;
}