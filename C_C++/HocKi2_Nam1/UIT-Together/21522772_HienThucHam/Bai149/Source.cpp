#include <iostream>
#include <math.h>

using namespace std;

// initialize method
void Input(int&,int& );
int Gcd(int,int );


int main()
{
	int a,b;
	Input(a,b);
	bool result = Gcd(a,b);
	cout << "Uoc chung lon nhat: " << result;
	return 0;
}

//method
void Input(int& aa, int& bb)
{
	cout << "Nhap a: ";
	cin >> aa;
	cout << "Nhap b: ";
	cin >> bb;
}

int Gcd(int aa, int bb)
{
	while (aa * bb != 0)
	{
		if (aa > bb)
			aa %= bb;
		else
			bb %= aa;
	}
	return aa + bb;
}