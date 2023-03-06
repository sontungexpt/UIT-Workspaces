#include <iostream>
#include <math.h>

using namespace std;

// initialize method
void Input(int&);
int GetTensOf(int);

int main()
{
	int n;
	Input(n);
	int result = GetTensOf(n);
	cout << "Chu so hang chuc cua " << n << " la: " << result;
	return 0;
}

//method
void Input(int& nn)
{
	cout << "Nhap n: ";
	cin >> nn;
}
int GetTensOf(int nn)
{
	return nn /10 % 10;
}
