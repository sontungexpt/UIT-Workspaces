﻿#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cctype>
#include <math.h>

using namespace std;

#define MAX 100000

//initalize function
string GetFileLink(string);
void Nhap(string, int[], int&);
int TongLeDau(int[], int);
int ChuSoDau(int);

int main()
{
	int n;
	int a[MAX];
	Nhap(GetFileLink("int"), a, n);
	cout << "Tong cac so co chu so dau tien la so le la: " << TongLeDau(a, n);
	return 0;
}

//function
string GetFileLink(string dataTypeOfFile)
{
	//lấy tên thư mục
	string folderName = dataTypeOfFile;
	folderName[0] = toupper(folderName[0]);
	folderName += "Data";
	//lấy đường dẫn tới file data.inp
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

int ChuSoDau(int n)
{
	int dt = abs(n);
	for (; dt >= 10;)
		dt /= 10;
	return dt;
}

int TongLeDau(int a[], int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
		if (ChuSoDau(a[i]) % 2 != 0)
			sum += a[i];
	return sum;
}
