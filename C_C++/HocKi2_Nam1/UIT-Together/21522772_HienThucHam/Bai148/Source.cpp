#include <iostream>
#include <math.h>

using namespace std;

// initialize method
void Input(int&);
bool IsAllEvenDigit(int);


int main()
{
	int n;
	Input(n);
	bool result = IsAllEvenDigit(n);
	if (result == 1)
		cout << n << " toan chu so chan";
	else
		cout << n << " khong toan chu so chan";
	return 0;
}

//method
void Input(int& nn)
{
	cout << "Nhap so nguyen n: ";
	cin >> nn;
}

bool IsAllEvenDigit(int nn)
{
	int unit = 0;
	for (; nn > 0;)
	{
		unit = nn % 10;
		if (unit % 2 != 0)
			return 0;
		nn /= 10;
	}
	return 1;
}