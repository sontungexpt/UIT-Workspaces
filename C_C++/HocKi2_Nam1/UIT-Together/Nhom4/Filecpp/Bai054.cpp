#include <iostream>
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
bool KtSoDoiXung(int);
int DemDoiXung(int[], int);

int main()
{
	int n;
	int a[MAX];
	Nhap(GetFileLink("int"), a, n);
	cout << "So luong so doi xung co trong mang la: " << DemDoiXung(a, n);
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

bool KtSoDoiXung(int n)
{
	int temp = abs(n);
	int soDaoNguoc = 0;
	for (; temp > 0;)
	{
		int dvi = temp % 10;
		soDaoNguoc = soDaoNguoc * 10 + dvi;
		temp /= 10;
	}
	if (soDaoNguoc == abs(n))
		return true;
	return false;
}

int DemDoiXung(int a[], int n)
{
	int count = 0;
	for (int i = 0; i < n; i++)
		if (KtSoDoiXung(a[i]) == true)
			count++;
	return count;
}