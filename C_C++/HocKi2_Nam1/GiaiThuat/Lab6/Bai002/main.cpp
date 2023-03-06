#include <iostream>

using namespace std;

struct Node
{
	int data;
	struct Node* pLeft;
	struct Node* pRight;
};

typedef struct Node Node;
typedef Node* Tree;

void Read(int a[], int& n)
{
	cout << "\nNhap so luong phan tu muon nhap: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "\nNhap phan tu thu " << i << ": ";
		cin >> a[i];
	}
}

void Print(int a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << "\na[" << i << "]: " << a[i];
}

void Init(Tree& tree)
{
	tree = nullptr;
}
Node* CreateNode(int number)
{
	Node* p = new Node;
	if (p == nullptr)
		return nullptr;
	p->data = number;
	p->pLeft = nullptr;
	p->pRight = nullptr;
	return p;
}
bool IsEmpty(Tree tree)
{
	if (tree == nullptr)
		return 1;
	return 0;
}
void Insert(Tree& root, int data)
{
	if (root == nullptr)
		root = CreateNode(data);
	else
		if (root->data == data)
			return;
		else if (root->data > data)
			Insert(root->pLeft, data);
		else
			Insert(root->pRight, data);
}

void PrintNLR(Tree tree)
{
	if (tree == nullptr)
		return;
	cout << tree->data << "  ";
	PrintNLR(tree->pLeft);
	PrintNLR(tree->pRight);
}

int SearchTimes(int a[], int n, int x)
{
	int time = 0;
	for (int i = 0; i < n; i++)
	{
		time++;
		if (x == a[i])
			break;
	}
	return time;
}

int SearchTimes(Tree tree, int x)
{
	int times = 0;
	if (tree == nullptr)
		return 0;
	if (tree->data == x)
		return times;
	else if (tree->data > x)
		times = SearchTimes(tree->pLeft, x) + 1;
	else
		times = SearchTimes(tree->pRight, x) + 1;
}

int main()
{
	int arr[1000];
	Tree tree;
	Init(tree);
	int key = -1;
	int n;
	int x;
	int time1;
	int time2;
	do
	{
		cout << "\n1. Nhap mang A gom n so: ";
		cout << "\n2. Luu mang vao cay nhi phan tim kiem: ";
		cout << "\n3. In mang A";
		cout << "\n4. In ra mang hinh theo cach duyet LNR";
		cout << "\n5. So sanh thoi gian tim kiem tren mang A va cay B";

		cout << "\n0. Ket thuc chuong trinh";


		cout << "\nNhap lua chon cua ban: ";
		cin >> key;
		switch (key)
		{
		case 1:
			Read(arr, n);
			break;
		case 2:
			for (int i = 0; i < n; i++)
				Insert(tree, arr[i]);
			cout << "\nSuccess";
			break;

		case 3:
			Print(arr, n);
			break;
		case 4:
			cout << endl;
			PrintNLR(tree);
			break;
		case 5:
			cout << "\nNhap x: ";
			cin >> x;
			time1 = SearchTimes(arr, n, x);
			time2 = SearchTimes(tree, x);
			if (time1 == time2)
				cout << "\nThoi gian tim kiem bang nhau";
			else if (time1 > time2)
				cout << "\nA > B";
			else
				cout << "\nB>A";
			cout << "\nSo lan tim kiem tren mang A: " << time1;
			cout << "\nSo lan tim kiem tren cay B: " << time2;
			break;

		case 0:
			exit(0);
		default:
			cout << "Nhap sai: ";
			break;
		}
		cout << endl;
		system("pause");
		system("cls");
	} while (key != 0);

	return 0;
}