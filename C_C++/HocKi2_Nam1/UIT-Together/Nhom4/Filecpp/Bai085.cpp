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
int ChanCuoi(int[], int);

int main()
{
	int n;
	int a[MAX];
	Nhap(GetFileLink("int"), a, n);
	if (ChanCuoi(a, n) == -1)
		cout << "Khong co so chan nao trong mang";
	else
		cout << "So chan cuoi cung trong mang cac so nguyen : " << ChanCuoi(a, n);

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

int ChanCuoi(int a[], int nn)
{
	for (int i = nn - 1; i >= 0; i--)
		if (a[i] % 2 == 0)
			return a[i];
	return -1;
}


