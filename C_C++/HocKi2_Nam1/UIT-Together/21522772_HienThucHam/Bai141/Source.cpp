#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

// initialize method
void Input(int&);
int GetFirstDigit(int);

int main()
{
	int n;
	Input(n);
	int result = GetFirstDigit(n);
	cout << "Chu so thu nhat cua " << n << " la: " << result;
	return 0;
}

//method
void Input(int& nn)
{
	cout << "Nhap so nguyen n: ";
	cin >> nn;
}
int GetFirstDigit(int nn)
{
	for (; nn >= 10;)
		nn / 10;
	return nn;
}
