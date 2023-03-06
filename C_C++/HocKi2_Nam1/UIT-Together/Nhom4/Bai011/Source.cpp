#include <iostream>
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
void LietKe(int[], int);
bool KtDang3m(int);

int main()
{
	int n;
	int a[MAX];
	Nhap(GetFileLink("int"), a, n);
	LietKe(a, n);
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

void LietKe(int a[], int n)
{
	cout << "\n Cac so co dang 3^m la: ";
	for (int i = 0; i < n; i++)
		if (KtDang3m(a[i]) == true)
			cout << a[i] << setw(11);
}

bool KtDang3m(int n)
{
	if (n < 1)
		return 0;
	int temp = n;
	bool flag = true;
	for (;temp > 1;)
	{
		int du = temp % 3;
		if (du != 0)
			flag = false;
		temp /= 3;
	}
	return flag;
}
