#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <time.h>
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
void AutoInput(LIST&);
void Output(LIST);
int CreateRandomValue(int,int);


int main()
{
	LIST list;
	AutoInput(list);
	InterchangeSort(list);
	Output(list);
	return 0;
}


//function

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
int CreateRandomValue(int leftLimit,int rightLimit)
{
	int result = rand() % (rightLimit - leftLimit + 1) + leftLimit;
	return result;
}
void InterchangeSort(LIST& li)
{
	for (NODE* p = li.pHead; p->pNext != NULL; p = p->pNext)
		for (NODE* q = p->pNext; q != NULL; q = q->pNext)
			if (p->info > q->info)
				swap(p->info, q->info);
}
void AutoInput(LIST& li)
{
	srand(time(NULL));
	int n;
	int x;
	cout << "Nhap so luong phan tu cho danh sach: ";
	cin >> n;
	Init(li);
	for (int i = 0; i < n; i++)
	{	
		x = CreateRandomValue(MAX,MIN);
		NODE* p = GetNode(x);
		if (p != NULL)
			AddTail(li, p);
	}
}

void Output(LIST li)
{
	for (NODE* p = li.pHead; p != NULL; p = p->pNext)
	{
		cout << p->info << setw(5);
	}
}
