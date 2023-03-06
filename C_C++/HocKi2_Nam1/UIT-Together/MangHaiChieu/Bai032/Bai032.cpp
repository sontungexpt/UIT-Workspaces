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
void Nhap(string, float[][MAXC], int&, int&);
void Xuat(float[][MAXC], int, int);

double Tong(float[][MAXC], int, int, float, float);


string GetFileLink(string);

int main()
{
	float a[MAXR][MAXC];
	int m;
	int n;
	float x, y;
	Nhap(GetFileLink("float"), a, m, n);
	Xuat(a, m, n);
	cout << "nhap x: ";
	cin >> x;
	cout << "nhap y: ";
	cin >> y;
	cout << "tong cac so nam trong doan " << x << " " << y << " la: " << Tong(a, m, n, x, y);
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
	fi >> m >> n;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			fi >> a[i][j];
}

void Xuat(float a[][MAXC], int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			cout << setw(8) << setprecision(3) << a[i][j];
		cout << endl;
	}
}

double Tong(float a[][MAXC], int m, int n, float x, float y)
{
	double s = 0;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (x < a[i][j] && a[i][j] < y)
				s += a[i][j];
	return s;
}