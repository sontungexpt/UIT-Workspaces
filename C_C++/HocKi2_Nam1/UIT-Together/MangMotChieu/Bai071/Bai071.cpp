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
int DemXuatHien(int[], int, int[], int);

int main()
{
	int nA;
	int a[MAX];
	int nB;
	int b[MAX];
	cout << "Chon file de nhap mang dau tien\n";
	Nhap(GetFileLink("int"), a, nA);
	cout << "Chon file de nhap mang thu hai\n";
	Nhap(GetFileLink("int"), b, nB);
	cout << "So lan xuat hien cua mang a trong mang b la: " << DemXuatHien(a, nA, b, nB);

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

int DemXuatHien(int aa1[], int nn1, int aa2[], int nn2)
{
	if (nn1 > nn2)
		return 0;
	int count = 0;
	for (int i = 0; i <= nn2 - nn1; i++)
	{
		int flag = 1;
		for (int j = 0; j < nn1; j++)
			if (aa1[j] != aa2[j + i])
				flag = 0;
		if (flag == 1)
			count++;
	}
	return count;
}

