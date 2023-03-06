#include <iostream>
#include <math.h>

using namespace std;

// initialize method
void Input(int&,int&);
void Output(int aa, int bb);
void Swap(int&, int&);

int main()
{
	int a,b;
	Input(a,b);
	Swap(a, b);
	Output(a, b);
	return 0;
}

//method
void Input(int&aa, int&bb)
{
	cout << "Nhap so nguyen a: ";
	cin >> aa;
	cout << "Nhap so nguyen b: ";
	cin >> bb;
}
void Output(int aa, int bb)
{
	cout << "Gia tri cua a la: " << aa;
	cout << "Gia tri cua b la: " << bb;
}
void Swap(int& aa, int& bb)
{
	int temp = aa;
	aa = bb;
	bb = temp;
}

