#include <iostream>
#include <iomanip>

using namespace std;

int ktToanLe(int);
void LietKe(int[], int);
void Nhap(int[], int);

int main()
{
	int n;
	int a[100];
	cout << "Nhap n: ";
	cin >> n;
	Nhap(a, n);
	LietKe(a, n);
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


int ktToanLe(int n)
{
	n = abs(n);
	if (n <= 9)
	{
		if (n % 2 != 0)
			return 1;
		return 0;
	}
	int dv = n % 10;
	if (ktToanLe(n / 10) == 1 && dv % 2 != 0)
		return 1;
	return 0;
}

void LietKe(int a[], int n)
{
	if (n == 0)
		return;
	LietKe(a, n - 1);
	if (ktToanLe(a[n - 1]))
		cout << setw(6) << a[n - 1];
}