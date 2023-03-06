#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

#define MAX 100000

bool Input(int[], int&, string);
void Output(int[], int);
bool Output(int[], int, string);
string GetFileName();

int main()
{
	int n;
	int arr[MAX];
	if (Input(arr, n, GetFileName()) == 1)
	{
		Output(arr, n);
		Output(arr, n, "intdata05.out");
	}
	else
		cout << "khong mo duoc file";
	return 0;
}
string GetFileName()
{
	int fileIndex;
	string fileName = "data/intdata";
	cout << "Nhap so thu tu cua file can lay gia tri: ";
	cin >> fileIndex;
	if (fileIndex < 10)
		fileName += '0';
	fileName += to_string(fileIndex);
	string fileNameInp = fileName;
	fileNameInp += ".inp";
	return fileNameInp;
}

bool Input(int a[], int& n, string filename)
{
	ifstream fi(filename);
	if (fi.fail() == true)
		return 0;
	fi >> n;
	for (int i = 0; i < n; i++)
		fi >> a[i];
	return 1;
}
void Output(int a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << setw(5) << a[i];
}
bool Output(int a[], int n, string fileName)
{
	ofstream fo(fileName);
	if (fo.fail() == true)
		return 0;
	fo << setw(5) << n << endl;
	for (int i = 0; i < n; i++)
		fo << setw(5) << a[i];
	return 1;
}