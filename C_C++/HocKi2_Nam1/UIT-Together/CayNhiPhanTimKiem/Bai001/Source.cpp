#include <iostream>
#include <string>
#include <cctype>
#include <fstream>
#include <iomanip>

using namespace std;
template <typename Type>
struct node
{
	Type info;
	struct node* pLeft;
	struct node* pRight;
};

using NODE = node<int>;
using FLOATNODE = node <float>;
typedef NODE* TREE;
typedef FLOATNODE* FLOATTREE;

template <typename Type>
struct listnode
{
	Type info;
	struct listnode* pNext;
};
using INTLISTNODE = listnode<int>;
using FLOATLISTNODE = listnode <float>;

struct BST_NODE 
{
	int Key;
	int times;
	struct 
};

struct list
{
	INTLISTNODE* pHead;
	INTLISTNODE* pTail;
};
typedef struct list LIST;


void Init(TREE&);
void Init(FLOATTREE&);
bool IsEmpty(TREE);
bool IsEmpty(FLOATTREE );
NODE* GetNODE(int);
FLOATNODE* GetNODE(float);
int InsertNODE(TREE&, int);
int InsertNODE(FLOATTREE&, float);
void Input(string, TREE&);
void Input(string, FLOATTREE&);
string GetFileLink(string);
string GetFileLink(string, int);
void Print(TREE);
int Sum(TREE);
int CountNODE(TREE);
void Print(string fileInName, TREE, string);
void Print(string fileInName, FLOATTREE, string);
void PrintNLR(TREE, string);
void PrintNLR(FLOATTREE, string);
void PrintLNR(TREE, string);
void PrintLRN(TREE, string);
void PrintLNR(FLOATTREE, string);
void PrintLRN(FLOATTREE, string);
int Height(TREE);
void RemoveAll(TREE&);
int CountOddNODE(TREE);
float Average(TREE);
float PositiveAverage(TREE);
int CountPositiveNODE(TREE);
int PositiveSum(TREE);
int CountNegativeNODE(TREE);
int NegativeSum(TREE);
float NegativeAverage(TREE);
float CalcR(TREE);
NODE* GetMax(TREE);
NODE* GetMin(TREE);
int CountOneChild(TREE);
void Init(LIST&);
bool IsEmpty(LIST);
INTLISTNODE* GetNode(int);
void AddTail(LIST&, INTLISTNODE*);
void InputRNL(LIST&, TREE);
void Print(LIST);
void BuildList(LIST&, TREE);

int main()
{
	TREE int_tree;
	FLOATTREE float_tree;
	LIST list;
	for (int i = 1; i <= 13; i++)
	{
		cout << "\nFile" << i;
		Input(GetFileLink("int", i), int_tree);
		cout << "\nTong la: " << Sum(int_tree);
		cout << "\nChieu cao la: " << Height(int_tree);
		cout << "\nSo luong node la: " << CountNODE(int_tree);
		cout << "\nSo luong node le la: " << CountOddNODE(int_tree);
		cout << "\nTrung binh cong cua cac node la: " << Average(int_tree);
		cout << "\nTrung binh cong cua cac node duong la: " << PositiveAverage(int_tree);
		cout << "\nTrung binh cong cua cac node am la: " << NegativeAverage(int_tree);
		cout << "\nR = a/b = " << CalcR(int_tree);
		cout << "\nGia tri cua node lon nhat la: " << GetMax(int_tree)->info;
		cout << "\nGia tri cua node nho nhat la: " << GetMin(int_tree)->info;
		cout << "\nTong so nut co mot nhanh con la: " << CountOneChild(int_tree);
		cout << "\nDanh sach lien ket don giam dan la: ";
		BuildList(list, int_tree);
		Print(list);
		Print(GetFileLink("int", i), int_tree, "NLR");
		RemoveAll(int_tree);
		//Float data
		Input(GetFileLink("float", i), float_tree);
		Print(GetFileLink("float", i), float_tree, "LNR");
		Print(GetFileLink("float", i), float_tree, "NLR");
		Print(GetFileLink("float", i), float_tree, "LRN");
		

		cout << endl;
	}
	return 1;
}


