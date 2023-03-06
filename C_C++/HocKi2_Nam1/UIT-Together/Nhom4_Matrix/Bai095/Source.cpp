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
void Xuat(int[][MAXC], int, int);
void Nhap(string, int[][MAXC], int&, int&);
int DemSoChuSo(int);
int DemSoChuSoNhieuNhat(int[][MAXC], int, int);
void LietKe(int[][MAXC], int, int);


int main()
{
	int k = 0;
	int l = 0;
	int a[MAXR][MAXC];
	int vtCot = 0;
	Nhap(GetFileLink("int"), a, k, l);
	LietKe(a, k, l);
	return 0;
}

//function
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

void Nhap(string filename, int a[][MAXC], int& m, int& n)
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

void Xuat(int a[][MAXC], int m, int n)
{
	cout << "Ma tran la:\n";
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			cout << setw(8) << a[i][j];
		cout << endl;
	}
}

int DemSoChuSo(int n)
{
	int count = 0;
	int temp = abs(n);
	for (; temp > 0;)
	{
		count++;
		temp /= 10;
	}
	return count;
}

int DemSoChuSoNhieuNhat(int a[][MAXC], int m, int n)
{
	int maxCount = 0;
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		count = 0;
		for (int j = 0; j < m; j++)
			count += DemSoChuSo(a[j][i]);
		if (count > maxCount)
			maxCount = count;
	}
	return maxCount;
}

void LietKe(int a[][MAXC], int m, int n)
{

	int maxCount = DemSoChuSoNhieuNhat(a, m, n);
	cout << "So chu so nhieu nhat tren cot la: " << maxCount << endl;
	cout << "Cac cot co so chu so nhieu nhat la\n";
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		count = 0;
		for (int j = 0; j < m; j++)
			count += DemSoChuSo(a[j][i]);
		if (maxCount == count)
		{
			cout << "Cot " << i << ": ";
			for (int k = 0; k < m; k++)
				cout << setw(8) << a[k][i];
			cout << endl;
		}
	}

}