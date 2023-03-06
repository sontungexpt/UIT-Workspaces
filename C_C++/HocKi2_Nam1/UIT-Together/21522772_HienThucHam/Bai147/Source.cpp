#include <iostream>
#include <math.h>

using namespace std;

// initialize method
void Input(int&);
bool IsAllOddDigit(int);


int main()
{
	int n;
	Input(n);
	bool result = IsAllOddDigit(n);
	if (result == 1)
		cout << n<<" toan chu so le";
	else
		cout << n << " khong toan chu so le";
	return 0;
}

//method
void Input(int& nn)
{
	cout << "Nhap so nguyen n: ";
	cin >> nn;
}

bool IsAllOddDigit(int nn)
{
	int unit = 0;
	for (; nn > 0;)
	{
		unit = nn % 10;
		if (unit % 2 == 0)
			return 0;
		nn /= 10;
	}
	return 1;
}