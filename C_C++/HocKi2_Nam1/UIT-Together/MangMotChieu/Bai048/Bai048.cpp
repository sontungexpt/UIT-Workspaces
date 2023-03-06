#include <iostream>
#include <iomanip>
#include <ctime>
#include <string>
#include <fstream>
#include <cctype>
using namespace std;

#define MAX 100000

void Nhap(string, float[], int&);
string GetFileName(string);
float TichDuong(float[], int);
int DemDuong(float[], int);
float TrungBinhNhan(float[], int);

int main()
{
	int n;
	float a[MAX];
	Nhap(GetFileName("float"), a, n);
	float kq = TrungBinhNhan(a, n);
	cout << "Trung binh nhan = " << kq;
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

float TichDuong(float a[], int n)
{
	float T = 01;
	for (int i = 0; i < n; i++)
		if (a[i] > 0)
			T = T * a[i];
	return T;
}

int DemDuong(float a[], int n)
{
	int dem = 0;
	for (int i = 0; i < n; i++)
		if (a[i] > 0)
			dem++;
	return dem;
}

float TrungBinhNhan(float a[], int n)
{
	float T = TichDuong(a, n);
	int dem = DemDuong(a, n);
	if (dem == 0)
		return 0;
	return pow(T, (float)1 / dem);
}

string GetFileName(string dataTypeOfFile)
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
