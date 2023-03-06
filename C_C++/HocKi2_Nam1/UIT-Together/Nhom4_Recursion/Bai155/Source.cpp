#include <iostream>
#include <iomanip>

using namespace std;


void Nhap(int[], int);
int ktBang(int[], int);

int main()
{
	int n;
	int a[100];
	cout << "Nhap n: ";
	cin >> n;
	Nhap(a, n);
	if (ktBang(a, n) == true)
		cout << "Chuoi bang";
	else
		cout << "Chuoi khong bang";
	return 0;
}
void Nhap(int a[], int n)
{
	if (n == 0)
		return;
	Nhap(a, n - 1);
	cout << "Nhap a[" << n - 1 << "]: ";
	cin >> a[n - 1];
}


int ktBang(int a[], int n)
{
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	if ((a[n - 2] == a[n - 1]) && ktBang(a, n - 1) == 1)
		return 1;
	return 0;
}