#include <iostream>
#include <math.h>

using namespace std;

// initialize method
void Input(int&);
bool IsType2M(int);


int main()
{
	int n;
	Input(n);
	bool result = IsType2M(n);
	if (result == 1)
		cout << n << " co dang 3^m";
	else
		cout << n << " khong co dang 3^m";

	return 0;
}

//method
void Input(int& nn)
{
	cout << "Nhap n: ";
	cin >> nn;

}

bool IsType2M(int nn)
{
	int surplus = 0;
	for (; nn > 1;)
	{
		if (nn % 3 != 0)
			return 0;
		nn /= 3;
	}
	return 1;
}
