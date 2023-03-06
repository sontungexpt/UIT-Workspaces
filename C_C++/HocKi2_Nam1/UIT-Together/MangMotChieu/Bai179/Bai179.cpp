#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cctype>
#include <math.h>

using namespace std;

#define MAX 10000

string GetFileLink(string);
void Nhap(string, float[], int&);
bool KtConDuong(float[], int, int, int);
void LietKe(float[], int);
void XuatCon(float[], int, int, int);
int main()
{
	int n;
	int l;
	float a[MAX];
	Nhap(GetFileLink("float"), a, n);
	LietKe(a, n);
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

void Nhap(string filename, float a[], int& n)
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

void XuatCon(float a[], int n, int vt, int l)
{
	for (int i = 0; i < l; i++)
		cout << setw(11) << a[vt + i];
	cout << endl;
}

bool KtConDuong(float a[], int n, int vt, int l)
{
	int flag = 1;
	for (int i = 0; i < l; i++)
		if (a[vt + i] <= 0)
			flag = 0;
	return flag;
}

void LietKe(float a[], int n)
{
	for (int l = 2; l <= n; l++)
		for (int vt = 0; vt <= n - l; vt++)
			if (KtConDuong(a, n, vt, l) == true)
				XuatCon(a, n, vt, l);
}