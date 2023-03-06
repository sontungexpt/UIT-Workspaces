#include <iostream>
#include <math.h>

using namespace std;

// initialize method
void Input(int&);
int GetUnitOf(int);

int main()
{
	int n;
	Input(n);
	int result = GetUnitOf(n);
	cout << "Chu so hang don vi cua "<<n<<" la: " << result;
	return 0;
}

//method
void Input(int& nn)
{
	cout << "Nhap n: ";
	cin >> nn;
}
int GetUnitOf(int nn)
{
	return nn % 10;
}
