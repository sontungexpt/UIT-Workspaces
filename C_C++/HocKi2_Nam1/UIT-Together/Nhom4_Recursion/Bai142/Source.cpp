#include <iostream>
#include <iomanip>

using namespace std;


void Nhap(int[], int);
int TimGiaTri(int[], int);
bool ktDang2m(int);

int main()
{
	int n;
	int a[100];
	cout << "Nhap n: ";
	cin >> n;
	Nhap(a, n);
	cout << "Gia tri tim duoc: " << TimGiaTri(a,n);
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

bool ktDang2m(int n)
{
	if (n == 1)
		return 1;
	else if (n == 0)
		return 0;
	bool flag = ktDang2m(n / 2);
	if (flag == 0)
		return 0;
	if (n % 2 == 0)
		return 1;
	else 
		return 0;
}


int TimGiaTri(int a[], int n) 
{
	if (n == 0)
		return 0;
	int lc = TimGiaTri(a, n - 1);
	if (!ktDang2m(a[n - 1]))
		return lc;
	if (lc == 0)
		return a[n - 1];
	if (a[n - 1] > lc)
		lc = a[n - 1];
	return lc;
}