string GetFileLink(string dataTypeOfFile)
{
	string folderName = dataTypeOfFile;
	folderName[0] = toupper(folderName[0]);
	folderName += "Data";
	string fileLink = "../" + folderName + "/Input/" + dataTypeOfFile + "data";
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

string GetFileLink(string dataTypeOfFile, int fileIndex)
{
	string folderName = dataTypeOfFile;
	folderName[0] = toupper(folderName[0]);
	folderName += "Data";
	string fileLink = "../" + folderName + "/Input/" + dataTypeOfFile + "data";
	if (fileIndex < 10)
		fileLink += '0';
	fileLink += to_string(fileIndex);
	string fileLinkInp = fileLink;
	fileLinkInp += ".inp";
	return fileLinkInp;
}

void Input(string filename, TREE& t)
{
	ifstream fi(filename);
	if (fi.fail() == true)
	{
		cout << "Khong mo duoc file";
		exit(0);
	}
	int n;
	int x;
	fi >> n;
	Init(t);
	for (int i = 0; i < n; i++)
	{
		fi >> x;
		InsertNODE(t, x);
	}
}

void Input(string filename, FLOATTREE& t)
{
	ifstream fi(filename);
	if (fi.fail() == true)
	{
		cout << "Khong mo duoc file";
		exit(0);
	}
	int n;
	float x;
	fi >> n;
	Init(t);
	for (int i = 0; i < n; i++)
	{
		fi >> x;
		InsertNODE(t, x);
	}
}

void Print(TREE t)
{
	if (t == nullptr)
	{
		cout << "Khong co cay";
		return;
	}
	Print(t->pLeft);
	cout << t->info;
	Print(t->pRight);
}

void Print(string fileInName, TREE t, string method)
{
	string fileOutName = fileInName;
	string inputFolderName = "Input";
	int indexFolderName = fileOutName.find(inputFolderName);
	fileOutName.replace(indexFolderName, inputFolderName.length(), "Output");
	string extension = "inp";
	int indexExtension = fileOutName.find(extension);
	fileOutName.replace(indexExtension, extension.length(), "out");
	fstream fileOut;
	fileOut.open(fileOutName, ios::trunc | ios::out);
	if (method == "NLR")
		PrintNLR(t, fileOutName);
	else if (method == "LNR")
		PrintLNR(t, fileOutName);
	else if (method == "LRN")
		PrintLRN(t, fileOutName);
	cout << "\nXuat file so nguyen theo kieu " << method << " thanh cong";
}

void Print(string fileInName, FLOATTREE t, string method)
{
	string fileOutName = fileInName;
	string inputFolderName = "Input";
	int indexFolderName = fileOutName.find(inputFolderName);
	fileOutName.replace(indexFolderName, inputFolderName.length(), "Output");
	string extension = "inp";
	int indexExtension = fileOutName.find(extension);
	fileOutName.replace(indexExtension, extension.length(), "out");
	fstream fileOut;
	fileOut.open(fileOutName, ios::trunc | ios::out);
	if (method == "NLR")
		PrintNLR(t, fileOutName);
	else if (method == "LNR")
		PrintLNR(t, fileOutName);
	else if (method == "LRN")
		PrintLRN(t, fileOutName);
	cout << "\nXuat file so thuc theo kieu  "<<method<<" thanh cong";
}

void PrintNLR(TREE t, string filePath)
{
	//ofstream fileOut(filePath);
	fstream fileOut;
	fileOut.open(filePath, ios::app);
	if (fileOut.fail() == true)
	{
		cout << "Khong mo duoc file";
		exit(0);
	}
	if (t == nullptr)
		return;
	fileOut << setw(6) << t->info;
	PrintNLR(t->pLeft, filePath);
	PrintNLR(t->pRight, filePath);
}

void PrintNLR(FLOATTREE t, string filePath)
{
	//ofstream fileOut(filePath);
	fstream fileOut;
	fileOut.open(filePath, ios::app);
	if (fileOut.fail() == true)
	{
		cout << "Khong mo duoc file";
		exit(0);
	}
	if (t == nullptr)
		return;
	fileOut << setw(6) << t->info;
	PrintNLR(t->pLeft, filePath);
	PrintNLR(t->pRight, filePath);
}

void PrintLNR(TREE t, string filePath)
{
	fstream fileOut;
	fileOut.open(filePath, ios::app);
	if (fileOut.fail() == true)
	{
		cout << "Khong mo duoc file";
		exit(0);
	}
	if (t == nullptr)
		return;

	PrintLNR(t->pLeft, filePath);
	fileOut << setw(6) << t->info;
	PrintLNR(t->pRight, filePath);
}

void PrintLRN(TREE t, string filePath)
{
	fstream fileOut;
	fileOut.open(filePath, ios::app);
	if (fileOut.fail() == true)
	{
		cout << "Khong mo duoc file";
		exit(0);
	}
	if (t == nullptr)
		return;

	PrintLNR(t->pLeft, filePath);
	PrintLNR(t->pRight, filePath);
	fileOut << setw(6) << t->info;
}

void PrintLNR(FLOATTREE t, string filePath)
{
	fstream fileOut;
	fileOut.open(filePath, ios::app);
	if (fileOut.fail() == true)
	{
		cout << "Khong mo duoc file";
		exit(0);
	}
	if (t == nullptr)
		return;

	PrintLNR(t->pLeft, filePath);
	fileOut << setw(6) << t->info;
	PrintLNR(t->pRight, filePath);
}

void PrintLRN(FLOATTREE t, string filePath)
{
	fstream fileOut;
	fileOut.open(filePath, ios::app);
	if (fileOut.fail() == true)
	{
		cout << "Khong mo duoc file";
		exit(0);
	}
	if (t == nullptr)
		return;

	PrintLNR(t->pLeft, filePath);
	PrintLNR(t->pRight, filePath);
	fileOut << setw(6) << t->info;
}

void Init(TREE& t)
{
	t = nullptr;
}

void Init(FLOATTREE& t)
{
	t = nullptr;
}

bool IsEmpty(TREE t)
{
	if (t == nullptr)
		return 1;
	return 0;
}

bool IsEmpty(FLOATTREE t)
{
	if (t == nullptr)
		return 1;
	return 0;
}

NODE* GetNODE(int x)
{
	NODE* p = new NODE;
	if (p == nullptr)
		return nullptr;
	p->info = x;
	p->pLeft = nullptr;
	p->pRight = nullptr;
	return p;
}

FLOATNODE* GetNODE(float x)
{
	FLOATNODE* p = new FLOATNODE;
	if (p == nullptr)
		return nullptr;
	p->info = x;
	p->pLeft = nullptr;
	p->pRight = nullptr;
	return p;
}

int InsertNODE(TREE& t, int x)
{
	if (t != nullptr)
	{
		if (x > t->info)
			return InsertNODE(t->pRight, x);
		else if (x < t->info)
			return InsertNODE(t->pLeft, x);
		return 0;
	}
	t = GetNODE(x);
	if (t != nullptr)
		return -1;
	return 1;
}

int InsertNODE(FLOATTREE& t, float x)
{
	if (t != nullptr)
	{
		if (x > t->info)
			return InsertNODE(t->pRight, x);
		else if (x < t->info)
			return InsertNODE(t->pLeft, x);
		return 0;
	}
	t = GetNODE(x);
	if (t != nullptr)
		return -1;
	return 1;
}

int Sum(TREE t)
{
	if (t == nullptr)
		return 0;
	int a = Sum(t->pLeft);
	int b = Sum(t->pRight);
	return a + b + t->info;
}

int CountNODE(TREE t)
{
	if (t == nullptr)
		return 0;
	int a = CountNODE(t->pLeft);
	int b = CountNODE(t->pRight);
	return a + b + 1;
}

int Height(TREE t)
{
	if (t == nullptr)
		return 0;
	int a = Height(t->pLeft);
	int b = Height(t->pRight);
	if (a > b)
		return a + 1;
	else
		return b + 1;
}

void RemoveAll(TREE& t)
{
	if (t == nullptr)
		return;
	RemoveAll(t->pLeft);
	RemoveAll(t->pRight);
	delete t;
	t = nullptr;
}

int CountOddNODE(TREE t)
{
	if (t == nullptr)
		return 0;
	int a = CountOddNODE(t->pLeft);
	int b = CountOddNODE(t->pRight);
	if (t->info % 2 != 0)
		return a + b + 1;
	return a + b;
}

float Average(TREE t)
{
	if (t == nullptr)
		return 0;
	int sum = Sum(t);
	int count = CountNODE(t);
	if (count == 0)
		return 0;
	return (float)sum / count;
}

int CountPositiveNODE(TREE t)
{
	if (t == nullptr)
		return 0;
	int a = CountPositiveNODE(t->pLeft);
	int b = CountPositiveNODE(t->pRight);
	if (t->info > 0)
		return a + b + 1;
	return a + b;
}

int PositiveSum(TREE t)
{
	if (t == nullptr)
		return 0;
	int a = PositiveSum(t->pLeft);
	int b = PositiveSum(t->pRight);
	if (t->info > 0)
		return a + b + t->info;
	return a + b;
}

float PositiveAverage(TREE t)
{
	int s = PositiveSum(t);
	int count = CountPositiveNODE(t);
	if (count == 0)
		return 0;
	return (float)s / count;
}

int CountNegativeNODE(TREE t)
{
	if (t == nullptr)
		return 0;
	int a = CountNegativeNODE(t->pLeft);
	int b = CountNegativeNODE(t->pRight);
	if (t->info < 0)
		return a + b + 1;
	return a + b;
}

int NegativeSum(TREE t)
{
	if (t == nullptr)
		return 0;
	int a = NegativeSum(t->pLeft);
	int b = NegativeSum(t->pRight);
	if (t->info < 0)
		return a + b + t->info;
	return a + b;
}

float NegativeAverage(TREE t)
{
	int s = NegativeSum(t);
	int count = CountNegativeNODE(t);
	if (count == 0)
		return 0;
	return (float)s / count;
}

float CalcR(TREE t)
{
	int a = PositiveSum(t);
	int b = NegativeSum(t);
	if (b == 0)
		return 0;
	return  a / b;
}

NODE* GetMax(TREE t)
{
	if (t == nullptr)
		return nullptr;
	NODE* gaurds = t;
	while (gaurds->pLeft != nullptr)
		gaurds = gaurds->pLeft;
	return gaurds;
}

NODE* GetMin(TREE t)
{
	if (t == nullptr)
		return nullptr;
	NODE* gaurds = t;
	while (gaurds->pRight != nullptr)
		gaurds = gaurds->pRight;
	return gaurds;
}

int CountOneChild(TREE t)
{
	if (t == nullptr)
		return 0;
	else if ((t->pLeft && !t->pRight) || (!t->pLeft && t->pRight))
		return 1 + CountOneChild(t->pLeft) + CountOneChild(t->pRight);
	return CountOneChild(t->pLeft) + CountOneChild(t->pRight);
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

INTLISTNODE* GetNode(int value)
{
	INTLISTNODE* p = new INTLISTNODE;
	if (p == nullptr)
		return nullptr;
	p->info = value;
	p->pNext = nullptr;
	return p;
}

void AddTail(LIST& li, INTLISTNODE* p)
{
	if (IsEmpty(li))
		li.pHead = li.pTail = p;
	else
	{
		li.pTail->pNext = p;
		li.pTail = p;
	}
}

void InputRNL(LIST& li, TREE t)
{
	if (t == nullptr)
		return;
	InputRNL(li, t->pRight);
	INTLISTNODE* p = GetNode(t->info);
	if (p != nullptr)
		AddTail(li, p);
	InputRNL(li, t->pLeft);
}

void Print(LIST li)
{
	for (INTLISTNODE* p = li.pHead; p != nullptr; p = p->pNext)
		cout << p->info << setw(5);
}

void BuildList(LIST& li, TREE t)
{
	Init(li);
	InputRNL(li, t);
}