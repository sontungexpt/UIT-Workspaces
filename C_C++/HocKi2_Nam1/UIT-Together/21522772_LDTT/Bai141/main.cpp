#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	int n;
	cout << "nhap n: ";
	cin >> n;
	int temp = n;
	while (temp >= 10)
	{
		temp = temp / 10;
	}
	cout << "ket qua la: " << temp;
	return 0;
}