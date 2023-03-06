#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cctype>
#include <math.h>

using namespace std;

#define MAXR 500
#define MAXC 500

string GetFileLink(string);
void Nhap(string, float[][500], int&, int&);
int ktToanDuong(float[][500], int, int);

int main()
{
	int row = 0;
	int col = 0;
	float a[MAXR][MAXC];
	Nhap(GetFileLink("float"), a, row, col);
	int kq = ktToanDuong(a, row, col);
	cout << "Ket qua kiem tra la: " << kq << endl;
}

void Nhap(string filename, float a[][500], int& m, int& n)
{
	ifstream fi(filename);
	fi >> m >> n;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			fi >> a[i][j];
}

int ktToanDuong(float a[][500], int m, int n)
{
	int flag = 1;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (a[i][j] < 0)
				return flag = 0;
	return flag;
}

string GetFileLink(string dataTypeOfFile)
{

	string folderName = dataTypeOfFile;
	folderName[0] = toupper(folderName[0]);
	folderName += "MatranData";
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


