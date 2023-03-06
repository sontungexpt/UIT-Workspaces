#include <iostream>
#include <math.h>

using namespace std;

// initialize method
void Input(int&);
int GetHundredsOf(int);

int main()
{
	int n;
	Input(n);
	int result = GetHundredsOf(n);
	cout << "Chu so hang tram cua " << n << " la: " << result;
	return 0;
}

//method
void Input(int& nn)
{
	cout << "Nhap n: ";
	cin >> nn;
}
int GetHundredsOf(int nn)
{
	return nn / 100 % 10;
}
