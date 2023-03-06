#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cctype>
#include <math.h>

using namespace std;

#define MAX 100000

string GetFileLink(string);
void Nhap(string, int[], int&);
bool KtSoNguyenTo(int);
int DemNguyenTo(int[], int);


int main()
{
	int n;
	int a[MAX];
	Nhap(GetFileLink("int"), a, n);
	cout << "So luong so nguyen to co trong mang la: " << DemNguyenTo(a, n);
	return 0;
}

string GetFileLink(string dataTypeOfFile)
{
	string folderName = dataTypeOfFile;
	folderName[0] = toupper(folderName[0]);
	folderName += "Data";
	string fileLink = "../" + folderName + "/" + dataTypeOfFile + "data";
	int fileIndex;
	cout << "Nhap so thu tu cua file can lay gia tri: ";
	cin >> fileIndex;
	if (fileIndex < 10)
		fileLink += '0';
	fileLink += to_string(fileIndex);
	string fileLinkInp = fileLink;
	fileLinkInp += ".inp";
	return fileLinkInp;
}

void Nhap(string filename, int a[], int& n)
{
	ifstream fi(filename);
	if (fi.fail() == true)
	{
		cout << "Khong mo duoc file";
		exit(0);
	}
	fi >> n;
	for (int i = 0; i < n; i++)
		fi >> a[i];
}

bool KtSoNguyenTo(int n)
{
	if (n <= 1)
		return false;
	int count = 0;
	for (int i = 1; i <= n; i++)
		if (n % i == 0)
			count++;
	if (count == 2)
		return true;
	return false;
}
int DemNguyenTo(int a[], int n)
{
	int count = 0;
	for (int i = 0; i < n; i++)
		if (KtSoNguyenTo(a[i]) == true)
			count++;
	return count;
}