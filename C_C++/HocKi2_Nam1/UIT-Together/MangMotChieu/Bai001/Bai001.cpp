#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

#define MAX 100000

void Nhap(int[], int&);
void Xuat(int[], int);

int main()
{
	int n;
	int a[MAX];
	Nhap(a, n);
	Xuat(a, n);
	return 0;
}

void Nhap(int a[], int& n)
{
	cout << "Nhap n: ";
	cin >> n;
	srand(time(NULL));

	for (int i = 0; i < n; i++)
		a[i] = rand() % 201 - 100;
}

void Xuat(int a[], int n)
{
	for (int i = 0; i <= n - 1; i++)
		cout << a[i] << setw(11);
}