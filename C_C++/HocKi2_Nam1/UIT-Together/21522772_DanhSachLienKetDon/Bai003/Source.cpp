#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <time.h>
#include <string>
#include <cctype>
#include <fstream>

using namespace std;

#define MAX 300
#define MIN 0

struct node
{
	int info;
	struct node* pNext;
};
typedef struct node NODE;

struct list
{
	NODE* pHead;
	NODE* pTail;
};
typedef struct list LIST;

//initalize function

void Init(LIST&);
bool IsEmpty(LIST);
NODE* GetNode(int);
void AddTail(LIST&, NODE*);
void Swap(int&, int&);
void InterchangeSort(LIST&);
void InputFromFile(string, LIST&);
void PrintToFile(string, LIST);
void Output(LIST);
string GetFileLink(string);


int main()
{
	LIST list;
	string fileName = GetFileLink("int");
	InputFromFile(fileName, list);
	InterchangeSort(list);
	PrintToFile(fileName, list);
	Output(list);
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

void Init(LIST& li)
{
	li.pHead = nullptr;
	li.pTail = nullptr;
}

bool IsEmpty(LIST li)
{
	if (li.pHead == nullptr)
		return 1;
	return 0;
}

NODE* GetNode(int value)
{
	NODE* p = new NODE;
	if (p == nullptr)
		return nullptr;
	p->info = value;
	p->pNext = nullptr;
	return p;
}

void AddTail(LIST& li, NODE* p)
{
	if (IsEmpty(li) == true)
		li.pHead = li.pTail = p;
	else
	{
		li.pTail->pNext = p;
		li.pTail = p;
	}
}
void Swap(int& value1, int& value2)
{
	int temp = value1;
	value1 = value2;
	value2 = temp;
}

void InterchangeSort(LIST& li)
{
	for (NODE* p = li.pHead; p->pNext != nullptr; p = p->pNext)
		for (NODE* q = p->pNext; q != nullptr; q = q->pNext)
			if (p->info > q->info)
				swap(p->info, q->info);
}
void InputFromFile(string filename, LIST& li)
{
	ifstream fi(filename);
	if (fi.fail() == true)
	{
		cout << "Khong mo duoc file";
		exit(0);
	}
	Init(li);
	int x;
	int n;
	fi >> n;
	for (int i = 0; i < n; i++)
	{
		fi >> x;
		NODE* newEle = GetNode(x);
		if (newEle != nullptr)
			AddTail(li, newEle);
	}
}

void Output(LIST li)
{
	for (NODE* p = li.pHead; p != nullptr; p = p->pNext)
		cout << p->info << setw(5);
}

void PrintToFile(string fileInName, LIST li)
{
	string fileOutName = fileInName;
	fstream fileOut;
	if (fileOut.fail() == true)
	{
		cout << "Khong mo duoc file";
		exit(0);
	}
	int index = fileOutName.find("inp");
	fileOutName.replace(index, 3, "out");
	fileOut.open(fileOutName, ios::out);
	for (NODE* p = li.pHead; p != nullptr; p = p->pNext)
		fileOut << setw(8)<<p->info;

}