#include <iostream>
#include <fstream>
#include<iomanip>
#include <string>
#include <algorithm>
using namespace std;

int Nhap(int[], int&, string);
int Xuat(int[], int, string);
void MergeSort(int[], int, int);
void Merge(int[], int, int, int);


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
			MergeSort(b, 0,k-1);
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
void Merge(int a[], int left, int mid, int right)
{
	int* temp = new int[right - left + 1];
	int m = 0;
	int i = left;
	int j = mid + 1;
	while (i <= mid || j <= right)
	{
		if ((i <= mid && j <= right && a[i] < a[j]) || j > right)
			temp[m++] = a[i++];
		else
			temp[m++] = a[j++];
	}
	for (int i = 0; i < m; i++)
		a[left + i] = temp[i];
}

void MergeSort(int a[], int left, int right)
{
	if (left < right)
	{
		int mid = (right + left) / 2;
		MergeSort(a, left, mid);
		MergeSort(a, mid + 1, left);
		Merge(a, left, mid, right);
	}
}
