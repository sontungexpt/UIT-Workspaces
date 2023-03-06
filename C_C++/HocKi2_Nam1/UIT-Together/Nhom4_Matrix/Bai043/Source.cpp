#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cctype>
#include <math.h>

using namespace std;

#define MAXR 500
#define MAXC 500

//initalize function
string GetFileLink(string);
void Xuat(float[][MAXC], int, int);
void Nhap(string, float[][MAXC], int&, int&);
long double TinhTichDuongCot(float[][MAXC], int, int, int &);

int main()
{
	int k = 0;
	int l = 0;
	float a[MAXR][MAXC];
	int vtCot;
	Nhap(GetFileLink("float"), a, k, l);
	long double tich = TinhTichDuongCot(a, k, l, vtCot);
	cout << "Tich cac so duong tai cot " << vtCot <<": " << tich;
	return 0;
}

//function
string GetFileLink(string dataTypeOfFile)
{
	//lấy tên thư mục
	string folderName = dataTypeOfFile;
	folderName[0] = toupper(folderName[0]);
	folderName += "MatranData";
	//lấy đường dẫn tới file data.inp
	string fileLink = "../" + folderName + "/" + dataTypeOfFile + "matrandata";
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

void Nhap(string filename, float a[][MAXC], int& m, int& n)
{
	ifstream fi(filename);
	if (fi.fail() == true)
	{
		cout << "Khong mo duoc file";
		exit(0);
	}
	fi >> m >> n;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			fi >> a[i][j];
}

void Xuat(float a[][MAXC], int m, int n)
{
	cout << "Ma tran la:\n";
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			cout << setw(8) << a[i][j];
		cout << endl;
	}
}

long double TinhTichDuongCot(float a[][MAXC], int m, int n, int &vtCot)
{
	cout << "Nhap vi tri cot can tinh: ";
	cin >> vtCot;
	double tich = 1;
	for (int i = 0; i < m; i++)
		if (a[i][vtCot] > 0)
			tich *= a[i][vtCot];
	return tich;
}

