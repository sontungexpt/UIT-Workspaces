#include <iostream>
#include <iomanip>

using namespace std;

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

void Init(LIST& );
bool IsEmpty(LIST);
NODE* GetNode(int);
void AddTail(LIST& li, NODE* p);
void Swap(int&, int&);
void InterchangeSort(LIST&);
void Input(LIST &);
void Output(LIST);
int main()
{
	LIST list;
	Input(list);
	InterchangeSort(list);
	Output(list);
	return 0;
}


//function

void Init(LIST& li)
{
	li.pHead = NULL;
	li.pTail = NULL;
}
bool IsEmpty(LIST li)
{
	if(li.pHead == NULL)
		return 1;
	return 0;
}
NODE* GetNode(int value)
{
	NODE* p = new NODE;
	if (p == NULL)
		return NULL;
	p->info = value;
	p->pNext = NULL;
	return p;
}
void AddTail(LIST& li, NODE* p)
{
	if (IsEmpty(li)==true)
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
	for (NODE* p = li.pHead; p->pNext != NULL; p = p->pNext)
		for (NODE* q = p->pNext; q != NULL; q = q->pNext)
			if (p->info > q->info)
				swap(p->info, q->info);
}
void Input(LIST& li)
{
	int n;
	int x;
	cout << "Nhap so luong phan tu cho danh sach: ";
	cin >> n;
	Init(li);
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap phan tu thu " << i<< ": ";
		cin >> x;
		NODE* p = GetNode(x);
		if(p!=NULL)
			AddTail(li,p);
	}
}

void Output(LIST li)
{
	for (NODE* p = li.pHead; p != NULL; p = p->pNext)
	{
		cout << p->info << setw(5);
	}
}