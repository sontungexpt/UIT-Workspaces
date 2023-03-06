#include <iostream>
#include <iomanip>
#include <ctime>
#include <string>
#include <fstream>
#include <cctype>

using namespace std;

#define MAX 100000

void Nhap(string, float[], int&);
int ktCon(float[], int, int, int);
void DuongDaiNhat(float[], int, int&, int&);
void Xuat(float[], int, int);
string GetFileLink(string);

int main()
{
	int n;
	float a[MAX];
	Nhap(GetFileLink("float"), a, n);
	int vtd = 0;
	int vtc = n - 1;
	DuongDaiNhat(a, n, vtd, vtc);
	if (vtd != -1 || vtc != -1)
		Xuat(a, vtd, vtc);
	else
		cout << "Khong co day con nao thoa!" << endl;
	return 0;
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

int ktCon(float a[], int n, int vt, int l)
{
	int flag = 1;
	for (int i = 0; i <= l - 1; i++)
		if (a[vt + i] <= 0)
			flag = 0;
	return flag;
}

void DuongDaiNhat(float a[], int n, int& vtd, int& vtc)
{
	for (int l = n; l >= 1; l--)
		for (int vt = 0; vt <= n - l; vt++)
			if (ktCon(a, n, vt, l) == 1)
			{
				vtd = vt;
				vtc = vt + l - 1;
				return;
			}
	vtd = vtc = -1;
}

void Xuat(float a[], int vtd, int vtc)
{
	for (int i = vtd; i <= vtc; i++)
		cout << setw(11) << a[i];
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