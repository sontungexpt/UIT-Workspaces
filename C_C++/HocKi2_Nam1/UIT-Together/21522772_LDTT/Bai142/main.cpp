#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	int n,unit;
	cout << "Nhap n: ";
	cin >> n;
	int temp = n;
	int reverseNum = 0;
	while (temp > 0)
	{
		unit = temp % 10;
		reverseNum = reverseNum * 10 + unit;
		temp = temp / 10;
	}
	cout << "so dao nguoc la: " << reverseNum;
	return 0;
}