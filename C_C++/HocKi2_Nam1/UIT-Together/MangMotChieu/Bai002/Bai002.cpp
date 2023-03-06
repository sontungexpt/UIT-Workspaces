#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

#define MAX 100000

void Nhap(float[], int&);
void Xuat(float[], int);

int main()
{
	int n;
	float a[MAX];
	Nhap(a, n);
	Xuat(a, n);
	return 0;
}

void Nhap(float a[], int& n)
{
	cout << "Nhap n: ";
	cin >> n;
	srand(time(NULL));

	for (int i = 0; i < n; i++)
		a[i] = -100.0 + (rand() / (RAND_MAX / (100.0 - (-100.0))));
}

void Xuat(float a[], int n)
{
	for (int i = 0; i <= n - 1; i++)
		cout << a[i] << setw(11);
}