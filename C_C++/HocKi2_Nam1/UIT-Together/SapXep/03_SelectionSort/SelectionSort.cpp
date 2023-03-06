#include <iostream>
#include <fstream>
#include<iomanip>
#include <string>
#include <algorithm>
using namespace std;

int Nhap(int[], int&, string);
int Xuat(int[], int, string);
void SelectionSort(int[], int);


int main()
{
	int b[100000];
	int k;

	for (int i = 1; i <= 13; i++)
	{

		string filename = "intdata";
		if (i < 10)
			filename += '0';
		filename += to_string(i);

		string filenameinp = filename;
		filenameinp += ".inp";
		if (Nhap(b, k, filenameinp) == 1)
		{
			SelectionSort(b, k);
			string filenameout = filename;
			filenameout += ".out";
			Xuat(b, k, filenameout);

			cout << "\n" << filenameinp;
			cout << "\n" << filenameout;
		}
		else
			cout << "\n Khong mo duoc file " << filename << "\n";
	}
	cout << "\n\n\n";
	return 1;
}

int Nhap(int a[], int& n, string filename)
{
	ifstream fi(filename);
	if (fi.fail())
		return 0;
	fi >> n;
	for (int i = 0; i < n; i++)
		fi >> a[i];
	return 1;
}

int Xuat(int a[], int n, string filename)
{
	ofstream fo(filename);
	if (fo.fail() == true)
		return 0;
	fo << setw(5) << n << endl;
	for (int i = 0; i < n; i++)
		fo << setw(5) << a[i];
	return 1;
}
void SelectionSort(int a[], int n)
{
	
	for (int i = 0; i < n - 1; i++)
	{
		int gaurds = i;
		for (int j = i; j < n; j++)
			if (a[j] < a[gaurds])
				gaurds = j;
		swap(a[i], a[gaurds]);
	}
}