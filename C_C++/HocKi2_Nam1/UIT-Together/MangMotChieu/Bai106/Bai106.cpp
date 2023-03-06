#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cctype>
using namespace std;

#define MAX 100000

bool ktDang5m(int);
int DauTien(int[], int);
int TimGiaTri(int[], int);
string GetFileLink(string);
void Nhap(int[], int&, string);

int main()
{
	int a[MAX];
	int n = 0;
	Nhap(a, n, GetFileLink("int"));
	int kq;
	kq = TimGiaTri(a, n);
	cout << "\nGia tri co dang 5^m lon nhat trong mang: " << kq;
	return 0;
}

void Nhap(int a[], int& n, string filename)
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

bool ktDang5m(int n)
{
	{
		if (n < 1)
			return false;
		bool flag = true;
		for (int t = abs(n); t > 1; t = t / 5)
		{
			int du = t % 5;
			if (du != 0)
				flag = false;
		}
		return flag;
	}
}

int DauTien(int a[], int n)
{
	for (int i = 0; i < n; i++)
		if (ktDang5m(a[i]) != 0)
			return a[i];
	return 0;
}

int TimGiaTri(int a[], int n)
{
	int lc = DauTien(a, n);
	if (lc == 0)
		return 0;
	for (int i = 0; i < n; i++)
		if (ktDang5m(a[i]) == 1 && a[i] > lc)
			lc = a[i];
	return lc;
}
