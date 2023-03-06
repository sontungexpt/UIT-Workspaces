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
void Nhap(int&, int&);
int DauTien(int[], int, int, int);

int main()
{
	int n;
	int x;
	int y;
	int a[MAX];
	Nhap(GetFileLink("int"), a, n);
	Nhap(x, y);
	cout << "Chu so dau tien nam trong khoang(" << x << "," << y << ") la: " << DauTien(a, n, x, y);
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
void Nhap(int& xx, int& yy)
{
	cout << "Nhap khoang (x,y)\n";
	cout << "Nhap x: ";
	cin >> xx;
	cout << "Nhap y: ";
	cin >> yy;
}
int DauTien(int a[], int nn, int xx, int yy)
{
	for (int i = 0; i < nn; i++)
		if (xx < a[i] && a[i] < yy)
			return a[i];
	return xx;

}



