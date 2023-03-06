#include <iostream>
#include <math.h>

using namespace std;

// initialize method

void Input(int&);

//hàm liệt kê tất cả các ước số
void ListAllOddDivisor(int);

int main()
{
	int n;
	Input(n);
	ListAllOddDivisor(n);
	return 0;
}

//method

void Input(int& nn)
{
	cout << "Nhap so nguyen n: ";
	cin >> nn;
}
void ListAllOddDivisor(int nn)
{
	cout << "Cac uoc so cua " << nn << ": ";
	for (int i = 1; i <= nn; i+=2)
	{
		if (nn % i == 0)
		{
			cout << i;
		}
	}
}
