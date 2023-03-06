#include <iostream>
#include <iomanip>
#include <ctime>int
#include <string>
#include <fstream>
#include <cctype>

using namespace std;

#define MAX 100000

void Nhap(string, int[], int&);
int TongCon(int[], int, int, int);
void TimCon(int[], int, int, int&, int&);
void Xuat(int[], int, int);
string GetFileLink(string);

int main()
{
	int M;
	cout << "Nhap vao M: ";
	cin >> M;
	int n;
	int a[MAX];
	Nhap(GetFileLink("int"), a, n);
	int vtd = 0;
	int vtc = n - 1;
	TimCon(a, n, M, vtd, vtc);
	if (vtd != -1 || vtc != -1)
		Xuat(a, vtd, vtc);
	else
		cout << "Khong co day con nao thoa!" << endl;
	return 0;
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

int TongCon(int a[], int n, int vt, int l)
{
	int s = 0;
	for (int i = 0; i <= l - 1; i++)
		s += a[vt + i];
	return s;
}

void TimCon(int a[], int n, int M, int& vtd, int& vtc)
{
	for (int l = 1; l <= n; l++)
		for (int vt = 0; vt <= n - l; vt++)
			if (TongCon(a, n, vt, l) == M)
			{
				vtd = vt;
				vtc = vt + l - 1;
				return;
			}
	vtd = vtc = -1;
}

void Xuat(int a[], int vtd, int vtc)
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