#include <iostream>
#include <math.h>

using namespace std;

// initialize method
void Input(int&);

int GetNumberAt(int);
int main()
{
	int n;
	Input(n);
	int result = GetNumberAt(n);
	cout << "So hang thu"<<n<<" cua day la: " << result;
	return 0;
}

//method
void Input(int& nn)
{
	cout << "Nhap so nguyen n: ";
	cin >> nn;
}

int GetNumberAt(int nn)
{
	int aPrevious = 2;
	int aCurrent = 0;
	for (int i = 2; i <= nn; i++)
	{
		aCurrent = aPrevious + 2 * i + 1;
		aPrevious = aCurrent;
	}
	return aCurrent;
}