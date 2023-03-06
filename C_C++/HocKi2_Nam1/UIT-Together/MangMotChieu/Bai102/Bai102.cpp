#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cctype>
using namespace std;

#define MAX 100000

bool ktHoanThien(int);
int HoanThienDau(int[], int);
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
	cout << "\nGia tri hoan thien nho nhat trong mang: " << kq;
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

bool ktHoanThien(int n)
{
	int s = 0;
	for (int i = 1; i <= n - 1; i++)
		if (n % i == 0)
			s += i;
	if (s == n)
		return true;
	return false;
}

int HoanThienDau(int a[], int n)
{
	for (int i = 0; i < n; i++)
		if (ktHoanThien(a[i]) == 1)
			return a[i];
	return -1;
}

int TimGiaTri(int a[], int n)
{
	int lc = HoanThienDau(a, n);
	if (lc == -1)
		return -1;
	for (int i = 0; i < n; i++)
		if (ktHoanThien(a[i]) == 1 && a[i] < lc)
			lc = a[i];
	return lc;
}