#include <iostream>
#include <string>
#include <string.h>

using namespace std;

struct ProductInfo
{
	string name;
	int price;
	int remainingAmount;
};
typedef struct ProductInfo ProductInfo;

struct Node
{
	ProductInfo info;
	struct Node* pNext;
};
typedef struct Node Node;

struct List
{
	Node* pHead;
	Node* pTail;
};

void Init(List&);
bool IsEmpty(List);
Node* CreateNode(ProductInfo);
void AddTail(List&, Node*);
void AddHead(List&, Node*);
void Input(List&);
void ListInRangeOfValue(List);
void PrintInfo(ProductInfo);

int main()
{
	List list;
	Input(list);
	ListInRangeOfValue(list);
	return 0;
}

void Init(List& li)
{
	li.pHead = nullptr;
	li.pTail = nullptr;
}
bool IsEmpty(List li)
{
	if (li.pHead == nullptr)
		return 1;
	return 0;
}

Node* CreateNode(ProductInfo info)
{
	Node* newEle = new Node;
	if (newEle == nullptr)
		return nullptr;
	newEle->info.name = info.name;
	newEle->info.price = info.price;
	newEle->info.remainingAmount = info.remainingAmount;
	newEle->pNext = nullptr;
	return newEle;
}

void AddTail(List& li, Node* newEle)
{
	if (IsEmpty(li))
		li.pHead = li.pTail = newEle;
	else
	{
		li.pTail->pNext = newEle;
		li.pTail = newEle;
	}
}

void AddHead(List& li, Node* newEle)
{
	if (IsEmpty(li))
		li.pHead = li.pTail = newEle;
	else
	{
		newEle->pNext = li.pHead;
		li.pHead = newEle;
	}
}

void Input(List& li)
{
	Init(li);
	ProductInfo info;
	for (int i = 0; i < 3; i++)
	{
		cout << "Nhap ten mat hang: ";
		getline(cin, info.name,'\n');
		cout << "Nhap gia mat hang: ";
		cin >> info.price;
		cout << "Nhap so luong con lai trong kho: ";
		cin >> info.remainingAmount;
		Node* newEle = CreateNode(info);
		if(newEle != nullptr)
			AddTail(li, newEle);
		cin.ignore();
	}
}

void ListInRangeOfValue(List li)
{
	cout << "Nhap x: ";
	int x;
	cin >> x;
	cout << "Nhap y: ";
	int y;
	cin >> y;
	for (Node* temp = li.pHead; temp != nullptr; temp = temp->pNext)
		if (temp->info.remainingAmount > x && temp->info.remainingAmount < y)
		{
			PrintInfo(temp->info);
			cout << endl;
		}
}

void PrintInfo(ProductInfo info)
{
	cout << "Ten san pham la: ";
	cout << info.name << endl;
	cout << "Gia san pham la: ";
	cout << info.price << endl;
	cout << "So luong con lai cua san pham la: ";
	cout << info.remainingAmount<<endl;
}